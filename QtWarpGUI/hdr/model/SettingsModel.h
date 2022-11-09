#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QtGlobal>

class SettingsModel final
{
    Q_DISABLE_COPY(SettingsModel)
public:
    static SettingsModel &instance();

    bool warpConnected() const;
    void setWarpConnected(bool newWarpConnected);

    bool warpSvcActivated() const;
    void setWarpSvcActivated(bool newWarpSvcActivated);

    bool warpSvcEnabled() const;
    void setWarpSvcEnabled(bool newWarpSvcEnabled);

private:
    SettingsModel();

private:
    bool m_warpConnected;
    bool m_warpSvcActivated;
    bool m_warpSvcEnabled;

};

#endif // SETTINGSMODEL_H
