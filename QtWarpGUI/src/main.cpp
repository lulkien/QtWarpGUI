#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "AppEngine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AppEngine engine(&app);

    engine.initApplication();
    engine.startApplication();

    return app.exec();
}
