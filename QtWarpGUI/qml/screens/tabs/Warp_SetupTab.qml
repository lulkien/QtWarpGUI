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
        label: Translator.STR_START_WARP_SVC
        isEnabled: QML_Model.qmlActiveStatus
        onSwitched: {
          QML_Handler.qmlSendRequestEvent(
                WarpEnums.EVT_REQ_ACTIVE_WARP_SERVICE,
                !QML_Model.qmlActiveStatus)
        }
      }
      KCommon.KSwitchSetting {
        id: setting_2
        label: Translator.STR_ENABLE_WARP_SVC
        guideText: Translator.STR_ENABLE_WARP_SVC_GUIDE
        isEnabled: QML_Model.qmlEnableStatus
        onSwitched: {
          QML_Handler.qmlSendRequestEvent(
                WarpEnums.EVT_REQ_ENABLE_WARP_SERVICE,
                !QML_Model.qmlEnableStatus)
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
