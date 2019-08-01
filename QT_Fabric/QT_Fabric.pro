#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T13:47:48
#
#-------------------------------------------------

QT       += concurrent widgets
QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_Fabric
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    detect_indent_fft.cpp \
    detect_mura_defects_blur.cpp \
    camerathread.cpp \
    textspeech.cpp

HEADERS  += mainwindow.h \
    detect_indent_fft.h \
    detect_mura_defects_blur.h \
    camerathread.h \
    textspeech.h

FORMS    += mainwindow.ui


INCLUDEPATH += D:\QTProgram\QT_Fabric\include\
            += D:\QTProgram\QT_Fabric\include\halconcpp\
            += D:\QTProgram\QT_Fabric\QT_Fabric\speech\Include\
            += D:\QTProgram\QT_Fabric\Includes

LIBS += D:\QTProgram\QT_Fabric\lib\x64-win64\halconcpp.lib
LIBS += D:\QTProgram\QT_Fabric\lib\x64-win64\halcon.lib
LIBS += D:\QTProgram\QT_Fabric\QT_Fabric\MVCAMSDK_X64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\CyCamLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\CyComLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\CyDispExLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\CyEngineLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\CyImgLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\CyMediumLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\CyUtilsLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\EbSetupLib64.lib
LIBS += D:\QTProgram\QT_Fabric\Libraries\PtPublic64.lib


LIBS += D:\QTProgram\QT_Fabric\QT_Fabric\speech\Lib\i386\sapi.lib
LIBS += -Ldll -lws2_32

CONFIG += qaxcontainer
