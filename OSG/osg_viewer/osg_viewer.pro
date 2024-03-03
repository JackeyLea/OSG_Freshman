TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

OsgDir = D:\Apps\osg-3.6.5

CONFIG(release, debug|release) {
    LIBS += -L$${OsgDir}/lib/ -losgQOpenGL -losgDB -losgViewer \
            -losg -losgUtil -losgGA  -lOpenThreads
} else {
    LIBS += -L$${OsgDir}/lib/ -losgQOpenGLd -losgDBd -losgViewerd \
            -losgd -losgUtild -losgGAd -lOpenThreadsd
}

INCLUDEPATH += $${OsgDir}/include
DEPENDPATH += $${OsgDir}/include

SOURCES += \
        main.cpp
