#include "AppModel.h"
#include "Common.h"
#include "WarpEnums.h"

AppModel AppModel::self;

AppModel &AppModel::instance()
{
    return self;
}

AppModel *AppModel::create(QQmlEngine *, QJSEngine *)
{
    return &self;
}

AppModel::~AppModel()
{
    LOG;
}

void AppModel::init()
{
    LOG << "Do init AppModel";
}

AppModel::AppModel()
    : m_currentTab              { static_cast<int>(WarpEnums::SETUP) }
    , m_tempWarpConnected       { false }
    , m_tempWarpSvcActivated    { false }
    , m_tempWarpSvcEnabled      { false }
    , m_processingRequest       { false }
{
    LOG;
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

void AppModel::setCurrentTab(int newCurrentTab)
{
    if (m_currentTab == newCurrentTab)
        return;
    m_currentTab = newCurrentTab;
    emit currentTabChanged();
}

void AppModel::setTempWarpConnected(bool newTempWarpConnected)
{
    if (m_tempWarpConnected == newTempWarpConnected)
        return;
    m_tempWarpConnected = newTempWarpConnected;
    emit tempWarpConnectedChanged();
}

void AppModel::setTempWarpSvcActivated(bool newTempWarpSvcActivated)
{
    if (m_tempWarpSvcActivated == newTempWarpSvcActivated)
        return;
    m_tempWarpSvcActivated = newTempWarpSvcActivated;
    emit tempWarpSvcActivatedChanged();
}

void AppModel::setTempWarpSvcEnabled(bool newTempWarpSvcEnabled)
{
    if (m_tempWarpSvcEnabled == newTempWarpSvcEnabled)
        return;
    m_tempWarpSvcEnabled = newTempWarpSvcEnabled;
    emit tempWarpSvcEnabledChanged();
}

void AppModel::setProcessingRequest(bool newProcessingRequest)
{
    if (m_processingRequest == newProcessingRequest)
        return;
    m_processingRequest = newProcessingRequest;
    emit processingRequestChanged();
    if (!m_processingRequest)
    {
        LOG << "processingRequestCompleted";
        emit processingRequestCompleted();
    }
}
