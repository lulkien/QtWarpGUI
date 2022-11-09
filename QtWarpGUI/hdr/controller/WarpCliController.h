#ifndef WARPCLICONTROLLER_H
#define WARPCLICONTROLLER_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QThread>

class WarpCliController : public QObject
{
    Q_OBJECT
public:
    WarpCliController();
    virtual ~WarpCliController();

    void initSystemSettings();

public slots:
    void warpConnect();
    void warpDisconnect();
    void activeWarpService();
    void inactiveWarpService();
    void enableWarpService();
    void disableWarpService();


private:
    void printResult(QString prefix, QString data);

private slots:

private:

signals:

};

#endif // WARPCLICONTROLLER_H
