#ifndef WARPCLICONTROLLER_H
#define WARPCLICONTROLLER_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QThread>

class RequestLocker
{
    static int mLockerCount;
public:
    RequestLocker();
    ~RequestLocker();
};

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
    void doHandleConnect(const QString& command, const bool& expectedResult);
    void doHandleActive(const QString& command, const bool& expectedResult);
    void doHandleEnable(const QString& command, const bool& expectedResult);
    void printResult(QString prefix, QString data);

private slots:

private:

signals:
    void notifyServiceNotStarted();

};

#endif // WARPCLICONTROLLER_H
