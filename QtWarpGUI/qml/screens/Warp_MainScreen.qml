import QtQuick 2.15
import "../components" as KComponent
import com.warp.custom

Rectangle {
  id: root_main
  width: Constants.WINDOW_WIDTH
  height: Constants.WINDOW_HEIGHT
  color: Constants.GRAY

  KComponent.KTabBar {
    id: menubar
    z: 1
    anchors {
      left: root_main.left
      top: root_main.top
    }
  }

  KComponent.KTabLoader {
    id: tabloader
    z: 0
    anchors {
      right: root_main.right
      top: root_main.top
    }
  }
}
