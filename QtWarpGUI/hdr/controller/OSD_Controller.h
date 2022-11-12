#ifndef OSD_CONTROLLER_H
#define OSD_CONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QUrl>
#include <QMap>
#include "WarpEnums.h"

extern QMap<WarpEnums::OSDIndex, QUrl> OSD_URL_MAP;

class OSD_Controller : public QObject
{
    Q_OBJECT
public:
    OSD_Controller(QQmlApplicationEngine* engine);
    ~OSD_Controller();

    bool showOSD(const WarpEnums::OSDIndex &osdIdx);
    bool hideOSD(const WarpEnums::OSDIndex &osdIdx);
    bool isShowingOSD() const;

private slots:

private:
    QQmlApplicationEngine *mEngine;
    QQuickItem *mRootItem;
    QObject *mCurrentOsdObject;
    WarpEnums::OSDIndex mCurrentOSD;

signals:

};

#endif // OSD_CONTROLLER_H
