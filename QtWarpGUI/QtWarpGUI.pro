QT += quick

INCLUDEPATH += \
        hdr/controller \
        hdr/common \
        hdr/utils

SOURCES += \
        src/common/Constants.cpp \
        src/common/WarpEvents.cpp \
        src/controller/QML_Handler.cpp \
        src/main.cpp

HEADERS += \
    hdr/common/Common.h \
    hdr/common/Constants.h \
    hdr/common/WarpEvents.h \
    hdr/controller/QML_Handler.h

qml_file.files += \
        qml/main.qml \
        qml/components/KSystemTray.qml \
        qml/components/KWindow.qml \
        qml/components/KTabBar.qml \
        qml/components/common/KTabItem.qml
qml_file.prefix = /$${TARGET}

img_files.files += \
        res/images/cloudflare.png
img_files.prefix = /$${TARGET}

RESOURCES += qml_file img_files

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

