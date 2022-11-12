#include "QML_Model.h"
#include "Common.h"
#include "WarpEnums.h"

QML_Model &QML_Model::instance()
{
    static QML_Model self;
    return self;
}

QML_Model *QML_Model::create(QQmlEngine *, QJSEngine *)
{
    return &instance();
}

QML_Model::~QML_Model()
{
    LOG;
}

void QML_Model::init()
{
    LOG << "Do init QML_Model";
}

QML_Model::QML_Model()
    : m_currentTab          { static_cast<int>(WarpEnums::HOME) }
    , m_qmlConnectStatus    { false }
    , m_qmlActiveStatus     { false }
    , m_qmlEnableStatus     { false }
    , m_processingRequest   { false }
{
    LOG;
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

void QML_Model::setCurrentTab(int newCurrentTab)
{
    if (m_currentTab == newCurrentTab)
        return;
    m_currentTab = newCurrentTab;
    emit currentTabChanged();
}

void QML_Model::setQmlConnectStatus(bool newTempWarpConnected)
{
    if (m_qmlConnectStatus == newTempWarpConnected)
        return;
    m_qmlConnectStatus = newTempWarpConnected;
    emit qmlConnectStatusChanged();
}

void QML_Model::setQmlActiveStatus(bool newTempWarpSvcActivated)
{
    if (m_qmlActiveStatus == newTempWarpSvcActivated)
        return;
    m_qmlActiveStatus = newTempWarpSvcActivated;
    emit qmlActiveStatusChanged();
}

void QML_Model::setQmlEnableStatus(bool newTempWarpSvcEnabled)
{
    if (m_qmlEnableStatus == newTempWarpSvcEnabled)
        return;
    m_qmlEnableStatus = newTempWarpSvcEnabled;
    emit qmlEnableStatusChanged();
}

void QML_Model::setProcessingRequest(bool newProcessingRequest)
{
    if (m_processingRequest == newProcessingRequest)
        return;
    m_processingRequest = newProcessingRequest;
    emit processingRequestChanged();
    if (!m_processingRequest)
        emit processingRequestCompleted();
}
