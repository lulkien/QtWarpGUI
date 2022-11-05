import QtQuick
import Qt5Compat.GraphicalEffects
import com.warp.custom

Item {
  id: root_indexer
  width: Constants.TAB_SIZE
  height: Constants.TAB_SIZE

  Rectangle {
    id: core_indexer
    width: Constants.TAB_SIZE * 1.7
    height: Constants.TAB_SIZE * 0.7
    radius: height / 2
    anchors {
      horizontalCenter: root_indexer.horizontalCenter
      verticalCenter: root_indexer.verticalCenter
    }
    color: Constants.ALMOST_WHITE
  }

  Rectangle {
    id: mask
    width: core_indexer.width * 0.95
    height: core_indexer.height * 0.9
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
    end: Qt.point(Constants.TAB_SIZE * 1.7, 0)
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
