#ifndef COMMON_H
#define COMMON_H

#include <QDebug>
#include <QString>
#include <QThread>

#define QML_LOG qDebug().noquote() << "[QmlMessage] "
#define LOG     qDebug().noquote() << "[" << QThread::currentThreadId() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "

// custom import qml
#define QML_IMPORT          "com.warp.custom"
#define QML_IMPORT_MAJOR    1
#define QML_IMPORT_MINOR    0

// linux

// command
#ifdef WARP_DEBUG
#define CMD_WARP_CONNECT        "echo \"warp-cli connect\""
#define CMD_WARP_DISCONNECT     "echo \"warp-cli disconnect\""
#define CMD_WARP_SVC_ACTIVE     "echo \"systemctl start warp-svc.service\""
#define CMD_WARP_SVC_INACTIVE   "echo \"systemctl stop warp-svc.service\""
#define CMD_WARP_SVC_ENABLE     "echo \"systemctl enable warp-svc.service\""
#define CMD_WARP_SVC_DISABLE    "echo \"systemctl disable warp-svc.service\""

#else
#define CMD_WARP_CONNECT        "warp-cli connect"
#define CMD_WARP_DISCONNECT     "warp-cli disconnect"
#define CMD_WARP_SVC_ACTIVE     "systemctl start warp-svc.service"
#define CMD_WARP_SVC_INACTIVE   "systemctl stop warp-svc.service"
#define CMD_WARP_SVC_ENABLE     "systemctl enable warp-svc.service"
#define CMD_WARP_SVC_DISABLE    "systemctl disable warp-svc.service"
#endif

// general define
#define CAST        static_cast
#define DCAST       dynamic_cast
#define RCAST       reinterpret_cast
#define QCAST       qobject_cast

// static functions
namespace {
template <class T>
void safeDelete(T* _ptr)
{
    if (nullptr != _ptr)
    {
        delete _ptr;
        _ptr = nullptr;
    }
}
}

#endif // COMMON_H
