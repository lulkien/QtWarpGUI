#include "WarpCliController.h"
#include "Common.h"
#include "QML_Model.h"
#include "ApplicationModel.h"
#include <QStringList>
#include <QByteArray>

int RequestLocker::mLockerCount = 0;

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
    bool _result;

    // check service enabled
    _cmd = "systemctl is-enabled warp-svc.service";
    process.startCommand(_cmd, QProcess::ReadOnly);
    if (!process.waitForFinished(1000))
    {
        LOG << "FAIL TO CHECK SERVICE ENABLED... ABORT!";
        abort();
    }
    _stdout = QString(process.readAllStandardOutput()).trimmed();
    _result = QString("enabled") == _stdout;
    ApplicationModel::instance().setWarpSvcEnabled(_result);
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
    _result = QString("active") == _stdout;
    ApplicationModel::instance().setWarpSvcActivated(_result);
    LOG << _cmd << "---->" << _stdout;

    // check connection
    _cmd = "warp-cli status";
    process.startCommand(_cmd, QProcess::ReadOnly);
    if (!process.waitForFinished(1000))
    {
        LOG << "FAIL TO CHECK WARP CONNECTION... ABORT!";
        abort();
    }
    _stdout = QString(process.readAllStandardOutput()).trimmed();
    _result = _stdout.contains("Connected", Qt::CaseSensitive);
    ApplicationModel::instance().setWarpConnected(_result);
    LOG << _cmd << "---->" << _stdout;

    // init user info
    return;
}

void WarpCliController::warpConnect()
{
    LOG;
    RequestLocker guiLocker;
    // set temporary status for QML
    QML_Model::instance().setQmlConnectStatus(true);
    if (!ApplicationModel::instance().warpSvcActivated())
    {
        LOG << "Unable to connect to CloudflareWARP daemon. Maybe the daemon is not running?";
        QThread::sleep(1);
        QML_Model::instance().setQmlConnectStatus(false);
        emit notifyServiceNotStarted();
        return;
    }
    else
    {
        this->doHandleConnect(QString(CMD_WARP_CONNECT), true);
        return;
    }
}

void WarpCliController::warpDisconnect()
{
    LOG;
    RequestLocker guiLocker;
    // set temporary status for QML
    QML_Model::instance().setQmlConnectStatus(false);
    this->doHandleConnect(QString(CMD_WARP_DISCONNECT), false);
    return;
}

void WarpCliController::activeWarpService()
{
    LOG;
    RequestLocker guiLocker;
    // set temporary status for QML
    QML_Model::instance().setQmlActiveStatus(true);
    this->doHandleActive(QString(CMD_WARP_SVC_ACTIVE), true);
    return;
}

void WarpCliController::inactiveWarpService()
{
    LOG;
    RequestLocker guiLocker;
    // disconnect then inactive
    // set temporary status for QML
    QML_Model::instance().setQmlActiveStatus(false);
    if (ApplicationModel::instance().warpConnected())
    {
        this->doHandleConnect(QString(CMD_WARP_DISCONNECT), false);
    }
    this->doHandleActive(QString(CMD_WARP_SVC_INACTIVE), false);
    return;
}

void WarpCliController::enableWarpService()
{
    LOG;
    RequestLocker guiLocker;
    // set temporary status for QML
    QML_Model::instance().setQmlEnableStatus(true);
    this->doHandleEnable(QString(CMD_WARP_SVC_ENABLE), true);
    return;
}

void WarpCliController::disableWarpService()
{
    LOG;
    RequestLocker guiLocker;
    // set temporary status for QML
    QML_Model::instance().setQmlEnableStatus(false);
    this->doHandleEnable(QString(CMD_WARP_SVC_DISABLE), false);
    return;
}

void WarpCliController::doHandleConnect(const QString &command, const bool &expectedResult)
{
    LOG << expectedResult;
    // create process
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();

#ifdef WARP_DEBUG
    QThread::sleep(1);
#endif

    // print log
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));

    // check exit
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        // reset temporary status for QML
        QML_Model::instance().setQmlConnectStatus(!expectedResult);
    }
    else
    {
        // confirm final status
        ApplicationModel::instance().setWarpConnected(expectedResult);
        LOG << "Success";
    }
    return;
}

void WarpCliController::doHandleActive(const QString &command, const bool &expectedResult)
{
    LOG << expectedResult;
    // create process
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();

#ifdef WARP_DEBUG
    QThread::sleep(1);
#endif

    // print log
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));

    // check exit
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        // reset temporary status for QML
        QML_Model::instance().setQmlActiveStatus(!expectedResult);
    }
    else
    {
        // confirm final status
        ApplicationModel::instance().setWarpSvcActivated(expectedResult);
        LOG << "Success";
    }
    return;
}

void WarpCliController::doHandleEnable(const QString &command, const bool &expectedResult)
{
    LOG << expectedResult;
    // create process
    QProcess process;
    process.startCommand(command, QProcess::ReadOnly);
    process.waitForFinished();

#ifdef WARP_DEBUG
    QThread::sleep(1);
#endif

    // print log
    printResult("stdout:", QString(process.readAllStandardOutput()));
    printResult("stderr:", QString(process.readAllStandardError()));

    // check exit
    if (process.exitCode() != 0 || process.exitStatus() != QProcess::NormalExit)
    {
        LOG << "ExitCode:" << process.exitCode() << "| ExitStatus:" << process.exitStatus();
        // reset temporary status for QML
        QML_Model::instance().setQmlEnableStatus(!expectedResult);
    }
    else
    {
        // confirm final status
        ApplicationModel::instance().setWarpSvcEnabled(expectedResult);
        LOG << "Success";
    }
    return;
}

RequestLocker::RequestLocker()
{
    if (mLockerCount != 0)
    {
        LOG << "More than one instance of RequestLocker exists at a time:" << mLockerCount;
        abort();
    }
    mLockerCount++;
    QML_Model::instance().setProcessingRequest(true);
}

RequestLocker::~RequestLocker()
{
    mLockerCount = 0;
    QML_Model::instance().setProcessingRequest(false);
}
