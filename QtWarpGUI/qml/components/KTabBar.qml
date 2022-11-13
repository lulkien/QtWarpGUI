import QtQuick
import Qt5Compat.GraphicalEffects
import com.warp.custom
import "common" as KCommon

Item {
  id: root_bar
  width: Constants.TAB_SIZE
  height: Constants.WINDOW_HEIGHT

  LinearGradient {
    anchors.fill: parent
    start: Qt.point(0, 0)
    end: Qt.point(0, Constants.WINDOW_HEIGHT)
    gradient: Gradient {
      GradientStop {
        position: 0.0
        color: Constants.ORANGE_CLOUDFLARE_L
      }
      GradientStop {
        position: 1.0
        color: Constants.ORANGE_CLOUDFLARE_D
      }
    }
  }

  Rectangle {
    id: spacer
    anchors {
      horizontalCenter: root_bar.right
      horizontalCenterOffset: width / 2
      verticalCenter: root_bar.verticalCenter
    }
    color: Constants.ALMOST_BLACK
    width: 4
    height: root_bar.height
  }

  KCommon.KTabIndexer {
    id: indexer

    anchors {
      top: parent.top
      topMargin: ((QML_Model.currentTab + 0.5) * Constants.TAB_SIZE) - (indexer.height / 2)
      horizontalCenter: root_bar.horizontalCenter
    }

    Behavior on anchors.topMargin {
      NumberAnimation {
        duration: 200
      }
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
        selected: QML_Model.currentTab === index
        onTabClicked: {
          if (index !== QML_Model.currentTab && !QML_Model.processingRequest) {
            QML_Model.currentTab = index
          }
        }
      }
    }
  }

  KCommon.KButton {
    id: power_button
    width: root_bar.width * 0.7
    height: width
    isRounded: true
    borderColor: Constants.INVISIBLE
    nColor: Constants.INVISIBLE
    pColor: Constants.RED_OPTION_P

    Image {
      width: Constants.TAB_ICO_SIZE
      height: Constants.TAB_ICO_SIZE
      anchors.centerIn: power_button
      antialiasing: true
      smooth: true
      sourceSize.width: width
      sourceSize.height: height
      source: Constants.POWER_ICO
    }

    anchors {
      horizontalCenter: root_bar.horizontalCenter
      bottom: root_bar.bottom
      bottomMargin: (root_bar.width - width) / 2
    }

    onClicked: {
      Qt.quit()
    }
  }
}
