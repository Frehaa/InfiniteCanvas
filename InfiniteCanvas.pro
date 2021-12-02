QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Drawables/circle.cpp \
    Drawables/drawableconfig.cpp \
    Drawables/path.cpp \
    Tools/circletool.cpp \
    Tools/linetool.cpp \
    Tools/pentool.cpp \
    colorbackground.cpp \
    gridlines.cpp \
    main.cpp \
    mainwindow.cpp \
    rulelines.cpp

HEADERS += \
    Drawables/circle.h \
    Drawables/drawable.h \
    Drawables/drawableconfig.h \
    Drawables/path.h \
    Tools/circletool.h \
    Tools/linetool.h \
    Tools/pentool.h \
    Tools/tool.h \
    colorbackground.h \
    gridlines.h \
    mainwindow.h \
    rulelines.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    InfiniteCanvas_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
