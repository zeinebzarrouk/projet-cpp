QT       += core sql gui
QT       += network
QT       += printsupport
QT       += multimedia
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alarme.cpp \
    arduino.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    articles.cpp \
    emissions.cpp \
    module_employe.cpp \
    module_mission.cpp \
    popup.cpp \
    smtp.cpp  \
    evenements.cpp  \
    participants.cpp  \
    fonction.cpp \
    mailing.cpp \
    personnel.cpp \
    qcustomplot/qcustomplot.cpp \
    mission.cpp  \
    journaliste.cpp  \
    connection.cpp \
    module_evenement.cpp  \
    module_article.cpp

HEADERS += \
    alarme.h \
    arduino.h \
    mainwindow.h \
    menu.h \
    articles.h \
    module_employe.h \
    module_mission.h \
    participants.h \
    evenements.h \
    fonction.h \
    mailing.h \
    personnel.h \
    popup.h \
    qcustomplot/qcustomplot.h \
    mission.h  \
    journaliste.h  \
    emissions.h \
    participants.cpp \
    smtp.h  \
    connection.h \
    module_evenement.h  \
    module_article.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    module_employe.ui \
    module_evenement.ui \
    mailing.ui \
    module_article.ui \
    module_mission.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc
