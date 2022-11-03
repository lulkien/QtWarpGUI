#ifndef WARPEVENTS_H
#define WARPEVENTS_H

#include <QMetaType>
#include <QObject>

class WarpEvents : public QObject
{
    Q_OBJECT
public:
    // enums declare
    enum Events {
        EVT_NONE = 0,

        // enum start here
        EVT_HIDE_WINDOW,
        EVT_SHOW_WINDOW,
        EVT_HIDE_SYSTRAY,
        EVT_SHOW_SYSTRAY,

        // no enum after this line
        EVT_MAX = 999,
    };
    Q_ENUM(Events)

public:
    WarpEvents();
    virtual ~WarpEvents();
    static void qmlRegister();
};

#endif // WARPEVENTS_H
