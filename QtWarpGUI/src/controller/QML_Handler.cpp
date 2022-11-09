#include "QML_Handler.h"
#include "Common.h"

QML_Handler QML_Handler::self;

QML_Handler &QML_Handler::instance()
{
    return self;
}

QML_Handler *QML_Handler::create(QQmlEngine *, QJSEngine *)
{
    return &self;
}

void QML_Handler::qmlDebug(QString msg)
{
    QML_LOG << msg;
}

void QML_Handler::qmlSendGUIEvent(WarpEnums::GUIEvents _event)
{
    LOG << _event;
}

void QML_Handler::qmlSendRequestEvent(WarpEnums::RequestEvent _event, QVariant data)
{
    LOG << "Event:" << _event << "| Data:" << data;
    emit notifyRequestEvent(_event, data);
}

QML_Handler::QML_Handler()
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}
