#include "OSD_Controller.h"
#include "Constants.h"
#include "Common.h"
#include <QQmlComponent>
#include <QQuickWindow>

#define CHANGE_DURATION     150.0f
#define CHANGE_STEP         30
#define CHANGE_INTERVAL     (CHANGE_DURATION / CHANGE_STEP)
#define ANIMATION_MIN_W     (Constants::instance().WINDOW_WIDTH() / 50)
#define ANIMATION_MIN_H     (Constants::instance().WINDOW_HEIGHT() / 50)

QMap<WarpEnums::OSDIndex, QUrl> OSD_URL_MAP =
{
    {WarpEnums::OSD_REQUIRE_START_SERVICE, Constants::instance().OSD_REQ_START_SVC()},
};

OSD_Controller::OSD_Controller(QQmlApplicationEngine *engine)
    : mEngine               { engine }
    , mCurrentOsdObject     { nullptr }
    , mCurrentOSD           { WarpEnums::OSD_NONE }
{
    LOG;
    initializeOsdController();
}

OSD_Controller::~OSD_Controller()
{
    LOG;
    mCurrentOsdObject = nullptr;
}

bool OSD_Controller::showOSD(const WarpEnums::OSDIndex &osdIdx)
{
    if (this->isShowingOSD())
    {
        LOG << "There is an OSD showing -> destroy OSD:" << mCurrentOSD;
        mCurrentOsdObject->deleteLater();
        mCurrentOsdObject = nullptr;
        mCurrentOSD = WarpEnums::OSD_NONE;
    }
    // init object
    QUrl url = OSD_URL_MAP.value(osdIdx, QUrl(""));
    QQmlComponent osdComponent(mEngine, url);
    mCurrentOsdObject = osdComponent.create();

    if (mCurrentOsdObject != nullptr)
    {
        mCurrentOSD = osdIdx;
        // display object
        LOG << "OSD displayed: " << osdIdx;
        QQuickItem *item = QCAST<QQuickItem *>(mCurrentOsdObject);
        QQmlEngine::setObjectOwnership(mCurrentOsdObject, QQmlEngine::CppOwnership);
        item->setParentItem(mRootItem);
        return true;
    }
    else
    {
        mCurrentOSD = WarpEnums::OSD_NONE;
        LOG << "Show OSD failed: " << osdIdx;
        return false;
    }
}

bool OSD_Controller::hideOSD(const WarpEnums::OSDIndex &osdIdx)
{
    if (!isShowingOSD())
    {
        LOG << "No OSD showing";
        return false;
    }

    if (osdIdx <= WarpEnums::OSD_NONE || WarpEnums::OSD_MAX <= osdIdx)
    {
        LOG << "Invalid OSD Index:" << osdIdx;
        return false;
    }

    if (osdIdx != mCurrentOSD)
    {
        LOG << "OSD [" << osdIdx << "] not currently showed";
        return false;
    }

    LOG << "Delete OSD Index:" << osdIdx;
#ifndef USING_OSD_ANIMATION
    QQuickItem *item = QCAST<QQuickItem *>(mCurrentOsdObject);
    item->setParentItem(nullptr);
    mCurrentOsdObject->deleteLater();
    mCurrentOsdObject = nullptr;
    mCurrentOSD = WarpEnums::OSD_NONE;
#else
    mHideTimer.start();
#endif
    return true;
}

bool OSD_Controller::isShowingOSD() const
{
    return (WarpEnums::OSD_NONE != mCurrentOSD
            && nullptr != mCurrentOsdObject);
}

void OSD_Controller::hideAnimTimeout()
{
    QQuickItem *item = QCAST<QQuickItem *>(mCurrentOsdObject);
    qreal new_width = item->width() - (Constants::instance().WINDOW_WIDTH() / CHANGE_STEP);
    qreal new_height = item->height() - (Constants::instance().WINDOW_HEIGHT() / CHANGE_STEP);
    if (new_width <= ANIMATION_MIN_W
            || new_height <= ANIMATION_MIN_H)
    {
        mHideTimer.stop();
        item->setParentItem(nullptr);
        mCurrentOsdObject->deleteLater();
        mCurrentOsdObject = nullptr;
        mCurrentOSD = WarpEnums::OSD_NONE;
    }
    else
    {
        item->setWidth(new_width);
        item->setHeight(new_height);
    }
}

void OSD_Controller::showAnimTimeout()
{
    QQuickItem *item = QCAST<QQuickItem *>(mCurrentOsdObject);
    qreal new_width = item->width() + (Constants::instance().WINDOW_WIDTH() / CHANGE_STEP);
    qreal new_height = item->height() + (Constants::instance().WINDOW_HEIGHT() / CHANGE_STEP);
    if (new_width >= Constants::instance().WINDOW_WIDTH()
            || new_height <= Constants::instance().WINDOW_HEIGHT())
    {
        mHideTimer.stop();
        item->setWidth(Constants::instance().WINDOW_WIDTH());
        item->setHeight(Constants::instance().WINDOW_HEIGHT());
    }
    else
    {
        item->setWidth(new_width);
        item->setHeight(new_height);
    }
}

void OSD_Controller::initializeOsdController()
{
    LOG;
    QQuickWindow *rootWindow = QCAST<QQuickWindow *>(mEngine->rootObjects()[0]);
    mRootItem = QCAST<QQuickItem *>(rootWindow->contentItem());

    mHideTimer.setInterval(CHANGE_INTERVAL);
    connect(&mHideTimer, &QTimer::timeout, this, &OSD_Controller::hideAnimTimeout);
}
