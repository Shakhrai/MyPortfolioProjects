QT       += core gui widgets sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authomation.cpp \
    dbcreate.cpp \
    editactive.cpp \
    editauthomation.cpp \
    generatereport.cpp \
    main.cpp \
    mainwindow.cpp \
    nonematerialactives.cpp \
    tablepage.cpp

HEADERS += \
    authomation.h \
    dbcreate.h \
    editactive.h \
    editauthomation.h \
    generatereport.h \
    mainwindow.h \
    nonematerialactives.h \
    tablepage.h

FORMS += \
    authomation.ui \
    dbcreate.ui \
    editactive.ui \
    editauthomation.ui \
    generatereport.ui \
    mainwindow.ui \
    nonematerialactives.ui \
    tablepage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc


