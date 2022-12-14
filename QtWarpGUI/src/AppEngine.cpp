#include "AppEngine.h"
#include "Common.h"
#include "Constants.h"
#include "QML_Handler.h"
#include "QML_Model.h"
#include "WarpCliController.h"
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include "Translator.h"

AppEngine::AppEngine(QGuiApplication *app)
    : m_app { app }
{
    LOG;
}

AppEngine::~AppEngine()
{
    LOG;
    safeDelete<TabListModel>(m_tabListModel);
    safeDelete<WarpCliController>(m_warpController);
    safeDelete<OSD_Controller>(m_osdController);
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

    // create QML OSD Ctroller after load qml
    createQmlOSDController();
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
    // QThread - > QThread
    connect(&QML_Handler::instance(), &QML_Handler::notifyRequestEvent,
            this, &AppEngine::onNotifyRequestEvent);
    // this -> Warp-Cli
    connect(this, &AppEngine::reqWarpConnect,
            m_warpController, &WarpCliController::warpConnect, Qt::QueuedConnection);
    connect(this, &AppEngine::reqWarpDisconnect,
            m_warpController, &WarpCliController::warpDisconnect, Qt::QueuedConnection);
    connect(this, &AppEngine::reqActiveWarpService,
            m_warpController, &WarpCliController::activeWarpService, Qt::QueuedConnection);
    connect(this, &AppEngine::reqInactiveWarpService,
            m_warpController, &WarpCliController::inactiveWarpService, Qt::QueuedConnection);
    connect(this, &AppEngine::reqEnableWarpService,
            m_warpController, &WarpCliController::enableWarpService, Qt::QueuedConnection);
    connect(this, &AppEngine::reqDisableWarpService,
            m_warpController, &WarpCliController::disableWarpService, Qt::QueuedConnection);
    // Warp-Cli -> this
    connect(m_warpController, &WarpCliController::notifyServiceNotStarted,
            this, &AppEngine::onNotifyServiceNotStarted, Qt::QueuedConnection);
}

void AppEngine::initSettings()
{
    m_warpController->initSystemSettings(); // this function must be called in main thread
}

void AppEngine::createQmlOSDController()
{
    m_osdController = new OSD_Controller(this);
}

void AppEngine::handleRequestWarpConnect(bool isReqConnect)
{
    LOG << isReqConnect;
    if (isReqConnect)
        emit reqWarpConnect();
    else
        emit reqWarpDisconnect();
}

void AppEngine::handleRequestActiveService(bool isReqActive)
{
    LOG << isReqActive;
    if (isReqActive)
        emit reqActiveWarpService();
    else
        emit reqInactiveWarpService();
}

void AppEngine::handleRequestEnableService(bool isReqEnable)
{
    LOG << isReqEnable;
    if (isReqEnable)
        emit reqEnableWarpService();
    else
        emit reqDisableWarpService();
}

void AppEngine::onNotifyRequestEvent(WarpEnums::RequestEvent event, QVariant data)
{
    switch (event) {
    case WarpEnums::EVT_REQ_WARP_CONNECT:
        this->handleRequestWarpConnect(data.toBool());
        break;
    case WarpEnums::EVT_REQ_ACTIVE_WARP_SERVICE:
        this->handleRequestActiveService(data.toBool());
        break;
    case WarpEnums::EVT_REQ_ENABLE_WARP_SERVICE:
        this->handleRequestEnableService(data.toBool());
        break;
    case WarpEnums::EVT_REQ_GO_TO_SETTING:
        m_osdController->hideOSD(WarpEnums::OSD_REQUIRE_START_SERVICE);
        QML_Model::instance().setCurrentTab(WarpEnums::SETUP);
        break;
    case WarpEnums::EVT_HIDE_OSD_REQUIRE_START_SVC:
        m_osdController->hideOSD(WarpEnums::OSD_REQUIRE_START_SERVICE);
        break;
    default:
        LOG << "Default case";
        break;
    }
}

void AppEngine::onNotifyServiceNotStarted()
{
    LOG;
    m_osdController->showOSD(WarpEnums::OSD_REQUIRE_START_SERVICE);
}

