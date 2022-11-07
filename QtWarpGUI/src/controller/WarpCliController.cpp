#include "WarpCliController.h"
#include "Common.h"
#include "AppModel.h"
#include <QStringList>
#include <QByteArray>

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
        LOG << "\n" << prefix << data;
    }
}

WarpCliController::~WarpCliController()
{
    LOG;
}

void WarpCliController::startWarpService()
{
    LOG;
#ifdef WARP_DEBUG
    QString command = "echo \"systemctl start warp-svc.service\"";
#else
    QString command = "/usr/bin/bash -c \"systemctl start warp-svc.service\"";
#endif
    AppModel::instance().setWarpSvcStarting(true);
    QThread::sleep(5);
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("Output:", QString(process.readAllStandardOutput()));
    printResult("Error:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        AppModel::instance().setTmpWarpSvcStarted(false);
    }
    else
    {
        LOG << "Success";
    }
    AppModel::instance().setWarpSvcStarting(false);
    return;
}

void WarpCliController::stopWarpService()
{
    LOG;
#ifdef WARP_DEBUG
    QString command = "echo \"systemctl stop warp-svc.service\"";
#else
    QString command = "/usr/bin/bash -c \"systemctl stop warp-svc.service\"";
#endif
    AppModel::instance().setWarpSvcStarting(true);
    QThread::sleep(5);
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();
    printResult("Output:", QString(process.readAllStandardOutput()));
    printResult("Error:", QString(process.readAllStandardError()));
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        AppModel::instance().setTmpWarpSvcStarted(true);
    }
    else
    {
        LOG << "Success";
    }
    AppModel::instance().setWarpSvcStarting(false);
    return;
}
