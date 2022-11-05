#ifndef QML_HANDLER_H
#define QML_HANDLER_H

#include <QObject>
#include <QQmlEngine>
#include "WarpEvents.h"

class QML_Handler final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    static QML_Handler &instance();
    static QML_Handler *create(QQmlEngine *, QJSEngine *);

public slots:
    void qmlDebug(QString msg);
    void qmlSendGUIEvent(WarpEvents::GUIEvents _event);
    void qmlSendLogicEvent(WarpEvents::RequestEvent _event);

private:
    static QML_Handler self;
    QML_Handler();

signals:

};

#endif // QML_HANDLER_H
