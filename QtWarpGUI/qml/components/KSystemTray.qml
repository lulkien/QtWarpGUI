import QtQuick 2.15
import Qt.labs.platform

SystemTrayIcon {
    id: root_systray

    // signal declare
    signal reqShowApp()

    icon.source: "qrc:/res/images/cloudflare.png"

    // Menu
    menu: Menu {
        id: menu_systray
        MenuItem {
            text: qsTr("QtWarpGUI")
            onTriggered: reqShowApp()
        }
        MenuSeparator {}
        MenuItem {
            text: qsTr("Quit")
            onTriggered: Qt.quit()
        }
    }


    // signal handler
    onActivated: (reason) => {
                     if (SystemTrayIcon.Trigger === reason) {
                         console.warn("SystemTrayIcon.Trigger...")
                     }
                 }

}
