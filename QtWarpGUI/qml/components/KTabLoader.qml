import QtQuick
import com.warp.custom

Item {
  id: root_tabloader
  width: Constants.TAB_PAGE_WIDTH
  height: Constants.TAB_PAGE_HEIGHT

  readonly property var qmlTabList: [Constants.HOME_TAB_QML, Constants.USER_TAB_QML, Constants.SETUP_TAB_QML, Constants.INFO_TAB_QML]

  Loader {
    id: loader_1
    anchors.fill: parent
    source: qmlTabList[AppModel.currentTab]
  }

  Loader {
    id: loader_2
    anchors.fill: parent
    source: qmlTabList[AppModel.currentTab]
  }
}
