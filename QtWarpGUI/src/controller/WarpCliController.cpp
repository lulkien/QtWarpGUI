#include "WarpCliController.h"
#include "Common.h"
#include "AppModel.h"
#include <QStringList>
#include <QByteArray>

WarpCliController::WarpCliController()
    : m_process         { new QProcess() }
    , m_currentWorkID   { DoNothing }
{
    LOG;
}

void WarpCliController::initConnections()
{
//    connect(m_process, &QProcess::readyReadStandardOutput, this, &WarpCliController::onReadyReadStandardOutput);
//    connect(m_process, &QProcess::readyReadStandardError, this, &WarpCliController::onReadyReadStandardError);
    //    connect(m_process, &QProcess::finished, this, &WarpCliController::onFinished);
}

void WarpCliController::printResult(QString prefix, QString data)
{
    data = data.trimmed();
    if (!data.isEmpty())
    {
        LOG << "\n" << prefix << data;
    }
}

void WarpCliController::onReadyReadStandardOutput()
{
    QByteArray stdOut = m_process->readAllStandardOutput();
    LOG << QString(stdOut);
}

void WarpCliController::onReadyReadStandardError()
{
    QByteArray stdErr = m_process->readAllStandardOutput();
    LOG << QString(stdErr);
}

void WarpCliController::onFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    LOG << "Code:" << exitCode << "| ExitStatus:" << exitStatus << "| WorkID:" << m_currentWorkID;

    m_currentWorkID = DoNothing;
}

WarpCliController &WarpCliController::instance()
{
    static WarpCliController self;
    return self;
}

WarpCliController::~WarpCliController()
{
    LOG;
    safeDelete<QProcess>(m_process);
}

void WarpCliController::startWarpService()
{
    LOG;
    QString command = "/usr/bin/bash -c \"systemctl start warp-svc.service\"";
    AppModel::instance().setWarpSvcStarting(true);
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
    QString command = "/usr/bin/bash -c \"systemctl stop warp-svc.service\"";
    AppModel::instance().setWarpSvcStarting(true);
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
