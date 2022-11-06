#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QTimer>
#include "TabListModel.h"
#include "WarpEvents.h"

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
    void startExecuteTimer(WarpEvents::RequestEvent event);

private slots:
    void onNotifyRequestEvent(WarpEvents::RequestEvent event);

private:
    QGuiApplication *m_app;
    TabListModel *m_tabListModel;
};

#endif // APPENGINE_H
