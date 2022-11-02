QT += quick

INCLUDEPATH += \
        hdr/controller

SOURCES += \
        src/controller/QML_Handler.cpp \
        src/main.cpp

HEADERS += \
    hdr/controller/QML_Handler.h

qml_file.files += \
        qml/main.qml \
        qml/components/KSystemTray.qml \
        qml/components/KWindow.qml
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
