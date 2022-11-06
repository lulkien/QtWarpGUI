#ifndef WARPCLICONTROLLER_H
#define WARPCLICONTROLLER_H

#include <QObject>
#include <QProcess>
#include <QString>

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

    static WarpCliController &instance();
    virtual ~WarpCliController();

    void startWarpService();
    void stopWarpService();

private:
    WarpCliController();
    void initConnections();
    void printResult(QString prefix, QString data);

private slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
    void onFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QProcess *m_process;
    WorkID m_currentWorkID;

signals:

};

#endif // WARPCLICONTROLLER_H
