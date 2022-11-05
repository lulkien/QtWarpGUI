#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>

class AppEngine : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    AppEngine();
};

#endif // APPENGINE_H
