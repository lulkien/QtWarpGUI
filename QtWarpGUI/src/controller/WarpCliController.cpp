#include "WarpCliController.h"
#include "Common.h"
#include "AppModel.h"
#include <QStringList>
#include <QByteArray>

#define PROCESSING_DUMMY_TIME 1

WarpCliController::WarpCliController()
    : m_currentWorkID   { DoNothing }
{
    LOG;
}

void WarpCliController::initConnections()
{
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
    printResult("StrErr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTmpWarpEnabled(false);
    }
    else
    {
        AppModel::instance().setWarpEnabled(true);
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
    printResult("StrErr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTmpWarpEnabled(true);
    }
    else
    {
        AppModel::instance().setWarpEnabled(false);
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
    QString command = "/usr/bin/bash -c \"systemctl start warp-svc.service\"";
#endif
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("StrErr:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTmpWarpSvcStarted(false);
    }
    else
    {
        AppModel::instance().setWarpSvcStarted(true);
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
    QString command = "/usr/bin/bash -c \"systemctl stop warp-svc.service\"";
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
        AppModel::instance().setWarpSvcStarted(false);
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
    QString command = "/usr/bin/bash -c \"systemctl enable warp-svc.service\"";
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
        AppModel::instance().setWarpSvcEnabled(true);
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
    QString command = "/usr/bin/bash -c \"systemctl disable warp-svc.service\"";
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
        AppModel::instance().setWarpSvcEnabled(false);
        LOG << "Success";
    }
    AppModel::instance().setWarpSvcEnabling(false);
    return;
}
