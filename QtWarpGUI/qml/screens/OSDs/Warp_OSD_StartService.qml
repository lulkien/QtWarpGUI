import QtQuick
import com.warp.custom
import "../../components/common" as KCommon

Item {
  id: root_ssOSD
  width: Constants.WINDOW_WIDTH
  height: Constants.WINDOW_HEIGHT

  QtObject {
    id: attributes
    readonly property int popupWidth: root_ssOSD.width / 2
    readonly property int popupHeight: root_ssOSD.height / 2
    readonly property int guideTextSize: popupHeight / 15
    property bool hiding: false
  }

  Rectangle {
    id: bg
    anchors.fill: parent
    color: Constants.ALMOST_BLACK
    opacity: 0.5
  }

  MouseArea {
    anchors.fill: parent
  }

  Rectangle {
    id: popup
    visible: !attributes.hiding
    width: attributes.popupWidth
    height: attributes.popupHeight
    radius: height / 10
    anchors.centerIn: parent
    color: Constants.LIGHT_GRAY
    border {
      width: 2
      color: Constants.ALMOST_BLACK
    }

    Text {
      id: guide_text
      width: popup.width
      font {
        pixelSize: attributes.guideTextSize
        bold: true
      }
      textFormat: Text.RichText
      horizontalAlignment: Text.AlignHCenter
      wrapMode: Text.WordWrap
      color: Constants.ALMOST_BLACK
      text: "<br><br>Unable to connect to CloudflareWARP daemon.<br>Maybe the daemon is not running?<br>Start warp-svc.service in Setup."
    }

    KCommon.KButton {
      id: close
      width: popup.width / 3
      height: popup.height / 4
      anchors {
        bottom: popup.bottom
        bottomMargin: height / 2
        left: popup.left
        leftMargin: (popup.width / 2 - width) / 2
      }

      isRounded: true
      labelSize: height / 3
      labelBold: true
      nColor: Constants.RED_OPTION_N
      pColor: Constants.RED_OPTION_P
      label: "Close"
      onClicked: {
        attributes.hiding = true
        QML_Handler.qmlSendRequestEvent(
              WarpEnums.EVT_HIDE_OSD_REQUIRE_START_SVC)
      }
    }

    KCommon.KButton {
      id: ok
      width: popup.width / 3
      height: popup.height / 4
      anchors {
        bottom: popup.bottom
        bottomMargin: height / 2
        right: popup.right
        rightMargin: (popup.width / 2 - width) / 2
      }

      isRounded: true
      labelSize: height / 3
      labelBold: true
      nColor: Constants.GREEN_OPTION_N
      pColor: Constants.GREEN_OPTION_P
      label: "Go to Setting"
      onClicked: {
        attributes.hiding = true
        QML_Handler.qmlSendRequestEvent(WarpEnums.EVT_REQ_GO_TO_SETTING)
      }
    }
  }
}
