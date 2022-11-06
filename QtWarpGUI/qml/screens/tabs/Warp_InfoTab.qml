import QtQuick
import com.warp.custom

Rectangle {
  id: root_infotab
  width: Constants.TAB_PAGE_WIDTH
  height: Constants.TAB_PAGE_HEIGHT
  color: Constants.EVENING_BLACK

  Text {
    id: text
    anchors.centerIn: parent
    text: "This is Info Page!!!"
    font.pixelSize: 30
    font.bold: true
    color: Constants.LIGHT_GRAY
  }
}
