QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT +=printsupport
#QT += core gui multimedia

QT += multimedia
#multimediawidgets

#QT += widgets multimedia

QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    evenements.cpp \
    main.cpp \
    mainwindow.cpp \
    participants.cpp

HEADERS += \
    connexion.h \
    evenements.h \
    mainwindow.h \
    participants.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    test_son.qrc

QMAKE_CXXFLAGS += -std=gnu++11








//TARGET = test_son

//TEMPLATE = app










