import QtQuick
import com.warp.custom
import "../../components/common" as KCommon

Rectangle {
  id: root_hometab
  width: Constants.TAB_PAGE_WIDTH
  height: Constants.TAB_PAGE_HEIGHT
  color: Constants.SAD_BLUE

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

  //  Text {
  //    id: text
  //    anchors.centerIn: parent
  //    text: "This is Home Page!!!"
  //    font.pixelSize: 30
  //    font.bold: true
  //  }
}
