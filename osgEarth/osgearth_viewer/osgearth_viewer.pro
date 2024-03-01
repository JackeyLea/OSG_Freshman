TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

OsgDir = D:\Apps\osgEarth-3.5.0

CONFIG(release, debug|release) {
    LIBS += -L$${OsgDir}/lib/ -losgQOpenGL -losgDB -losgViewer \
            -losg -losgUtil -losgGA  -lOpenThreads -losgEarth
} else {
    LIBS += -L$${OsgDir}/lib/ -losgQOpenGLd -losgDBd -losgViewerd \
            -losgd -losgUtild -losgGAd -lOpenThreadsd -losgEarthd
}

INCLUDEPATH += $${OsgDir}/include
DEPENDPATH += $${OsgDir}/include

SOURCES += \
        main.cpp
