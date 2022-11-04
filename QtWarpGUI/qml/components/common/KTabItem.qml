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
    signal tabClicked()

    Image {
        id: ico
        width: Constants.TAB_ICO_SIZE
        height: Constants.TAB_ICO_SIZE
        anchors {
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
            horizontalCenterOffset: selected ? (Constants.TAB_SIZE / 2)
                                             : 0
        }
        source: root_tabItem.icoSource
        sourceSize {
            width: Constants.TAB_ICO_SIZE
            height: Constants.TAB_ICO_SIZE
        }

        antialiasing: true
        smooth: true

        Behavior on anchors.horizontalCenterOffset {
            NumberAnimation { duration: 200 }
        }
    }

    Text {
        id: label
        anchors {
            verticalCenter: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
            horizontalCenterOffset: -(Constants.TAB_SIZE / 6)
        }
        opacity: selected ? 1 : 0
        font {
            pixelSize: Constants.TAB_ICO_SIZE * 0.4
            bold: true
        }

        text: name

        Behavior on opacity {
            NumberAnimation { duration: 150 }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: (mouse) => {
                       root_tabItem.tabClicked()
                       QML_Handler.qmlDebug("Item clicked: " + name)
                   }
    }

}
