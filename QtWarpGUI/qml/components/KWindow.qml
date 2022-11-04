import QtQuick 2.15
import QtQuick.Window 2.15
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

    // signal handler
    onVisibilityChanged: {
        switch (root_window.visibility) {
        case Window.Minimized:
            QML_Handler.qmlDebug("[onVisibilityChanged] Visibility: Window.Minimized >>>>> root_window.hide()")
            root_window.hideWindow()
            break
        case Window.Hidden:
            QML_Handler.qmlDebug("[onVisibilityChanged] Visibility: Window.Hidden >>>>> systrayVisibleChanged(true)")
            root_window.handleSystrayVisible(true)
            break
        default:
            QML_Handler.qmlDebug("[onVisibilityChanged] Visibility: " + root_window.visibility + " >>>> systrayVisibleChanged(false)")
            root_window.handleSystrayVisible(false)
            break
        }
    }

    function handleSystrayVisible(state) {
        QML_Handler.qmlSendEvent(state === true ? WarpEvents.EVT_SHOW_SYSTRAY : WarpEvents.EVT_HIDE_SYSTRAY)
        notifySystrayVisibleChanged(state)
    }

    function hideWindow() {
        QML_Handler.qmlSendEvent(WarpEvents.EVT_HIDE_WINDOW)
        root_window.hide()
    }

    function showWindow() {
        QML_Handler.qmlSendEvent(WarpEvents.EVT_SHOW_WINDOW)
        root_window.show()
    }

//    onClosing: (close) => {
//                   switch (root_window.visibility) {
//                   case Window.Hidden:
//                       console.warn("[onClosing] Visibility: Window.Hidden >>>>> close.accepted = true")
//                       close.accepted = true
//                       break
//                   default:
//                       console.warn("[onClosing] Visibility:", root_window.visibility, ">>>>> close.accepted = false")
//                       console.warn("[onClosing] root_window.hide()")
//                       close.accepted = false
//                       root_window.hide()
//                       break
//                   }
//               }
}
