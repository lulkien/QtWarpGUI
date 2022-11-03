#include "QML_Handler.h"
#include "Common.h"

QML_Handler &QML_Handler::instance()
{
    static QML_Handler _self;
    return _self;
}

void QML_Handler::qmlDebug(QString msg)
{
    QML_LOG << msg;
}

void QML_Handler::qmlSendEvent(WarpEvents::Events _event)
{
    LOG << _event;
}

QML_Handler::QML_Handler()
{

}
