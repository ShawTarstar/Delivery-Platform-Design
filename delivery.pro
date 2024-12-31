QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    1_main.cpp \
    client_mainp.cpp \
    dish.cpp \
    data.cpp \
    message_login.cpp \
    order.cpp \
    rigister.cpp \
    sever_mainp.cpp \
    users.cpp \
    users_business.cpp \
    users_client.cpp \
    users_manager.cpp

HEADERS += \
    client_mainp.h \
    data.h \
    message_login.h \
    rigister.h \
    sever_mainp.h

FORMS += \
    client_mainp.ui \
    data.ui \
    message_login.ui \
    rigister.ui \
    sever_mainp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
