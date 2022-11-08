#include "WarpCliController.h"
#include "Common.h"
#include "AppModel.h"
#include "SettingsModel.h"
#include <QStringList>
#include <QByteArray>

#define PROCESSING_DUMMY_TIME 1

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
    SettingsModel::instance().setWarpServiceEnabled(QString("enabled") == _stdout);
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
    SettingsModel::instance().setWarpServiceStarted(QString("active") == _stdout);
    LOG << _cmd << "---->" << _stdout;
    return;
}

void WarpCliController::enableWarp()
{
    LOG;
    AppModel::instance().setWarpEnabling(true);
#ifdef WARP_DEBUG
    QString command = "echo \"warp-cli connect\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "/usr/bin/bash -c \"warp-cli connect\"";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTmpWarpEnabled(false);
    }
    else
    {
        SettingsModel::instance().setWarpEnabled(true);
        LOG << "Success";
    }
    AppModel::instance().setWarpEnabling(false);
    return;
}

void WarpCliController::disableWarp()
{
    LOG;
    AppModel::instance().setWarpEnabling(true);
#ifdef WARP_DEBUG
    QString command = "echo \"warp-cli disconnect\"";
    QThread::sleep(PROCESSING_DUMMY_TIME);
#else
    QString command = "/usr/bin/bash -c \"warp-cli disconnect\"";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTmpWarpEnabled(true);
    }
    else
    {
        SettingsModel::instance().setWarpEnabled(false);
        LOG << "Success";
    }
    AppModel::instance().setWarpEnabling(false);
    return;
}

void WarpCliController::startWarpService()
{
    LOG;
    AppModel::instance().setWarpSvcStarting(true);
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
        AppModel::instance().setTmpWarpSvcStarted(false);
    }
    else
    {
        SettingsModel::instance().setWarpServiceStarted(true);
        LOG << "Success";
    }
    AppModel::instance().setWarpSvcStarting(false);
    return;
}

void WarpCliController::stopWarpService()
{
    LOG;
    AppModel::instance().setWarpSvcStarting(true);
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
        AppModel::instance().setTmpWarpSvcStarted(true);
    }
    else
    {
        SettingsModel::instance().setWarpServiceStarted(false);
        LOG << "Success";
    }
    AppModel::instance().setWarpSvcStarting(false);
    return;
}

void WarpCliController::enableWarpService()
{
    LOG;
    AppModel::instance().setWarpSvcEnabling(true);
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
        AppModel::instance().setTmpWarpSvcEnabled(false);
    }
    else
    {
        SettingsModel::instance().setWarpServiceEnabled(true);
        LOG << "Success";
    }
    AppModel::instance().setWarpSvcEnabling(false);
    return;
}

void WarpCliController::disableWarpService()
{
    LOG;
    AppModel::instance().setWarpSvcEnabling(true);
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
        AppModel::instance().setTmpWarpSvcEnabled(true);
    }
    else
    {
        SettingsModel::instance().setWarpServiceEnabled(false);
        LOG << "Success";
    }
    AppModel::instance().setWarpSvcEnabling(false);
    return;
}
