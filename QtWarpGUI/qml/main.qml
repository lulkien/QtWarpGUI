import QtQuick 2.15
import "components" as KComp

KComp.KWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    onSystrayVisibleChanged: (state) => {
                                 tray.visible = state
                             }

    KComp.KSystemTray {
        id: tray
        onReqShowApp: {
            root.show()
        }
    }
}
