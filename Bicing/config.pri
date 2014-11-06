# Config.pri file version 2.0. Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR = $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            LIBS += -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        } else {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            LIBS += -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }

    }

    CONFIG(release, debug|release) {
        !profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            LIBS += -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

simulator {
    CONFIG(debug, debug|release) {
        !profile {
            INCLUDEPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            DEPENDPATH += $$quote(${QNX_TARGET}/usr/include/qt4/QtNetwork)

            LIBS += -lQtNetwork

            CONFIG += \
                config_pri_assets \
                config_pri_source_group1
        }
    }
}

config_pri_assets {
    OTHER_FILES += \
        $$quote($$BASEDIR/assets/Bubble.qml) \
        $$quote($$BASEDIR/assets/DialogContent.qml) \
        $$quote($$BASEDIR/assets/JsonData.qml) \
        $$quote($$BASEDIR/assets/ListPage.qml) \
        $$quote($$BASEDIR/assets/Map.qml) \
        $$quote($$BASEDIR/assets/MapPage.qml) \
        $$quote($$BASEDIR/assets/PlaceInspector.qml) \
        $$quote($$BASEDIR/assets/StationListItem.qml) \
        $$quote($$BASEDIR/assets/StreetView.qml) \
        $$quote($$BASEDIR/assets/images/black_pin.png) \
        $$quote($$BASEDIR/assets/images/bubble.png) \
        $$quote($$BASEDIR/assets/images/bubble2.png) \
        $$quote($$BASEDIR/assets/images/clearpin.png) \
        $$quote($$BASEDIR/assets/images/compass.png) \
        $$quote($$BASEDIR/assets/images/green_pin.png) \
        $$quote($$BASEDIR/assets/images/ic_favorite.png) \
        $$quote($$BASEDIR/assets/images/ic_favorite_yellow.png) \
        $$quote($$BASEDIR/assets/images/ic_info.png) \
        $$quote($$BASEDIR/assets/images/ic_info_black.png) \
        $$quote($$BASEDIR/assets/images/ic_map.png) \
        $$quote($$BASEDIR/assets/images/ic_nav_to.png) \
        $$quote($$BASEDIR/assets/images/ic_share.png) \
        $$quote($$BASEDIR/assets/images/ic_share_black.png) \
        $$quote($$BASEDIR/assets/images/me.png) \
        $$quote($$BASEDIR/assets/images/nearby.png) \
        $$quote($$BASEDIR/assets/images/pin.png) \
        $$quote($$BASEDIR/assets/images/red_pin.png) \
        $$quote($$BASEDIR/assets/images/url.png) \
        $$quote($$BASEDIR/assets/images/yellow_pin.png) \
        $$quote($$BASEDIR/assets/main.qml)
}

config_pri_source_group1 {
    SOURCES += \
        $$quote($$BASEDIR/src/applicationui.cpp) \
        $$quote($$BASEDIR/src/bicing.cpp) \
        $$quote($$BASEDIR/src/main.cpp)

    HEADERS += \
        $$quote($$BASEDIR/src/applicationui.hpp) \
        $$quote($$BASEDIR/src/bicing.hpp)
}

CONFIG += precompile_header

PRECOMPILED_HEADER = $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES += \
        $$quote($$BASEDIR/../src/*.c) \
        $$quote($$BASEDIR/../src/*.c++) \
        $$quote($$BASEDIR/../src/*.cc) \
        $$quote($$BASEDIR/../src/*.cpp) \
        $$quote($$BASEDIR/../src/*.cxx) \
        $$quote($$BASEDIR/../assets/*.qml) \
        $$quote($$BASEDIR/../assets/*.js) \
        $$quote($$BASEDIR/../assets/*.qs) \
        $$quote($$BASEDIR/../assets/images/*.qml) \
        $$quote($$BASEDIR/../assets/images/*.js) \
        $$quote($$BASEDIR/../assets/images/*.qs)

    HEADERS += \
        $$quote($$BASEDIR/../src/*.h) \
        $$quote($$BASEDIR/../src/*.h++) \
        $$quote($$BASEDIR/../src/*.hh) \
        $$quote($$BASEDIR/../src/*.hpp) \
        $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS = $$quote($${TARGET}.ts)
