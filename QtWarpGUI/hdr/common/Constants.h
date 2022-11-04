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
    static Constants self;
    Constants();

    // Start define
    DEFINES(int,    MONITOR_WIDTH,          QGuiApplication::primaryScreen()->geometry().width())
    DEFINES(int,    MONITOR_HEIGHT,         QGuiApplication::primaryScreen()->geometry().height())
    DEFINES(int,    WINDOW_WIDTH,           static_cast<int>(MONITOR_WIDTH() * 0.6f))
    DEFINES(int,    WINDOW_HEIGHT,          static_cast<int>(MONITOR_HEIGHT() * 0.6f))

    // Item size
    DEFINES(int,    TAB_SIZE,               static_cast<int>(WINDOW_HEIGHT() / 6))
    DEFINES(int,    TAB_ICO_SIZE,           static_cast<int>(TAB_SIZE() * 0.4f))

    // Define color
    DEFINES(QColor, ALMOST_BLACK,           "#111111")
    DEFINES(QColor, BLUE_SKY,               "#3282CD")
    DEFINES(QColor, SELECTION_GREEN,        "#39C668")
    DEFINES(QColor, SELECTION_BLUE,         "#408CFA")
    DEFINES(QColor, GRAY,                   "#878787")
    DEFINES(QColor, MAGENTA,                "#C63997")
    DEFINES(QColor, LIGHT_GRAY,             "#CACACA")
    DEFINES(QColor, ORANGE_CLOUDFLARE_D,    "#F38020")
    DEFINES(QColor, ORANGE_CLOUDFLARE_L,    "#FAAE40")
    DEFINES(QColor, ALMOST_WHITE,           "#FAFAFA")
    DEFINES(QColor, INVISIBLE,              "transparent")

    // QML Url
    DEFINES(QUrl,   MAIN_QML,           u"qrc:/QtWarpGUI/qml/main.qml"_qs)

    // Images Url
    DEFINES(QUrl,   TRAY_ICO,           u"qrc:/QtWarpGUI/res/images/cloudflare.svg"_qs)
    DEFINES(QUrl,   HOME_ICO,           u"qrc:/QtWarpGUI/res/images/home.svg"_qs)
    DEFINES(QUrl,   USER_ICO,           u"qrc:/QtWarpGUI/res/images/user.svg"_qs)
    DEFINES(QUrl,   SETUP_ICO,          u"qrc:/QtWarpGUI/res/images/setup.svg"_qs)
    DEFINES(QUrl,   INFO_ICO,           u"qrc:/QtWarpGUI/res/images/info.svg"_qs)
};

#endif // CONSTANTS_H
