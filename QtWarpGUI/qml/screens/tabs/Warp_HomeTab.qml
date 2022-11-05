import QtQuick
import com.warp.custom
import "../../components/common" as KCommon

Rectangle {
  id: root_hometab
  width: Constants.TAB_PAGE_WIDTH
  height: Constants.TAB_PAGE_HEIGHT
  color: Constants.EVENING_BLACK

  KCommon.KSwitchButton {
    id: switchBtn
    anchors.centerIn: parent
    switchSize: 120
    isEnabled: AppModel.warpEnabled
    enableColor: Constants.SELECTION_GREEN
    onClicked: {
      QML_Handler.qmlDebug("Enable button clicked")
      AppModel.warpEnabled = !AppModel.warpEnabled
    }
  }
}
