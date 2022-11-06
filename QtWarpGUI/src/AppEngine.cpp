#include "AppEngine.h"
#include "Common.h"
#include "Constants.h"
#include "QML_Handler.h"
#include "WarpCliController.h"
#include <QQmlContext>

AppEngine::AppEngine(QGuiApplication *app)
    : m_app { app }
    , m_tabListModel { new TabListModel() }
{
    LOG;
}

AppEngine::~AppEngine()
{
    LOG;
    safeDelete<TabListModel>(m_tabListModel);
}

void AppEngine::startApplication()
{
    LOG;
    if (!this->initApplication())
    {
        LOG << "Application must be initialized first";
        return;
    }
    QUrl url = Constants::instance().MAIN_QML();
    QObject::connect(this, &QQmlApplicationEngine::objectCreated,
                     m_app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    this->load(url);
}

bool AppEngine::initApplication()
{
    static bool initialized = false;
    if (!initialized)
    {
        LOG << "First initialize.";
        initialized = true;
        initEnvironment();
        initQmlContexts();
        initConnections();
        return false;
    }
    else
    {
        LOG << "Application was initialized... Return True for checking.";
        return true;
    }
}

void AppEngine::initEnvironment()
{
    LOG;
}

void AppEngine::initQmlContexts()
{
    LOG;
    this->rootContext()->setContextProperty("tabModel", m_tabListModel);
}

void AppEngine::initConnections()
{
    LOG;
    connect(&QML_Handler::instance(), &QML_Handler::notifyRequestEvent,
            this, &AppEngine::onNotifyRequestEvent);
}

void AppEngine::startExecuteTimer(WarpEvents::RequestEvent event)
{
    LOG;
    QTimer::singleShot(200, [event]() {
        LOG << event;
        switch (event) {
        case WarpEvents::EVT_REQ_START_WARP_SERVICE:
            WarpCliController::instance().startWarpService();
            break;
        case WarpEvents::EVT_REQ_STOP_WARP_SERVICE:
            WarpCliController::instance().stopWarpService();
            break;
        default:
            break;
        }
    });
}

void AppEngine::onNotifyRequestEvent(WarpEvents::RequestEvent event)
{
    switch (event) {
    case WarpEvents::EVT_REQ_START_WARP_SERVICE:
    case WarpEvents::EVT_REQ_STOP_WARP_SERVICE:
        startExecuteTimer(event);
        break;
    default:
        break;
    }
}

