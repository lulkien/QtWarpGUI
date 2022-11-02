import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root_window
    maximumHeight: height
    minimumHeight: height
    maximumWidth: width
    minimumWidth: width
    flags: Qt.Window | Qt.WindowMinimizeButtonHint

    // signal declare
    signal systrayVisibleChanged(bool state)

    // signal handler
    onVisibilityChanged: {
        switch (root_window.visibility) {
        case Window.Minimized:
            console.warn("[onVisibilityChanged] Visibility: Window.Hidden >>>>> root_window.hide()")
            root_window.hide()
            break
        case Window.Hidden:
            console.warn("[onVisibilityChanged] Visibility: Window.Hidden >>>>> systrayVisibleChanged(true)")
            systrayVisibleChanged(true)
            break
        default:
            console.warn("[onVisibilityChanged] Visibility:", root_window.visibility, ">>>> systrayVisibleChanged(false)")
            systrayVisibleChanged(false)
            break
        }
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
