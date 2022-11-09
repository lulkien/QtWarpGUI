#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QQmlEngine>

class AppModel final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(int  currentTab              READ currentTab             WRITE setCurrentTab             NOTIFY currentTabChanged            )
    Q_PROPERTY(bool tempWarpConnected       READ tempWarpConnected      WRITE setTempWarpConnected      NOTIFY tempWarpConnectedChanged     )
    Q_PROPERTY(bool tempWarpSvcActivated    READ tempWarpSvcActivated   WRITE setTempWarpSvcActivated   NOTIFY tempWarpSvcActivatedChanged  )
    Q_PROPERTY(bool tempWarpSvcEnabled      READ tempWarpSvcEnabled     WRITE setTempWarpSvcEnabled     NOTIFY tempWarpSvcEnabledChanged    )
    Q_PROPERTY(bool processingRequest       READ processingRequest      WRITE setProcessingRequest      NOTIFY processingRequestChanged     )

public:
    static AppModel &instance();
    static AppModel *create(QQmlEngine *, QJSEngine *);
    virtual ~AppModel();
    void init();

    int currentTab() const          {   return m_currentTab;    }
    void setCurrentTab(int newCurrentTab);

    // enable check
    bool tempWarpConnected() const  {   return m_tempWarpConnected;     }
    void setTempWarpConnected(bool newTempWarpConnected);

    // start service check
    bool tempWarpSvcActivated() const   {   return m_tempWarpSvcActivated;  }
    void setTempWarpSvcActivated(bool newTempWarpSvcActivated);

    // enable service check
    bool tempWarpSvcEnabled() const {   return m_tempWarpSvcEnabled;    }
    void setTempWarpSvcEnabled(bool newTempWarpSvcEnabled);

    bool processingRequest() const  {   return m_processingRequest;     }
    void setProcessingRequest(bool newProcessingRequest);

private:
    AppModel();

private:
    static AppModel self;
    int m_currentTab;
    bool m_tempWarpConnected;
    bool m_tempWarpSvcActivated;
    bool m_tempWarpSvcEnabled;
    bool m_processingRequest;

signals:
    void currentTabChanged();
    void tempWarpConnectedChanged();
    void tempWarpSvcActivatedChanged();
    void tempWarpSvcEnabledChanged();
    void processingRequestChanged();
    void processingRequestCompleted();
};

#endif // APPMODEL_H
