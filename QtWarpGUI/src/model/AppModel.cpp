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
    , m_warpEnabled         { false }
    , m_tmpWarpEnabled      { false }
    , m_warpEnabling        { false }
    , m_warpSvcStarted      { false }
    , m_tmpWarpSvcStarted   { false }
    , m_warpSvcStarting     { false }
    , m_warpSvcEnabled      { false }
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

void AppModel::setWarpEnabled(bool newWarpEnabled)
{
    m_warpEnabled = newWarpEnabled;
    this->setTmpWarpEnabled(m_warpEnabled);
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

void AppModel::setWarpSvcStarted(bool newWarpSvcStarted)
{
    m_warpSvcStarted = newWarpSvcStarted;
    this->setTmpWarpSvcStarted(m_warpSvcStarted);
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

void AppModel::setWarpSvcEnabled(bool newWarpSvcEnabled)
{
    m_warpSvcEnabled = newWarpSvcEnabled;
    this->setTmpWarpSvcEnabled(m_warpSvcEnabled);
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
