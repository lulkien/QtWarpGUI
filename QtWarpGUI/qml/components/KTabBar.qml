import QtQuick
import Qt5Compat.GraphicalEffects
import com.warp.custom
import "common" as KCommon

Item {
    id: root_bar
    width: Constants.TAB_SIZE
    height: Constants.WINDOW_HEIGHT

    // custom properties
    property int selectedIndex: 0

    LinearGradient {
        anchors.fill: parent
        start: Qt.point(0, 0)
        end: Qt.point(0, Constants.WINDOW_HEIGHT)
        gradient: Gradient {
            GradientStop { position: 0.0; color: Constants.ORANGE_CLOUDFLARE_L }
            GradientStop { position: 1.0; color: Constants.ORANGE_CLOUDFLARE_D }
        }
    }

    Rectangle {
        id: spacer
        anchors {
            horizontalCenter: root_bar.right
            verticalCenter: root_bar.verticalCenter
        }
        color: Constants.ALMOST_BLACK
        width: 6
        height: root_bar.height
    }

    KCommon.KTabIndexer {
        id: indexer

        anchors {
            top: parent.top
            topMargin: ((root_bar.selectedIndex + 0.5) * Constants.TAB_SIZE) - (indexer.height / 2)
            horizontalCenter: root_bar.horizontalCenter
        }

        Behavior on anchors.topMargin {
            NumberAnimation { duration: 200 }
        }
    }

    Column {
        id: column_layout
        Repeater {
            id: repeater
            model: tabModel
            delegate: KCommon.KTabItem {
                name: Name
                icoSource: Icon
                selected: root_bar.selectedIndex === index
                onTabClicked: {
                    root_bar.selectedIndex = index
                    QML_Handler.qmlDebug("Tab selected: " + root_bar.selectedIndex)
                }
            }
        }
    }

}
