#include "AppModel.h"
#include "Common.h"

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

AppModel::AppModel()
    : m_currentTab          { 2 }
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

int AppModel::currentTab() const
{
    return m_currentTab;
}

void AppModel::setCurrentTab(int newCurrentTab)
{
    if (m_currentTab == newCurrentTab)
        return;
    m_currentTab = newCurrentTab;
    emit currentTabChanged();
}


bool AppModel::tmpWarpEnabled() const
{
    return m_tmpWarpEnabled;
}

void AppModel::setTmpWarpEnabled(bool newTmpWarpEnabled)
{
    if (m_tmpWarpEnabled == newTmpWarpEnabled)
        return;
    m_tmpWarpEnabled = newTmpWarpEnabled;
    emit tmpWarpEnabledChanged();
}

bool AppModel::tmpWarpSvcStarted() const
{
    return m_tmpWarpSvcStarted;
}

void AppModel::setTmpWarpSvcStarted(bool newTmpWarpSvcStarted)
{
    if (m_tmpWarpSvcStarted == newTmpWarpSvcStarted)
        return;
    m_tmpWarpSvcStarted = newTmpWarpSvcStarted;
    emit tmpWarpSvcStartedChanged();
}

bool AppModel::tmpWarpSvcEnabled() const
{
    return m_tmpWarpSvcEnabled;
}

void AppModel::setTmpWarpSvcEnabled(bool newTmpWarpSvcEnabled)
{
    if (m_tmpWarpSvcEnabled == newTmpWarpSvcEnabled)
        return;
    m_tmpWarpSvcEnabled = newTmpWarpSvcEnabled;
    emit tmpWarpSvcEnabledChanged();
}

bool AppModel::warpEnabling() const
{
    return m_warpEnabling;
}

void AppModel::setWarpEnabling(bool newWarpEnabling)
{
    if (m_warpEnabling == newWarpEnabling)
        return;
    m_warpEnabling = newWarpEnabling;
    emit warpEnablingChanged();
}

bool AppModel::warpSvcStarting() const
{
    return m_warpSvcStarting;
}

void AppModel::setWarpSvcStarting(bool newWarpSvcStarting)
{
    if (m_warpSvcStarting == newWarpSvcStarting)
        return;
    m_warpSvcStarting = newWarpSvcStarting;
    emit warpSvcStartingChanged();
}

bool AppModel::warpSvcEnabling() const
{
    return m_warpSvcEnabling;
}

void AppModel::setWarpSvcEnabling(bool newWarpSvcEnabling)
{
    if (m_warpSvcEnabling == newWarpSvcEnabling)
        return;
    m_warpSvcEnabling = newWarpSvcEnabling;
    emit warpSvcEnablingChanged();
}
