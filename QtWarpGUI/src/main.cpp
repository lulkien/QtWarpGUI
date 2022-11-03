#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "QML_Handler.h"
#include "WarpEvents.h"
#include "Constants.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    WarpEvents::qmlRegister();
    engine.rootContext()->setContextProperty("QML_Handler", &QML_Handler::instance());
    engine.rootContext()->setContextProperty("Constants", &Constants::instance());

    const QUrl url(u"qrc:/QtWarpGUI/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
