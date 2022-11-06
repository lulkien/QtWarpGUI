import QtQuick
import com.warp.custom

Item {
  id: root_settingItem

  // custom properties
  property string label: ""
  property string guideText: ""
  property color contentColor: Constants.LIGHT_GRAY
  property bool isEnabled: false
  property bool buttonReady: true

  // readonly properties
  readonly property int textWidth: width * 0.75
  readonly property int textMargin: width * 0.13
  readonly property int fontSize: height * 0.26

  // signal declare
  signal switched

  width: Constants.SETTING_ITEM_WIDTH
  height: Constants.SETTING_ITEM_HEIGHT

  Text {
    id: setting_text
    visible: guideText === ""
    width: root_settingItem.textWidth
    clip: true
    anchors {
      verticalCenter: root_settingItem.verticalCenter
      left: root_settingItem.left
      leftMargin: root_settingItem.textMargin
    }
    font.pixelSize: root_settingItem.fontSize
    text: root_settingItem.label
    color: root_settingItem.contentColor
  }

  Text {
    id: setting_text_2
    visible: !setting_text.visible
    width: root_settingItem.textWidth
    clip: true
    anchors {
      verticalCenter: root_settingItem.verticalCenter
      verticalCenterOffset: -(setting_text_2.height / 2)
      left: root_settingItem.left
      leftMargin: root_settingItem.textMargin
    }
    font: setting_text.font
    text: root_settingItem.label
    color: root_settingItem.contentColor
  }

  Text {
    id: guide_text
    visible: !setting_text.visible
    width: root_settingItem.textWidth
    clip: true
    anchors {
      verticalCenter: root_settingItem.verticalCenter
      verticalCenterOffset: (setting_text_2.height / 2)
      left: root_settingItem.left
      leftMargin: root_settingItem.textMargin
    }
    font.pixelSize: root_settingItem.height / 5
    text: root_settingItem.guideText
    color: root_settingItem.contentColor
  }

  KSwitchButton {
    id: switch_btn
    readonly property int rightMargin: root_settingItem.width * 0.1
    anchors {
      verticalCenter: root_settingItem.verticalCenter
      right: root_settingItem.right
      rightMargin: switch_btn.rightMargin
    }
    isEnabled: root_settingItem.isEnabled
    buttonReady: root_settingItem.buttonReady
    switchSize: 60
    onClicked: {
      root_settingItem.switched()
    }
  }

  Rectangle {
    id: spacer
    width: root_settingItem.width * 0.8
    height: 1
    anchors {
      horizontalCenter: root_settingItem.horizontalCenter
      bottom: root_settingItem.bottom
    }
    color: Constants.LIGHT_GRAY
  }
}
