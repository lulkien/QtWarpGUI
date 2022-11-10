import QtQuick
import com.warp.custom

Rectangle {
  id: root_switch

  // custom properties
  property int switchSize: 100
  property color enableColor: Constants.ORANGE_CLOUDFLARE_L
  property color disableColor: Constants.LIGHT_GRAY
  property color buttonProcessingColor: Constants.KINDA_RED
  property color buttonDisableColor: Constants.MEDIUM_GRAY
  property string borderColor: Constants.DARK_GRAY
  property bool isEnabled: false
  property bool buttonReady: true

  // private properties
  QtObject {
    id: attributes
    property bool switched: false
    readonly property double sizeRatio: 0.5
    readonly property double borderRatio: 0.02
    readonly property int switchDuration: 150
    readonly property bool buttonAllowMouse: (!QML_Model.processingRequest
                                              && root_switch.buttonReady)
    readonly property bool buttonDisabled: (!buttonAllowMouse && !switched)
    readonly property bool buttonProcessing: (!buttonAllowMouse && switched)
  }

  width: switchSize
  height: switchSize * attributes.sizeRatio
  radius: height / 2
  //  color: attributes.buttonDisabled ? buttonDisableColor : (attributes.buttonProcessing ? buttonProcessingColor : (isEnabled ? enableColor : disableColor))
  color: attributes.buttonProcessing ? buttonProcessingColor : (isEnabled ? enableColor : disableColor)

  border.width: switchSize * attributes.borderRatio
  border.color: borderColor

  // signal declare
  signal clicked

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
        duration: attributes.switchDuration
      }
    }
  }

  MouseArea {
    visible: attributes.buttonAllowMouse
    enabled: visible
    anchors.fill: parent
    onClicked: {
      attributes.switched = true
      root_switch.clicked()
    }
  }

  Connections {
    target: QML_Model
    function onProcessingRequestCompleted() {
      attributes.switched = false
    }
  }
}
