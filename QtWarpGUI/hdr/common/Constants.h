#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QObject>
#include <QColor>
#include <QString>

#define DEFINES(_type, _name, _value) \
    Q_PROPERTY(_type _name READ _name CONSTANT) \
    public: _type _name() { return _value; }

class Constants final : public QObject
{
    Q_OBJECT
public:
    static Constants &instance();

private:
    explicit Constants(QObject *parent = nullptr);

    // Start define
    DEFINES(int,    WINDOW_WIDTH,   640)
    DEFINES(int,    WINDOW_HEIGHT,  480)

    DEFINES(int,    TAB_SIZE,       80)

    // Define color
    DEFINES(QColor, BLACK,          "#111111")

};

#endif // CONSTANTS_H
