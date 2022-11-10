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

  // private properties
  QtObject {
    id: attributes
    readonly property int textWidth: root_settingItem.width * 0.75
    readonly property int textMargin: root_settingItem.width * 0.13
    readonly property int fontSize: root_settingItem.height * 0.26
    readonly property int fontSizeGuide: root_settingItem.height * 0.2
  }

  // signal declare
  signal switched

  width: Constants.SETTING_ITEM_WIDTH
  height: Constants.SETTING_ITEM_HEIGHT

  Text {
    id: setting_text
    visible: guideText === ""
    width: attributes.textWidth
    clip: true
    anchors {
      verticalCenter: root_settingItem.verticalCenter
      left: root_settingItem.left
      leftMargin: attributes.textMargin
    }
    font.pixelSize: attributes.fontSize
    text: root_settingItem.label
    color: root_settingItem.contentColor
  }

  Text {
    id: setting_text_2
    visible: !setting_text.visible
    width: attributes.textWidth
    clip: true
    anchors {
      verticalCenter: root_settingItem.verticalCenter
      verticalCenterOffset: -(setting_text_2.height / 2)
      left: root_settingItem.left
      leftMargin: attributes.textMargin
    }
    font: setting_text.font
    text: root_settingItem.label
    color: root_settingItem.contentColor
  }

  Text {
    id: guide_text
    visible: !setting_text.visible
    width: attributes.textWidth
    clip: true
    anchors {
      verticalCenter: root_settingItem.verticalCenter
      verticalCenterOffset: (setting_text_2.height / 2)
      left: root_settingItem.left
      leftMargin: attributes.textMargin
    }
    font.pixelSize: attributes.fontSizeGuide
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
