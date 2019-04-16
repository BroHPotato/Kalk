TEMPLATE = app
TARGET = Kalk-gui
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    tastierino.cpp \
    view.cpp \
    lcd.cpp

HEADERS += \
    tastierino.h \
    view.h \
    base.h \
    lcd.h
