#ifndef COMMON_H
#define COMMON_H

#include <QDebug>

#define QML_LOG qDebug().noquote() << "[QML] "
#define LOG     qDebug().noquote() << "[" << __PRETTY_FUNCTION__ << "][" << __LINE__ << "] "

// custom import qml
#define QML_IMPORT          "com.warp.custom"
#define QML_IMPORT_MAJOR    1
#define QML_IMPORT_MINOR    0

#endif // COMMON_H
