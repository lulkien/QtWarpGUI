import QtQuick 2.15
import "components" as KComponent
import com.warp.custom

KComponent.KWindow {
    id: root
    width: Constants.WINDOW_WIDTH
    height: Constants.WINDOW_HEIGHT
    visible: true
    title: qsTr("QtWarpGUI")

    onNotifySystrayVisibleChanged: (state) => {
                                 tray.visible = state
                             }

    KComponent.KSystemTray {
        id: tray
        onReqShowApp: {
            root.showWindow()
        }
    }

    Rectangle {
        anchors.fill: parent
        color: Constants.GRAY
    }

    KComponent.KTabBar {
        id: tabbar
        anchors {
            left: root.left
            top: root.top
        }
    }
}
