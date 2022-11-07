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
    enum WorkID {
        DoNothing = 0,
        EnableWarp,
        DisableWarp,
        StartWarpService,
        StopWarpService,
        EnableWarpService,
        DisableWarpService,
    };

    WarpCliController();
    virtual ~WarpCliController();

public slots:
    void enableWarp();
    void disableWarp();
    void startWarpService();
    void stopWarpService();
    void enableWarpService();
    void disableWarpService();

private:
    void initConnections();
    void printResult(QString prefix, QString data);

private slots:

private:
    WorkID m_currentWorkID;

signals:

};

#endif // WARPCLICONTROLLER_H
