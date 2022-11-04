#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Constants.h"
#include "TabListModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    TabListModel model;

    engine.rootContext()->setContextProperty("tabModel", &model);

    const QUrl url = Constants::instance().MAIN_QML();
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
