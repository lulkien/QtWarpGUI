import QtQuick 2.15
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
        }
        source: root_tabItem.icoSource
        sourceSize {
            width: Constants.TAB_ICO_SIZE
            height: Constants.TAB_ICO_SIZE
        }

        antialiasing: true
        smooth: true
    }

    MouseArea {
        anchors.fill: parent
        onClicked: (mouse) => {
                       root_tabItem.tabClicked()
                       QML_Handler.qmlDebug("item clicked")
                   }
    }

}
