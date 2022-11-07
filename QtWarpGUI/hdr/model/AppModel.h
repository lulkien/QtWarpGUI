#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QQmlEngine>

class AppModel final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(int  currentTab          READ currentTab         WRITE setCurrentTab         NOTIFY currentTabChanged)
    Q_PROPERTY(bool tmpWarpEnabled      READ tmpWarpEnabled     WRITE setTmpWarpEnabled     NOTIFY tmpWarpEnabledChanged)
    Q_PROPERTY(bool warpEnabling        READ warpEnabling       WRITE setWarpEnabling       NOTIFY warpEnablingChanged)
    Q_PROPERTY(bool tmpWarpSvcStarted   READ tmpWarpSvcStarted  WRITE setTmpWarpSvcStarted  NOTIFY tmpWarpSvcStartedChanged)
    Q_PROPERTY(bool warpSvcStarting     READ warpSvcStarting    WRITE setWarpSvcStarting    NOTIFY warpSvcStartingChanged)
    Q_PROPERTY(bool tmpWarpSvcEnabled   READ tmpWarpSvcEnabled  WRITE setTmpWarpSvcEnabled  NOTIFY tmpWarpSvcEnabledChanged)
    Q_PROPERTY(bool warpSvcEnabling     READ warpSvcEnabling    WRITE setWarpSvcEnabling    NOTIFY warpSvcEnablingChanged)
public:
    static AppModel &instance();
    static AppModel *create(QQmlEngine *, QJSEngine *);
    virtual ~AppModel();

    int currentTab() const
    {
        return m_currentTab;
    }
    void setCurrentTab(int newCurrentTab);

    // enable check
    bool warpEnabled() const       {    return m_warpEnabled;       }
    bool tmpWarpEnabled() const    {    return m_tmpWarpEnabled;    }
    bool warpEnabling() const      {   return m_warpEnabling;       }
    void setWarpEnabled(bool newWarpEnabled);
    void setTmpWarpEnabled(bool newTmpWarpEnabled);
    void setWarpEnabling(bool newWarpEnabling);

    // start service check
    bool warpSvcStarted() const    {    return m_warpSvcStarted;    }
    bool tmpWarpSvcStarted() const {    return m_tmpWarpSvcStarted; }
    bool warpSvcStarting() const   {    return m_warpSvcStarting;   }
    void setWarpSvcStarted(bool newWarpSvcStarted);
    void setTmpWarpSvcStarted(bool newTmpWarpSvcStarted);
    void setWarpSvcStarting(bool newWarpSvcStarting);

    // enable service check
    bool warpSvcEnabled() const    {    return m_warpSvcEnabled;    }
    bool tmpWarpSvcEnabled() const {    return m_tmpWarpSvcEnabled; }
    bool warpSvcEnabling() const   {    return m_warpSvcEnabling;   }
    void setWarpSvcEnabled(bool newWarpSvcEnabled);
    void setTmpWarpSvcEnabled(bool newTmpWarpSvcEnabled);
    void setWarpSvcEnabling(bool newWarpSvcEnabling);

private:
    AppModel();

private:
    static AppModel self;
    int m_currentTab;

    bool m_warpEnabled;
    bool m_tmpWarpEnabled;
    bool m_warpEnabling;

    bool m_warpSvcStarted;
    bool m_tmpWarpSvcStarted;
    bool m_warpSvcStarting;

    bool m_warpSvcEnabled;
    bool m_tmpWarpSvcEnabled;
    bool m_warpSvcEnabling;

signals:
    void currentTabChanged();
    void tmpWarpEnabledChanged();
    void tmpWarpSvcStartedChanged();
    void tmpWarpSvcEnabledChanged();
    void warpEnablingChanged();
    void warpSvcStartingChanged();
    void warpSvcEnablingChanged();
};

#endif // APPMODEL_H
