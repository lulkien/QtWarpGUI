#include "AppEngine.h"
#include "Common.h"
#include "Constants.h"
#include "QML_Handler.h"
#include "WarpCliController.h"
#include <QQmlContext>

AppEngine::AppEngine(QGuiApplication *app)
    : m_app { app }
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
        initSettings();
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
    m_tabListModel = new TabListModel();
    m_warpController = new WarpCliController();
    m_warpWorker = new QThread();

    m_warpController->moveToThread(m_warpWorker);
    m_warpWorker->start();
}

void AppEngine::initQmlContexts()
{
    LOG;
    this->rootContext()->setContextProperty("tabModel", m_tabListModel);
}

void AppEngine::initConnections()
{
    LOG;
    connect(m_warpWorker, &QThread::finished, m_warpWorker, &QObject::deleteLater);
    connect(&QML_Handler::instance(), &QML_Handler::notifyRequestEvent,
            this, &AppEngine::onNotifyRequestEvent);
    connect(this, &AppEngine::reqWarpCliStartService,
            m_warpController, &WarpCliController::startWarpService, Qt::QueuedConnection);
    connect(this, &AppEngine::reqWarpCliStopService,
            m_warpController, &WarpCliController::stopWarpService, Qt::QueuedConnection);
    connect(this, &AppEngine::reqWarpCliEnableService,
            m_warpController, &WarpCliController::enableWarpService, Qt::QueuedConnection);
    connect(this, &AppEngine::reqWarpCliDisableService,
            m_warpController, &WarpCliController::disableWarpService, Qt::QueuedConnection);
}

void AppEngine::initSettings()
{
    m_warpController->initSystemSettings(); // this function must be called in main thread
}

void AppEngine::onNotifyRequestEvent(WarpEnums::RequestEvent event)
{
    switch (event) {
    case WarpEnums::EVT_REQ_START_WARP_SERVICE:
        emit reqWarpCliStartService();
        break;
    case WarpEnums::EVT_REQ_STOP_WARP_SERVICE:
        emit reqWarpCliStopService();
        break;
    case WarpEnums::EVT_REQ_ENABLE_WARP_SERVICE:
        emit reqWarpCliEnableService();
        break;
    case WarpEnums::EVT_REQ_DISABLE_WARP_SERVICE:
        emit reqWarpCliDisableService();
        break;
    default:
        break;
    }
}

