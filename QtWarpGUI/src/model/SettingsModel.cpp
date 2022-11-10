#include "SettingsModel.h"
#include "QML_Model.h"

SettingsModel &SettingsModel::instance()
{
    static SettingsModel self;
    return self;
}

bool SettingsModel::warpConnected() const
{
    return m_warpConnected;
}

void SettingsModel::setWarpConnected(bool newWarpConnected)
{
    m_warpConnected = newWarpConnected;
    QML_Model::instance().setQmlConnectStatus(m_warpConnected);
}

bool SettingsModel::warpSvcActivated() const
{
    return m_warpSvcActivated;
}

void SettingsModel::setWarpSvcActivated(bool newWarpSvcActivated)
{
    m_warpSvcActivated = newWarpSvcActivated;
    QML_Model::instance().setQmlActiveStatus(m_warpSvcActivated);
}

bool SettingsModel::warpSvcEnabled() const
{
    return m_warpSvcEnabled;
}

void SettingsModel::setWarpSvcEnabled(bool newWarpSvcEnabled)
{
    m_warpSvcEnabled = newWarpSvcEnabled;
    QML_Model::instance().setQmlEnableStatus(m_warpSvcEnabled);
}

SettingsModel::SettingsModel()
    : m_warpConnected       { false }
    , m_warpSvcActivated    { false }
    , m_warpSvcEnabled      { false }
{

}
