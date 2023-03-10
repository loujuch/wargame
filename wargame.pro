QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AudioManager/audiomanager.cpp \
    PageSystem/Activity/activityview.cpp \
    PageSystem/Activity/activityviewwidget.cpp \
    PageSystem/mypage.cpp \
    PageSystem/pagesystem.cpp \
    PageSystem/selectpage.cpp \
    PageSystem/waitpage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AudioManager/audiomanager.hpp \
    PageSystem/Activity/activityview.hpp \
    PageSystem/Activity/activityviewwidget.hpp \
    PageSystem/mypage.hpp \
    PageSystem/pagesystem.hpp \
    PageSystem/selectpage.hpp \
    PageSystem/waitpage.hpp \
    mainwindow.hpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
