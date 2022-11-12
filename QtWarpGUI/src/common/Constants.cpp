#include "Constants.h"

Constants &Constants::instance()
{
    static Constants self;
    return self;
}

Constants *Constants::create(QQmlEngine *, QJSEngine *)
{
    return &instance();
}

Constants::Constants()
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}
