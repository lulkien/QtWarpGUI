import QtQuick
import com.warp.custom

Rectangle {
  id: root_setuptab
  width: Constants.TAB_PAGE_WIDTH
  height: Constants.TAB_PAGE_HEIGHT
  color: Constants.SAD_BLUE

  Text {
    id: text
    anchors.centerIn: parent
    text: "This is Setup Page!!!"
    font.pixelSize: 30
    font.bold: true
  }
}
