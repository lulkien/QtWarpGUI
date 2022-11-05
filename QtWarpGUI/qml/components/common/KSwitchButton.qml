import QtQuick
import com.warp.custom

Rectangle {
  id: root_switch

  // custom properties
  property int switchSize: 100
  property string enableColor: Constants.ORANGE_CLOUDFLARE_L
  property string disableColor: Constants.LIGHT_GRAY
  property string borderColor: Constants.DARK_GRAY
  property bool isEnabled: false
  property bool buttonReady: true

  // readonly properties
  readonly property double sizeRatio: 0.5
  readonly property double borderRatio: 0.02
  readonly property int switchDuration: 150

  width: switchSize
  height: switchSize * sizeRatio
  radius: height / 2

  border.width: switchSize * borderRatio
  border.color: borderColor

  // signal declare
  signal clicked

  color: isEnabled ? enableColor : disableColor

  Rectangle {
    id: switch_core

    // magic ratio
    readonly property double switchMarginRatio: 0.05 // magic number
    readonly property double horizontalOffsetFactor: 0.6 // magic number
    // custom size
    readonly property int margin: root_switch.switchSize * switchMarginRatio
    readonly property int horizontalOffset: switch_core.height * horizontalOffsetFactor

    width: root_switch.height - (2 * margin)
    height: width
    radius: height / 2
    anchors {
      verticalCenter: root_switch.verticalCenter
      horizontalCenter: root_switch.horizontalCenter
      horizontalCenterOffset: root_switch.isEnabled ? switch_core.horizontalOffset : -switch_core.horizontalOffset
    }
    color: Constants.DARK_GRAY

    Behavior on anchors.horizontalCenterOffset {
      NumberAnimation {
        duration: root_switch.switchDuration
      }
    }
  }

  MouseArea {
    enabled: root_switch.buttonReady
    anchors.fill: parent
    onClicked: {
      root_switch.clicked()
    }
  }
}
