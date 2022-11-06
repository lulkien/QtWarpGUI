#include "SettingsModel.h"

SettingsModel &SettingsModel::instance()
{
    static SettingsModel self;
    return self;
}

bool SettingsModel::warpEnabled() const
{
    return m_warpEnabled;
}

void SettingsModel::setWarpEnabled(bool status)
{
    m_warpEnabled = status;
}

SettingsModel::SettingsModel()
    : m_warpEnabled { false }
    , m_warpServiceStarted { false }
    , m_warpServiceEnabled { false }
{

}
