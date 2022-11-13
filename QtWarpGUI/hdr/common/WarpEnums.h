#ifndef WARPENUMS_H
#define WARPENUMS_H

#include <QMetaType>
#include <QObject>
#include <QQmlEngine>

class WarpEnums : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("Cannot create object from WarpEnums")
public:
    // enums declare
    enum GUIEvents {
        EVT_GUI_NONE = 0,

        EVT_GUI_HIDE_WINDOW,
        EVT_GUI_SHOW_WINDOW,
        EVT_GUI_HIDE_SYSTRAY,
        EVT_GUI_SHOW_SYSTRAY,

        EVT_GUI_CLICKED_HOME,

        // no enum after this line
        EVT_GUI_MAX = 127,
    };
    Q_ENUM(GUIEvents)

    enum RequestEvent {
        EVT_REQ_NONE = EVT_GUI_MAX + 1,

        EVT_REQ_WARP_CONNECT,
        EVT_REQ_ACTIVE_WARP_SERVICE,
        EVT_REQ_ENABLE_WARP_SERVICE,

        EVT_REQ_GO_TO_SETTING,
        EVT_HIDE_OSD_REQUIRE_START_SVC,

        EVT_REQ_MAX = EVT_REQ_NONE + 127,
    };
    Q_ENUM(RequestEvent)

    enum Tab {
        HOME = 0,
        USER,
        SETUP,
        INFO,
    };
    Q_ENUM(Tab)

    enum OSDIndex {
        OSD_NONE = 0,

        OSD_REQUIRE_START_SERVICE,
        OSD_TEST,

        OSD_MAX,
    };
    Q_ENUM(OSDIndex)

    enum Language {
        EN_US = 0,
    };
    Q_ENUM(Language)

    enum AccountType {
        FREE = 0,
        UNLIMITED,
    };
    Q_ENUM(AccountType)

public:
    WarpEnums() {}
    virtual ~WarpEnums() {};
};

#endif // WARPENUMS_H
