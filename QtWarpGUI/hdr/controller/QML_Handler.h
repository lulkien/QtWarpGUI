#ifndef QML_HANDLER_H
#define QML_HANDLER_H

#include <QObject>
#include <QQmlEngine>
#include "WarpEnums.h"

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
    void qmlSendGUIEvent(WarpEnums::GUIEvents _event);
    void qmlSendRequestEvent(WarpEnums::RequestEvent _event);

private:
    static QML_Handler self;
    QML_Handler();

signals:
    void notifyRequestEvent(WarpEnums::RequestEvent _event);

};

#endif // QML_HANDLER_H
