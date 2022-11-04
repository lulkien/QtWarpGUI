#ifndef WARPEVENTS_H
#define WARPEVENTS_H

#include <QMetaType>
#include <QObject>
#include <QQmlEngine>

class WarpEvents : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Cannot create object from WarpEvents")
public:
    // enums declare
    enum Events {
        EVT_NONE = 0,

        // enum start here

        // event hide/show
        EVT_HIDE_WINDOW,
        EVT_SHOW_WINDOW,
        EVT_HIDE_SYSTRAY,
        EVT_SHOW_SYSTRAY,

        // event click
        EVT_CLICKED_HOME,

        // no enum after this line
        EVT_MAX = 999,
    };
    Q_ENUM(Events)

public:
    WarpEvents();
    virtual ~WarpEvents();
};

#endif // WARPEVENTS_H
