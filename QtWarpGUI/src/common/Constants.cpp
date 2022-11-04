#include "Constants.h"

Constants Constants::self;

Constants &Constants::instance()
{
    return self;
}

Constants *Constants::create(QQmlEngine *, QJSEngine *)
{
    return &self;
}

Constants::Constants()
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}
