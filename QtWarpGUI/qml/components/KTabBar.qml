import QtQuick 2.15
import "common" as KCommon

Item {
    id: root_bar
    width: Constants.TAB_SIZE
    height: Constants.WINDOW_HEIGHT

    Rectangle {
        id: spacer
        anchors {
            right: root_bar.right
            verticalCenter: root_bar.verticalCenter
        }
        color: Constants.BLACK
        width: 1
        height: root_bar.height
    }

    Column {
        id: column_layout
        Repeater {
            id: repeater
            model: 5
            delegate: KCommon.KTabItem {
                id: delegate
                MouseArea {
                    anchors.fill: parent
                    onClicked: QML_Handler.qmlDebug("Clicked at " + index)
                }
            }
        }

    }

}
