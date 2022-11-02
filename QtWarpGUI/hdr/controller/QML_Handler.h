#ifndef QML_HANDLER_H
#define QML_HANDLER_H

#include <QObject>

class QML_Handler final : public QObject
{
    Q_OBJECT
public:
    static QML_Handler &instance();

public slots:
    void qmlDebug(QString msg);

private:
    QML_Handler();

signals:

};

#endif // QML_HANDLER_H
