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
    : m_currentTab { 2 }
    , m_warpEnabled { false }
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

bool AppModel::warpEnabled() const
{
    return m_warpEnabled;
}

void AppModel::setWarpEnabled(bool newWarpEnabled)
{
    if (m_warpEnabled == newWarpEnabled)
        return;
    m_warpEnabled = newWarpEnabled;
    emit warpEnabledChanged();
}
