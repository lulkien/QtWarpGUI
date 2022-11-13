import QtQuick 2.15
import "components" as KComponent
import "screens" as KScreen
import com.warp.custom

KComponent.KWindow {
  id: root
  width: Constants.WINDOW_WIDTH
  height: Constants.WINDOW_HEIGHT
  visible: true
  title: Translator.STR_MAIN_TITLE

  Loader {
    id: main_loader
    anchors.fill: parent
    source: Constants.MAIN_SCREEN_QML
  }
}
