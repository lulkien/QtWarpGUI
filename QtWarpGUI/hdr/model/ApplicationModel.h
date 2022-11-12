#ifndef APPLICATIONMODEL_H
#define APPLICATIONMODEL_H

#include <QtGlobal>

class ApplicationModel final
{
    Q_DISABLE_COPY(ApplicationModel)
public:
    static ApplicationModel &instance();

    bool warpConnected() const;
    void setWarpConnected(bool newWarpConnected);

    bool warpSvcActivated() const;
    void setWarpSvcActivated(bool newWarpSvcActivated);

    bool warpSvcEnabled() const;
    void setWarpSvcEnabled(bool newWarpSvcEnabled);

private:
    ApplicationModel();

private:
    bool m_warpConnected;
    bool m_warpSvcActivated;
    bool m_warpSvcEnabled;

};

#endif // APPLICATIONMODEL_H
