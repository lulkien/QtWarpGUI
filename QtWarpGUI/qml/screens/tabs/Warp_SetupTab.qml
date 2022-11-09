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
        isEnabled: AppModel.tempWarpSvcActivated
        onSwitched: {
          AppModel.tempWarpSvcActivated = !AppModel.tempWarpSvcActivated
          QML_Handler.qmlSendRequestEvent(
                WarpEnums.EVT_REQ_ACTIVE_WARP_SERVICE,
                AppModel.tempWarpSvcActivated)
        }
      }
      KCommon.KSwitchSetting {
        id: setting_2
        label: "Enable warp-svc.service"
        guideText: "Autostart warp-svc.service on booting"
        isEnabled: AppModel.tempWarpSvcEnabled
        onSwitched: {
          AppModel.tempWarpSvcEnabled = !AppModel.tempWarpSvcEnabled
          QML_Handler.qmlSendRequestEvent(
                WarpEnums.EVT_REQ_ENABLE_WARP_SERVICE,
                AppModel.tempWarpSvcEnabled)
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
