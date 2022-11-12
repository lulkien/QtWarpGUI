#include "OSD_Controller.h"
#include "Constants.h"
#include "Common.h"
#include <QQmlComponent>
#include <QQuickWindow>

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
    QQuickWindow *rootWindow = QCAST<QQuickWindow *>(mEngine->rootObjects()[0]);
    mRootItem = QCAST<QQuickItem *>(rootWindow->contentItem());
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
        item->setVisible(true);
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
    QQuickItem *item = QCAST<QQuickItem *>(mCurrentOsdObject);
    item->setParentItem(nullptr);
    mCurrentOsdObject->deleteLater();
    mCurrentOsdObject = nullptr;
    mCurrentOSD = WarpEnums::OSD_NONE;
    return true;

}

bool OSD_Controller::isShowingOSD() const
{
    return (WarpEnums::OSD_NONE != mCurrentOSD
            && nullptr != mCurrentOsdObject);
}
