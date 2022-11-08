import QtQuick
import com.warp.custom
import "../../components/common" as KCommon

Rectangle {
  id: root_setuptab
  width: Constants.TAB_PAGE_WIDTH
  height: Constants.TAB_PAGE_HEIGHT
  color: Constants.EVENING_BLACK

  Item {
    id: mainLeft
    width: root_setuptab.width / 2
    height: root_setuptab.height
    Column {
      KCommon.KSwitchSetting {
        id: setting_1
        label: "Start warp-svc.service"
        isEnabled: AppModel.tmpWarpSvcStarted
        buttonReady: !AppModel.warpSvcStarting
        onSwitched: {
          AppModel.tmpWarpSvcStarted = !AppModel.tmpWarpSvcStarted
          QML_Handler.qmlSendRequestEvent(
                AppModel.tmpWarpSvcStarted ? WarpEnums.EVT_REQ_START_WARP_SERVICE : WarpEnums.EVT_REQ_STOP_WARP_SERVICE)
        }
      }
      KCommon.KSwitchSetting {
        id: setting_2
        label: "Enable warp-svc.service"
        guideText: "Autostart warp-svc.service on booting"
        isEnabled: AppModel.tmpWarpSvcEnabled
        buttonReady: !AppModel.warpSvcEnabling
        onSwitched: {
          AppModel.tmpWarpSvcEnabled = !AppModel.tmpWarpSvcEnabled
          QML_Handler.qmlSendRequestEvent(
                AppModel.tmpWarpSvcEnabled ? WarpEnums.EVT_REQ_ENABLE_WARP_SERVICE : WarpEnums.EVT_REQ_DISABLE_WARP_SERVICE)
        }
      }
    }
  }

  Rectangle {
    id: spacer
    anchors {
      right: mainLeft.right
      verticalCenter: root_setuptab.verticalCenter
    }
    width: 1
    height: root_setuptab.height * 0.95
    color: Constants.LIGHT_GRAY
  }
}
