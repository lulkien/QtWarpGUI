#ifndef QML_HANDLER_H
#define QML_HANDLER_H

#include <QObject>
#include "WarpEvents.h"

class QML_Handler final : public QObject
{
    Q_OBJECT
public:
    static QML_Handler &instance();

public slots:
    void qmlDebug(QString msg);
    void qmlSendEvent(WarpEvents::Events _event);

private:
    QML_Handler();

signals:

};

#endif // QML_HANDLER_H
