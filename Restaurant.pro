#-------------------------------------------------
#
# Project created by QtCreator 2017-09-04T15:58:43
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Restaurant
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    account_list.cpp \
    database.cpp \
    employee.cpp \
    food.cpp \
    login_dialog.cpp \
    menu_total.cpp \
    register_dialog.cpp \
    administrator_widget.cpp \
    ad_search_dialog.cpp \
    ad_add_dialog.cpp \
    ad_delete_dialog.cpp \
    ad_searchmenu_dialog.cpp \
    table.cpp \
    menu.cpp \
    list.cpp

HEADERS  += widget.h \
    account_list.h \
    database.h \
    employee.h \
    food.h \
    menu_total.h \
    register_dialog.h \
    login_dialog.h \
    administrator_widget.h \
    ad_search_dialog.h \
    ad_add_dialog.h \
    ad_delete_dialog.h \
    ad_searchmenu_dialog.h \
    table.h \
    menu.h \
    list.h

FORMS    += widget.ui \
    login_dialog.ui \
    register_dialog.ui \
    administrator_widget.ui \
    ad_search_dialog.ui \
    ad_add_dialog.ui \
    ad_delete_dialog.ui \
    ad_searchmenu_dialog.ui

RESOURCES += \
    image.qrc
