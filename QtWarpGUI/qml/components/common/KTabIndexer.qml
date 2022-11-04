import QtQuick
import Qt5Compat.GraphicalEffects
import com.warp.custom

Item {
    id: root_indexer
    width: Constants.TAB_SIZE
    height: Constants.TAB_SIZE

    Rectangle {
        id: mask
        width: Constants.TAB_SIZE * 1.7
        height: Constants.TAB_SIZE * 0.7
        radius: height / 2
        anchors {
            horizontalCenter: indexer.horizontalCenter
            verticalCenter: indexer.verticalCenter
        }
    }

    LinearGradient {
        anchors.fill: mask
        source: mask
        start: Qt.point(0, 0)
        end: Qt.point(Constants.TAB_SIZE * 1.7, 0)
        gradient: Gradient {
            GradientStop { position: 0.0; color: Constants.SELECTION_BLUE }
            GradientStop { position: 1.0; color: Constants.SELECTION_GREEN }
        }
    }
}
