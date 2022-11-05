#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QQmlEngine>

class AppModel final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(int  currentTab      READ currentTab     WRITE setCurrentTab     NOTIFY currentTabChanged)
    Q_PROPERTY(bool warpEnabled     READ warpEnabled    WRITE setWarpEnabled    NOTIFY warpEnabledChanged)
public:
    static AppModel &instance();
    static AppModel *create(QQmlEngine *, QJSEngine *);
    virtual ~AppModel();

    int currentTab() const;
    void setCurrentTab(int newCurrentTab);

    bool warpEnabled() const;
    void setWarpEnabled(bool newWarpEnabled);

private:
    AppModel();

private:
    static AppModel self;
    int m_currentTab;

    bool m_warpEnabled;

signals:

    void currentTabChanged();
    void warpEnabledChanged();
};

#endif // APPMODEL_H
