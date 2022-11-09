#include "WarpCliController.h"
#include "Common.h"
#include "AppModel.h"
#include "SettingsModel.h"
#include <QStringList>
#include <QByteArray>

#define PROCESSING_DUMMY_TIME 5

WarpCliController::WarpCliController()
{
    LOG;
}

void WarpCliController::printResult(QString prefix, QString data)
{
    data = data.trimmed();
    if (!data.isEmpty())
    {
        qDebug().noquote() << prefix << data;
    }
}

WarpCliController::~WarpCliController()
{
    LOG;
}

void WarpCliController::initSystemSettings()
{
    LOG;
    QProcess process;
    QString _cmd;
    QString _stdout;

    // check service enabled
    _cmd = "systemctl is-enabled warp-svc.service";
    process.startCommand(_cmd, QProcess::ReadOnly);
    if (!process.waitForFinished(1000))
    {
        LOG << "FAIL TO CHECK SERVICE ENABLED... ABORT!";
        abort();
    }
    _stdout = QString(process.readAllStandardOutput()).trimmed();
    SettingsModel::instance().setWarpSvcEnabled(QString("enabled") == _stdout);
    LOG << _cmd << "---->" << _stdout;

    // check service active
    _cmd = "systemctl is-active warp-svc.service";
    process.startCommand(_cmd, QProcess::ReadOnly);
    if (!process.waitForFinished(1000))
    {
        LOG << "FAIL TO CHECK SERVICE ACTIVE... ABORT!";
        abort();
    }
    _stdout = QString(process.readAllStandardOutput()).trimmed();
    SettingsModel::instance().setWarpSvcActivated(QString("active") == _stdout);
    LOG << _cmd << "---->" << _stdout;
    return;
}

void WarpCliController::warpConnect()
{
    LOG;
    AppModel::instance().setProcessingRequest(true);
#ifdef WARP_DEBUG
    QString command = "echo \"warp-cli connect\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "warp-cli connect";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTempWarpConnected(false);
    }
    else
    {
        SettingsModel::instance().setWarpConnected(true);
        LOG << "Success";
    }
    AppModel::instance().setProcessingRequest(false);
    return;
}

void WarpCliController::warpDisconnect()
{
    LOG;
    AppModel::instance().setProcessingRequest(true);
#ifdef WARP_DEBUG
    QString command = "echo \"warp-cli disconnect\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "warp-cli disconnect";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTempWarpConnected(true);
    }
    else
    {
        SettingsModel::instance().setWarpConnected(false);
        LOG << "Success";
    }
    AppModel::instance().setProcessingRequest(false);
    return;
}

void WarpCliController::activeWarpService()
{
    LOG;
    AppModel::instance().setProcessingRequest(true);
#ifdef WARP_DEBUG
    QString command = "echo \"systemctl start warp-svc.service\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "systemctl start warp-svc.service";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTempWarpSvcActivated(false);
    }
    else
    {
        SettingsModel::instance().setWarpSvcActivated(true);
        LOG << "Success";
    }
    AppModel::instance().setProcessingRequest(false);
    return;
}

void WarpCliController::inactiveWarpService()
{
    LOG;
    AppModel::instance().setProcessingRequest(true);
#ifdef WARP_DEBUG
    QString command = "echo \"systemctl stop warp-svc.service\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "systemctl stop warp-svc.service";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        AppModel::instance().setTempWarpSvcActivated(true);
    }
    else
    {
        SettingsModel::instance().setWarpSvcActivated(false);
        LOG << "Success";
    }
    AppModel::instance().setProcessingRequest(false);
    return;
}

void WarpCliController::enableWarpService()
{
    LOG;
    AppModel::instance().setProcessingRequest(true);
#ifdef WARP_DEBUG
    QString command = "echo \"systemctl enable warp-svc.service\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "systemctl enable warp-svc.service";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        AppModel::instance().setTempWarpSvcEnabled(false);
    }
    else
    {
        SettingsModel::instance().setWarpSvcEnabled(true);
        LOG << "Success";
    }
    AppModel::instance().setProcessingRequest(false);
    return;
}

void WarpCliController::disableWarpService()
{
    LOG;
    AppModel::instance().setProcessingRequest(true);
#ifdef WARP_DEBUG
    QString command = "echo \"systemctl disable warp-svc.service\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "systemctl disable warp-svc.service";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        AppModel::instance().setTempWarpSvcEnabled(true);
    }
    else
    {
        SettingsModel::instance().setWarpSvcEnabled(false);
        LOG << "Success";
    }
    AppModel::instance().setProcessingRequest(false);
    return;
}
