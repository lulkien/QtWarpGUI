#ifndef QML_MODEL_H
#define QML_MODEL_H

#include <QObject>
#include <QQmlEngine>

class QML_Model final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(int  currentTab              READ currentTab             WRITE setCurrentTab             NOTIFY currentTabChanged            )
    Q_PROPERTY(bool qmlConnectStatus        READ qmlConnectStatus       WRITE setQmlConnectStatus       NOTIFY qmlConnectStatusChanged      )
    Q_PROPERTY(bool qmlActiveStatus         READ qmlActiveStatus        WRITE setQmlActiveStatus        NOTIFY qmlActiveStatusChanged       )
    Q_PROPERTY(bool qmlEnableStatus         READ qmlEnableStatus        WRITE setQmlEnableStatus        NOTIFY qmlEnableStatusChanged       )
    Q_PROPERTY(bool processingRequest       READ processingRequest      WRITE setProcessingRequest      NOTIFY processingRequestChanged     )

public:
    static QML_Model &instance();
    static QML_Model *create(QQmlEngine *, QJSEngine *);
    virtual ~QML_Model();
    void init();

    int currentTab() const          {   return m_currentTab;        }
    void setCurrentTab(int newCurrentTab);

    // enable check
    bool qmlConnectStatus() const   {   return m_qmlConnectStatus;  }
    void setQmlConnectStatus(bool newTempWarpConnected);

    // start service check
    bool qmlActiveStatus() const    {   return m_qmlActiveStatus;   }
    void setQmlActiveStatus(bool newTempWarpSvcActivated);

    // enable service check
    bool qmlEnableStatus() const    {   return m_qmlEnableStatus;   }
    void setQmlEnableStatus(bool newTempWarpSvcEnabled);

    bool processingRequest() const  {   return m_processingRequest; }
    void setProcessingRequest(bool newProcessingRequest);

private:
    QML_Model();

private:
    int m_currentTab;
    bool m_qmlConnectStatus;
    bool m_qmlActiveStatus;
    bool m_qmlEnableStatus;
    bool m_processingRequest;

signals:
    void currentTabChanged();
    void qmlConnectStatusChanged();
    void qmlActiveStatusChanged();
    void qmlEnableStatusChanged();
    void processingRequestChanged();
    void processingRequestCompleted();
};

#endif // QML_MODEL_H
