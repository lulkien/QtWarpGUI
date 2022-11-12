import QtQuick
import Qt.labs.platform
import com.warp.custom

SystemTrayIcon {
  id: root_systray

  // signal declare
  signal reqShowApp

  icon.mask: true
  icon.source: Constants.TRAY_ICO

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
}
