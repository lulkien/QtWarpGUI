#include "WarpEvents.h"
#include "Common.h"
#include <QQmlEngine>

WarpEvents::WarpEvents()
{

}

WarpEvents::~WarpEvents()
{

}

void WarpEvents::qmlRegister()
{
    qmlRegisterUncreatableType<WarpEvents>(QML_IMPORT,
                                           QML_IMPORT_MAJOR,
                                           QML_IMPORT_MINOR,
                                           "WarpEvents",
                                           "Cannot create an instance from WarpEvents");
}
