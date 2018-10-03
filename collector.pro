#-------------------------------------------------
#
# Project created by QtCreator 2018-09-26T20:27:16
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = collector
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        router.cpp \
    gui/loadingwidget.cpp \
    gui/mainwidget.cpp \
    logic/game.cpp \
    gui/gamewidget.cpp \
    logic/personal.cpp \
    lib/database.cpp \
    gui/resultwidget.cpp \
    gui/hallwidget.cpp \
    gui/callwidget.cpp \
    gui/lootwidget.cpp \
    gui/lootwidgetopen.cpp \
    gui/lootwidgetcollection.cpp \
    gui/lootonewidget.cpp \
    lib/qlootlabel.cpp \
    gui/widgetstatistics.cpp \
    gui/aboutwidget.cpp \
    lib/qpixlabel.cpp \
    lib/phonevectqscrollarea.cpp

HEADERS += \
        router.h \
    gui/loadingwidget.h \
    gui/mainwidget.h \
    logic/game.h \
    gui/gamewidget.h \
    logic/personal.h \
    lib/database.h \
    lib/structs.h \
    gui/resultwidget.h \
    gui/hallwidget.h \
    gui/callwidget.h \
    gui/lootwidget.h \
    gui/lootwidgetopen.h \
    gui/lootwidgetcollection.h \
    gui/lootonewidget.h \
    lib/qlootlabel.h \
    gui/widgetstatistics.h \
    gui/aboutwidget.h \
    lib/withoutfilterstyle.h \
    lib/qpixlabel.h \
    lib/phonevectqscrollarea.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

FORMS += \
    gui/mainwidget.ui \
    gui/gamewidget.ui \
    gui/resultwidget.ui \
    gui/hallwidget.ui \
    gui/callwidget.ui \
    gui/lootwidget.ui \
    gui/lootwidgetopen.ui \
    gui/lootwidgetcollection.ui \
    gui/lootonewidget.ui \
    gui/widgetstatistics.ui \
    gui/aboutwidget.ui

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/AndroidManifest.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
