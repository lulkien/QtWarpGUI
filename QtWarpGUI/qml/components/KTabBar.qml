import QtQuick 2.15
import "common" as KCommon
import com.warp.custom

Item {
    id: root_bar
    width: Constants.TAB_SIZE
    height: Constants.WINDOW_HEIGHT

    // custom properties
    property int selectedIndex: 0

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
            model: tabModel
            delegate: KCommon.KTabItem {
                name: Name
                icoSource: Icon
                onTabClicked: {
                    root_bar.selectedIndex = index
                    QML_Handler.qmlDebug("Tab selected: " + root_bar.selectedIndex)
                }
            }
        }
    }

}
