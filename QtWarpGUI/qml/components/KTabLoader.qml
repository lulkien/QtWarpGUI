import QtQuick
import com.warp.custom

Item {
  id: root_tabloader
  width: Constants.TAB_PAGE_WIDTH
  height: Constants.TAB_PAGE_HEIGHT

  Loader {
    id: loader_1
    visible: QML_Model.currentTab === WarpEnums.HOME
    enabled: visible
    anchors.fill: parent
    source: Constants.HOME_TAB_QML
  }

  Loader {
    id: loader_2
    visible: QML_Model.currentTab === WarpEnums.USER
    enabled: visible
    anchors.fill: parent
    source: Constants.USER_TAB_QML
  }

  Loader {
    id: loader_3
    visible: QML_Model.currentTab === WarpEnums.SETUP
    enabled: visible
    anchors.fill: parent
    source: Constants.SETUP_TAB_QML
  }

  Loader {
    id: loader_4
    visible: QML_Model.currentTab === WarpEnums.INFO
    enabled: visible
    anchors.fill: parent
    source: Constants.INFO_TAB_QML
  }
}
