#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QObject>
#include <QColor>
#include <QString>
#include <QUrl>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QScreen>

#ifndef DEFINE_MACROS
#define DEFINE_MACROS
#define DEFINES(_type, _name, _value)           \
    Q_PROPERTY(_type _name READ _name CONSTANT) \
    public: _type _name() { return _value; }
#endif

class Constants final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    static Constants &instance();
    static Constants *create(QQmlEngine *, QJSEngine *);

private:
    Constants();

    // Start define
    // Window size
    DEFINES(qreal,      MONITOR_WIDTH,          QGuiApplication::primaryScreen()->geometry().width())
    DEFINES(qreal,      MONITOR_HEIGHT,         QGuiApplication::primaryScreen()->geometry().height())
    DEFINES(qreal,      WINDOW_WIDTH,           static_cast<int>(MONITOR_WIDTH() * 0.5f))
    DEFINES(qreal,      WINDOW_HEIGHT,          static_cast<int>(MONITOR_HEIGHT() * 0.5f))

    // Item size
    DEFINES(qreal,      TAB_SIZE,               static_cast<int>(WINDOW_HEIGHT() / 6))
    DEFINES(qreal,      TAB_ICO_SIZE,           static_cast<int>(TAB_SIZE() * 0.4f))
    DEFINES(qreal,      TAB_PAGE_WIDTH,         WINDOW_WIDTH() - TAB_SIZE())
    DEFINES(qreal,      TAB_PAGE_HEIGHT,        WINDOW_HEIGHT())
    DEFINES(qreal,      SETTING_ITEM_WIDTH,     static_cast<int>(TAB_PAGE_WIDTH() * 0.5f))
    DEFINES(qreal,      SETTING_ITEM_HEIGHT,    static_cast<int>(TAB_PAGE_HEIGHT() / 8))

    // Define color
    DEFINES(QColor,     ALMOST_BLACK,           "#111111")
    DEFINES(QColor,     EVENING_BLACK,          "#2E2F30")
    DEFINES(QColor,     DARK_GRAY,              "#393939")
    DEFINES(QColor,     BLUE_SKY,               "#3282CD")
    DEFINES(QColor,     SELECTION_GREEN,        "#39C668")
    DEFINES(QColor,     SELECTION_BLUE,         "#408CFA")
    DEFINES(QColor,     SAD_BLUE,               "#5C84AA")
    DEFINES(QColor,     GRAY,                   "#878787")
    DEFINES(QColor,     MEDIUM_GRAY,            "#888888")
    DEFINES(QColor,     PALE_BLUE,              "#9ACFD6")
    DEFINES(QColor,     BRIGHT_DAY,             "#C3CD98")
    DEFINES(QColor,     MAGENTA,                "#C63997")
    DEFINES(QColor,     LIGHT_GRAY,             "#CACACA")
    DEFINES(QColor,     ORANGE_CLOUDFLARE_D,    "#F38020")
    DEFINES(QColor,     ORANGE_CLOUDFLARE_L,    "#FAAE40")
    DEFINES(QColor,     ALMOST_WHITE,           "#FAFAFA")
    DEFINES(QColor,     KINDA_RED,              "#FF6161")
    DEFINES(QColor,     RED_OPTION_N,           "#FF6969")
    DEFINES(QColor,     RED_OPTION_P,           "#DE4040")
    DEFINES(QColor,     GREEN_OPTION_N,         "#64EC7D")
    DEFINES(QColor,     GREEN_OPTION_P,         "#42BC58")
    DEFINES(QColor,     INVISIBLE,              "transparent")

    // QML Url
    DEFINES(QUrl,       MAIN_QML,               u"qrc:/QtWarpGUI/qml/main.qml"_qs)
    DEFINES(QUrl,       MAIN_SCREEN_QML,        u"qrc:/QtWarpGUI/qml/screens/Warp_MainScreen.qml"_qs)
    DEFINES(QUrl,       HOME_TAB_QML,           u"qrc:/QtWarpGUI/qml/screens/tabs/Warp_HomeTab.qml"_qs)
    DEFINES(QUrl,       INFO_TAB_QML,           u"qrc:/QtWarpGUI/qml/screens/tabs/Warp_InfoTab.qml"_qs)
    DEFINES(QUrl,       SETUP_TAB_QML,          u"qrc:/QtWarpGUI/qml/screens/tabs/Warp_SetupTab.qml"_qs)
    DEFINES(QUrl,       USER_TAB_QML,           u"qrc:/QtWarpGUI/qml/screens/tabs/Warp_UserTab.qml"_qs)

    // for OSDs
    DEFINES(QUrl,       OSD_REQ_START_SVC,      u"qrc:/QtWarpGUI/qml/screens/OSDs/Warp_OSD_StartService.qml"_qs)

    // Images Url
    DEFINES(QUrl,       HOME_ICO,               u"qrc:/QtWarpGUI/res/images/home.svg"_qs)
    DEFINES(QUrl,       INFO_ICO,               u"qrc:/QtWarpGUI/res/images/info.svg"_qs)
    DEFINES(QUrl,       POWER_ICO,              u"qrc:/QtWarpGUI/res/images/power.svg"_qs)
    DEFINES(QUrl,       SETUP_ICO,              u"qrc:/QtWarpGUI/res/images/setup.svg"_qs)
    DEFINES(QUrl,       TRAY_ICO,               u"qrc:/QtWarpGUI/res/images/cloudflare.svg"_qs)
    DEFINES(QUrl,       USER_ICO,               u"qrc:/QtWarpGUI/res/images/user.svg"_qs)

    // Translation Url
    DEFINES(QString,    EN_US_TRANSLATION,      u":/QtWarpGUI/res/translations/qm/en_US.qm"_qs)
};

#endif // CONSTANTS_H
