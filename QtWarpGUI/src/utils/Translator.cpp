#include "Translator.h"
#include "Common.h"
#include "Constants.h"
#include <QFile>
#include <QGuiApplication>
#include <QQmlEngine>

QHash<WarpEnums::Language, QString> LANGUAGE_TABLE =
{
    {   WarpEnums::EN_US    ,   Constants::instance().EN_US_TRANSLATION()   },
};

Translator::Translator()
    : mCurrentLanguage  { WarpEnums::EN_US }
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    updateLanguage();
}

Translator &Translator::instance()
{
    static Translator self;
    return self;
}

Translator *Translator::create(QQmlEngine *, QJSEngine *)
{
    return &instance();
}

WarpEnums::Language Translator::currentLanguage() const
{
    return mCurrentLanguage;
}

void Translator::setLanguage(WarpEnums::Language newLanguage)
{
    if (newLanguage == mCurrentLanguage)
        return;
    mCurrentLanguage = newLanguage;
    updateLanguage();
}

QString Translator::translate(const QString &strID)
{
    return qApp->translate("Translation", strID.toStdString().c_str());
}

bool Translator::updateLanguage()
{
    QString translationFile = LANGUAGE_TABLE.value(mCurrentLanguage, Constants::instance().EN_US_TRANSLATION());
    LOG << "Current language:" << mCurrentLanguage
        << "| Load file:" << translationFile
        << "| isExisted?" << QFile(translationFile).exists();
    if (mTranslator.load(translationFile))
    {
        qApp->installTranslator(&mTranslator);
        emit languageChanged();
        return true;
    }
    else
    {
        LOG << "Cannot load file:" << translationFile;
        return false;
    }
}
