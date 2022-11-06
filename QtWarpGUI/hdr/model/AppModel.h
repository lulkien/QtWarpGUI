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

    int currentTab() const;
    void setCurrentTab(int newCurrentTab);

    bool tmpWarpEnabled() const;
    void setTmpWarpEnabled(bool newTmpWarpEnabled);

    bool tmpWarpSvcStarted() const;
    void setTmpWarpSvcStarted(bool newTmpWarpSvcStarted);

    bool tmpWarpSvcEnabled() const;
    void setTmpWarpSvcEnabled(bool newTmpWarpSvcEnabled);

    bool warpEnabling() const;
    void setWarpEnabling(bool newWarpEnabling);

    bool warpSvcStarting() const;
    void setWarpSvcStarting(bool newWarpSvcStarting);

    bool warpSvcEnabling() const;
    void setWarpSvcEnabling(bool newWarpSvcEnabling);

private:
    AppModel();

private:
    static AppModel self;
    int m_currentTab;

    bool m_tmpWarpEnabled;
    bool m_warpEnabling;

    bool m_tmpWarpSvcStarted;
    bool m_warpSvcStarting;

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
