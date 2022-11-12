#include "ApplicationModel.h"
#include "QML_Model.h"

ApplicationModel &ApplicationModel::instance()
{
    static ApplicationModel self;
    return self;
}

bool ApplicationModel::warpConnected() const
{
    return m_warpConnected;
}

void ApplicationModel::setWarpConnected(bool newWarpConnected)
{
    m_warpConnected = newWarpConnected;
    QML_Model::instance().setQmlConnectStatus(m_warpConnected);
}

bool ApplicationModel::warpSvcActivated() const
{
    return m_warpSvcActivated;
}

void ApplicationModel::setWarpSvcActivated(bool newWarpSvcActivated)
{
    m_warpSvcActivated = newWarpSvcActivated;
    QML_Model::instance().setQmlActiveStatus(m_warpSvcActivated);
}

bool ApplicationModel::warpSvcEnabled() const
{
    return m_warpSvcEnabled;
}

void ApplicationModel::setWarpSvcEnabled(bool newWarpSvcEnabled)
{
    m_warpSvcEnabled = newWarpSvcEnabled;
    QML_Model::instance().setQmlEnableStatus(m_warpSvcEnabled);
}

ApplicationModel::ApplicationModel()
    : m_warpConnected       { false }
    , m_warpSvcActivated    { false }
    , m_warpSvcEnabled      { false }
{

}
