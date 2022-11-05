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
    enum GUIEvents {
        EVT_GUI_NONE = 0,

        // enum start here

        // event hide/show
        EVT_GUI_HIDE_WINDOW,
        EVT_GUI_SHOW_WINDOW,
        EVT_GUI_HIDE_SYSTRAY,
        EVT_GUI_SHOW_SYSTRAY,

        // event click
        EVT_GUI_CLICKED_HOME,

        // no enum after this line
        EVT_GUI_MAX = 64,
    };
    Q_ENUM(GUIEvents)

    enum RequestEvent {
        EVT_REQ_NONE = EVT_GUI_MAX + 1,

        EVT_REQ_MAX = 128,
    };
    Q_ENUM(RequestEvent)

public:
    WarpEvents();
    virtual ~WarpEvents();
};

#endif // WARPEVENTS_H
