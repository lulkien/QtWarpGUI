#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QTimer>
#include <QThread>
#include <QVariant>
#include "WarpEnums.h"
#include "TabListModel.h"
#include "WarpCliController.h"

class AppEngine : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    AppEngine(QGuiApplication *app);
    virtual ~AppEngine();

    void startApplication();
    bool initApplication();

public slots:

private:
    // inits
    void initEnvironment();
    void initQmlContexts();
    void initConnections();
    void initSettings();

    // general
    void handleRequestWarpConnect(bool isReqConnect);
    void handleRequestActiveService(bool isReqActive);
    void handleRequestEnableService(bool isReqEnable);

private slots:
    void onNotifyRequestEvent(WarpEnums::RequestEvent event, QVariant data);
    void onNotifyServiceNotStarted();

private:
    QGuiApplication *m_app;
    TabListModel *m_tabListModel;
    WarpCliController *m_warpController;
    QThread *m_warpWorker;

signals:
    void reqWarpConnect();
    void reqWarpDisconnect();
    void reqActiveWarpService();
    void reqInactiveWarpService();
    void reqEnableWarpService();
    void reqDisableWarpService();
};

#endif // APPENGINE_H
