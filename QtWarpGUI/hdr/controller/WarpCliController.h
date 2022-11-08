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
    void enableWarp();
    void disableWarp();
    void startWarpService();
    void stopWarpService();
    void enableWarpService();
    void disableWarpService();


private:
    void printResult(QString prefix, QString data);

private slots:

private:

signals:

};

#endif // WARPCLICONTROLLER_H
