#include "Constants.h"

Constants &Constants::instance()
{
    static Constants _self;
    return _self;
}

Constants::Constants(QObject *parent)
    : QObject{parent}
{

}
