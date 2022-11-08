#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QtGlobal>

class SettingsModel final
{
    Q_DISABLE_COPY(SettingsModel)
public:
    static SettingsModel &instance();

    bool warpEnabled() const;
    void setWarpEnabled(bool newWarpEnabled);

    bool warpServiceStarted() const;
    void setWarpServiceStarted(bool newWarpServiceStarted);

    bool warpServiceEnabled() const;
    void setWarpServiceEnabled(bool newWarpServiceEnabled);

private:
    SettingsModel();

private:
    bool m_warpEnabled;
    bool m_warpServiceStarted;
    bool m_warpServiceEnabled;

};

#endif // SETTINGSMODEL_H
