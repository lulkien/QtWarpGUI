#ifndef COMMON_H
#define COMMON_H

#include <QDebug>
#include <QString>
#include <QThread>

#define QML_LOG qDebug().noquote() << "[QmlMessage] "
#define LOG     qDebug().noquote() << "[" << QThread::currentThreadId() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "
//#define LOG     qDebug().noquote() << QString("[0x%1][%2][%3]").arg((int)QThread::currentThreadId()).arg(__FUNCTION__).arg(__LINE__)

// custom import qml
#define QML_IMPORT          "com.warp.custom"
#define QML_IMPORT_MAJOR    1
#define QML_IMPORT_MINOR    0

// linux
#define BASH            QString("/usr/bin/bash")
#define WARP_SERVICE    QString("warp-svc.service")

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
