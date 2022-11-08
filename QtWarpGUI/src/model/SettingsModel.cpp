#include "SettingsModel.h"
#include "AppModel.h"

SettingsModel &SettingsModel::instance()
{
    static SettingsModel self;
    return self;
}

bool SettingsModel::warpEnabled() const
{
    return m_warpEnabled;
}

void SettingsModel::setWarpEnabled(bool newWarpEnabled)
{
    m_warpEnabled = newWarpEnabled;
    AppModel::instance().setTmpWarpEnabled(m_warpEnabled);
}

bool SettingsModel::warpServiceStarted() const
{
    return m_warpServiceStarted;
}

void SettingsModel::setWarpServiceStarted(bool newWarpServiceStarted)
{
    m_warpServiceStarted = newWarpServiceStarted;
    AppModel::instance().setTmpWarpSvcStarted(m_warpServiceStarted);
}

bool SettingsModel::warpServiceEnabled() const
{
    return m_warpServiceEnabled;
}

void SettingsModel::setWarpServiceEnabled(bool newWarpServiceEnabled)
{
    m_warpServiceEnabled = newWarpServiceEnabled;
    AppModel::instance().setTmpWarpSvcEnabled(m_warpServiceEnabled);
}

SettingsModel::SettingsModel()
    : m_warpEnabled { false }
    , m_warpServiceStarted { false }
    , m_warpServiceEnabled { false }
{

}
