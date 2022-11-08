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
    : m_currentTab          { static_cast<int>(WarpEnums::SETUP) }
    , m_tmpWarpEnabled      { false }
    , m_warpEnabling        { false }
    , m_tmpWarpSvcStarted   { false }
    , m_warpSvcStarting     { false }
    , m_tmpWarpSvcEnabled   { false }
    , m_warpSvcEnabling     { false }
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

void AppModel::setTmpWarpEnabled(bool newTmpWarpEnabled)
{
    if (m_tmpWarpEnabled == newTmpWarpEnabled)
        return;
    m_tmpWarpEnabled = newTmpWarpEnabled;
    emit tmpWarpEnabledChanged();
}

void AppModel::setWarpEnabling(bool newWarpEnabling)
{
    if (m_warpEnabling == newWarpEnabling)
        return;
    m_warpEnabling = newWarpEnabling;
    emit warpEnablingChanged();
}

void AppModel::setTmpWarpSvcStarted(bool newTmpWarpSvcStarted)
{
    if (m_tmpWarpSvcStarted == newTmpWarpSvcStarted)
        return;
    m_tmpWarpSvcStarted = newTmpWarpSvcStarted;
    emit tmpWarpSvcStartedChanged();
}

void AppModel::setWarpSvcStarting(bool newWarpSvcStarting)
{
    if (m_warpSvcStarting == newWarpSvcStarting)
        return;
    m_warpSvcStarting = newWarpSvcStarting;
    emit warpSvcStartingChanged();
}

void AppModel::setTmpWarpSvcEnabled(bool newTmpWarpSvcEnabled)
{
    if (m_tmpWarpSvcEnabled == newTmpWarpSvcEnabled)
        return;
    m_tmpWarpSvcEnabled = newTmpWarpSvcEnabled;
    emit tmpWarpSvcEnabledChanged();
}

void AppModel::setWarpSvcEnabling(bool newWarpSvcEnabling)
{
    if (m_warpSvcEnabling == newWarpSvcEnabling)
        return;
    m_warpSvcEnabling = newWarpSvcEnabling;
    emit warpSvcEnablingChanged();
}
