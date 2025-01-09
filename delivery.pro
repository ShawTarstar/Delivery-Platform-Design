QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    1_main.cpp \
    all_order.cpp \
    client_mainp.cpp \
    dish.cpp \
    data.cpp \
    food_show.cpp \
    message_login.cpp \
    order.cpp \
    pay_success.cpp \
    rigister.cpp \
    sever_mainp.cpp \
    shopcar.cpp \
    users.cpp \
    users_business.cpp \
    users_client.cpp \
    users_manager.cpp

HEADERS += \
    all_order.h \
    client_mainp.h \
    data.h \
    food_show.h \
    message_login.h \
    pay_success.h \
    rigister.h \
    sever_mainp.h \
    shopcar.h

FORMS += \
    all_order.ui \
    client_mainp.ui \
    data.ui \
    food_show.ui \
    message_login.ui \
    pay_success.ui \
    rigister.ui \
    sever_mainp.ui \
    shopcar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
