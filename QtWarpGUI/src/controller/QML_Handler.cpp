#include "QML_Handler.h"
#include <QDebug>

QML_Handler &QML_Handler::instance()
{
    static QML_Handler _self;
    return _self;
}

void QML_Handler::qmlDebug(QString msg)
{
    qDebug().noquote() << "[QML]" << msg;
}

QML_Handler::QML_Handler()
{

}
