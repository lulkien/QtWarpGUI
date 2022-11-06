import QtQuick
import com.warp.custom

Rectangle {
  id: root_tabItem

  // default properties
  width: Constants.TAB_SIZE
  height: Constants.TAB_SIZE
  color: Constants.INVISIBLE

  // new properties
  property string name: ""
  property string icoSource: ""
  property bool selected: false

  // signal declare
  signal tabClicked

  Image {
    id: ico
    // readonlt properties
    readonly property int selectedHorizontalOffset: (Constants.TAB_SIZE / 2)

    width: Constants.TAB_ICO_SIZE
    height: Constants.TAB_ICO_SIZE
    anchors {
      verticalCenter: root_tabItem.verticalCenter
      horizontalCenter: root_tabItem.horizontalCenter
      horizontalCenterOffset: root_tabItem.selected ? ico.selectedHorizontalOffset : 0
    }
    antialiasing: true
    source: root_tabItem.icoSource
    sourceSize {
      width: Constants.TAB_ICO_SIZE
      height: Constants.TAB_ICO_SIZE
    }
    Behavior on anchors.horizontalCenterOffset {
      NumberAnimation {
        duration: 200
      }
    }
  }

  Text {
    id: label

    // readonly properties
    readonly property int leftOffset: (Constants.TAB_SIZE * 0.15)
    readonly property int fontSize: Constants.TAB_ICO_SIZE * 0.45

    anchors {
      verticalCenter: root_tabItem.verticalCenter
      left: root_tabItem.left
      leftMargin: label.leftOffset
    }
    opacity: root_tabItem.selected ? 1 : 0
    font {
      pixelSize: label.fontSize
      bold: true
    }

    text: name

    Behavior on opacity {
      NumberAnimation {
        duration: 200
      }
    }
  }

  MouseArea {
    anchors.fill: parent
    onClicked: mouse => {
                 root_tabItem.tabClicked()
                 QML_Handler.qmlDebug("Item clicked: " + name)
               }
  }
}
