#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QString>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QTranslator>
#include <QHash>
#include "WarpEnums.h"

#define STR_TRANSLATE(str) \
    Q_PROPERTY(QString str READ str NOTIFY languageChanged) \
    public: QString str() { return QCoreApplication::translate("Translation", #str); }
#define STR_NO_TRANSLATE(str) \
    public: QString str() { return #str; }
#define QML_TRANSLATION_IMPL \
    Q_PROPERTY(QString qmlLanguageUpdate READ qmlLanguageUpdate NOTIFY languageChanged) \
    public: QString qmlLanguageUpdate() { return u""_qs; }

class Translator final : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    QML_TRANSLATION_IMPL
public:
    static Translator &instance();
    static Translator *create(QQmlEngine *, QJSEngine *);

    WarpEnums::Language currentLanguage() const;
    void setLanguage(WarpEnums::Language newLanguage);

public slots:
    QString translate(const QString& strID);

private:
    Translator();
    bool updateLanguage();

private:
    WarpEnums::Language mCurrentLanguage;
    QTranslator mTranslator;

signals:
    void languageChanged();

private:    // DEFINE STRING HERE
    STR_TRANSLATE(STR_MAIN_TITLE)
    STR_TRANSLATE(STR_LABEL_CANCEL)
    STR_TRANSLATE(STR_LABEL_GO_TO_SETUP)
    STR_TRANSLATE(STR_START_WARP_SVC)
    STR_TRANSLATE(STR_ENABLE_WARP_SVC)
    STR_TRANSLATE(STR_ENABLE_WARP_SVC_GUIDE)
    STR_TRANSLATE(STR_POPUP_REQ_START_SERVICE_LINE_1)
    STR_TRANSLATE(STR_POPUP_REQ_START_SERVICE_LINE_2)
    STR_TRANSLATE(STR_POPUP_REQ_START_SERVICE_LINE_3)
    STR_NO_TRANSLATE(STR_TAB_HOME)
    STR_NO_TRANSLATE(STR_TAB_USER)
    STR_NO_TRANSLATE(STR_TAB_SETTING)
    STR_NO_TRANSLATE(STR_TAB_INFO)

};

#endif // TRANSLATOR_H
