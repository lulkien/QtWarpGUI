#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QTimer>
#include "TabListModel.h"
#include "WarpEvents.h"
#include "WarpCliController.h"
#include <QThread>

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
    void initEnvironment();
    void initQmlContexts();
    void initConnections();

private slots:
    void onNotifyRequestEvent(WarpEvents::RequestEvent event);

private:
    QGuiApplication *m_app;
    TabListModel *m_tabListModel;
    WarpCliController *m_warpController;
    QThread *m_warpWorker;

signals:
    void reqWarpCliStartService();
    void reqWarpCliStopService();
};

#endif // APPENGINE_H
