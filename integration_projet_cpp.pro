QT       += core sql gui
QT       += network
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    articles.cpp \
    emissions.cpp \
    smtp.cpp  \
    evenements.cpp  \
    participants.cpp  \
    connection.cpp \
    module_article.cpp

HEADERS += \
    mainwindow.h \
    menu.h \
    articles.h \
    participants.h \
    evenements.h \
    emissions.h \
    participants.cpp \
    smtp.h  \
    connection.h \
    module_article.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    module_article.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
