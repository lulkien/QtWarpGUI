import QtQuick
import com.warp.custom

Rectangle {
  id: root_btn
  property bool isRounded: false
  property string label: ""
  property int labelSize: 30
  property bool labelBold: false
  property color labelColor: Constants.ALMOST_BLACK
  property int borderWidth: attributes.normalBorderWidth > 2 ? attributes.normalBorderWidth : 3
  property color borderColor: Constants.ALMOST_BLACK
  property color nColor: Constants.LIGHT_GRAY
  property color pColor: Constants.MEDIUM_GRAY

  // signal declare
  signal clicked
  signal pressed
  signal released

  QtObject {
    id: attributes
    property bool isPressed: false
    readonly property int normalBorderWidth: (root_btn.width + root_btn.height) / 100
  }

  width: 100
  height: width / 2
  color: attributes.isPressed ? pColor : nColor
  radius: isRounded ? (height / 5) : 0
  border {
    width: root_btn.borderWidth
    color: root_btn.borderColor
  }

  Text {
    id: btn_text
    anchors.centerIn: parent
    text: root_btn.label
    font {
      pixelSize: root_btn.labelSize
      bold: root_btn.labelBold
    }
    color: root_btn.labelColor
  }

  MouseArea {
    id: mouse
    anchors.fill: parent
    onPressed: {
      attributes.isPressed = true
      root_btn.pressed()
    }
    onReleased: {
      attributes.isPressed = false
      root_btn.released()
    }
    onClicked: {
      root_btn.clicked()
    }
  }
}
