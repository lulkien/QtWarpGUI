#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QQmlEngine>

class AppModel final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(int currentTab READ currentTab WRITE setCurrentTab NOTIFY currentTabChanged)
public:
    static AppModel &instance();
    static AppModel *create(QQmlEngine *, QJSEngine *);
    virtual ~AppModel();

    int currentTab() const;
    void setCurrentTab(int newCurrentTab);

private:
    AppModel();

private:
    static AppModel self;
    int m_currentTab;

signals:

    void currentTabChanged();
};

#endif // APPMODEL_H
