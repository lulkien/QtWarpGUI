import QtQuick
import com.warp.custom

Rectangle {
  id: root_btn
  width: 100
  height: width / 2

  border.width: 1
  border.color: Constants.GRAY

  property alias label: btn_text.text

  // signal declare
  signal clicked

  Text {
    id: btn_text
    text: ""
  }

  MouseArea {
    anchors.fill: parent
    onClicked: root_btn.clicked()
  }
}
