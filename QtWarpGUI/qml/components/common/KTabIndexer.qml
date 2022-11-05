import QtQuick
import Qt5Compat.GraphicalEffects
import com.warp.custom

Item {
  id: root_indexer
  width: Constants.TAB_SIZE
  height: Constants.TAB_SIZE

  Rectangle {
    id: core_indexer
    readonly property double widthFactor: 1.7 // modify this offset for better looking
    readonly property double heightFactor: .7 // modify this offset for better looking
    width: Constants.TAB_SIZE * core_indexer.widthFactor
    height: Constants.TAB_SIZE * core_indexer.heightFactor
    radius: height / 2
    anchors {
      horizontalCenter: root_indexer.horizontalCenter
      verticalCenter: root_indexer.verticalCenter
    }
    color: Constants.ALMOST_WHITE
  }

  Rectangle {
    id: mask
    readonly property double widthFactor: .95 // modify this offset for better looking
    readonly property double heightFactor: .9 // modify this offset for better looking
    width: core_indexer.width * mask.widthFactor
    height: core_indexer.height * mask.heightFactor
    radius: height / 2
    anchors {
      horizontalCenter: core_indexer.horizontalCenter
      verticalCenter: core_indexer.verticalCenter
    }
  }

  LinearGradient {
    anchors.fill: mask
    source: mask
    start: Qt.point(0, 0)
    end: Qt.point(mask.width, 0)
    gradient: Gradient {
      GradientStop {
        position: 0.0
        color: Constants.SELECTION_BLUE
      }
      GradientStop {
        position: 1.0
        color: Constants.SELECTION_GREEN
      }
    }
  }
}
