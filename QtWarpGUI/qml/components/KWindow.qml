import QtQuick
import QtQuick.Window
import com.warp.custom

Window {
  id: root_window
  maximumHeight: height
  minimumHeight: height
  maximumWidth: width
  minimumWidth: width
  flags: Qt.Window | Qt.WindowMinimizeButtonHint | Qt.WindowCloseButtonHint

  // signal declare
  signal notifySystrayVisibleChanged(bool state)

  KSystemTray {
    id: tray
    onReqShowApp: {
      root_window.showWindow()
    }
  }

  // signal handler
  onVisibilityChanged: {
    switch (root_window.visibility) {
    case Window.Minimized:
      root_window.hideWindow()
      break
    case Window.Hidden:
      root_window.handleSystrayVisible(true)
      break
    default:
      root_window.handleSystrayVisible(false)
      break
    }
  }

  onNotifySystrayVisibleChanged: state => {
                                   tray.visible = state
                                 }

  // Function declare
  function handleSystrayVisible(state) {
    QML_Handler.qmlSendGUIEvent(
          state === true ? WarpEnums.EVT_GUI_SHOW_SYSTRAY : WarpEnums.EVT_GUI_HIDE_SYSTRAY)
    notifySystrayVisibleChanged(state)
  }

  function hideWindow() {
    QML_Handler.qmlSendGUIEvent(WarpEnums.EVT_GUI_HIDE_WINDOW)
    root_window.hide()
  }

  function showWindow() {
    QML_Handler.qmlSendGUIEvent(WarpEnums.EVT_GUI_SHOW_WINDOW)
    root_window.show()
  }
}
