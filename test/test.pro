QT += core
QT -= gui

CONFIG += c++11

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

equals(CI, "enabled") {
        message(CI mode is enabled)
    unix:!macx: INCLUDEPATH += /usr/include/kaldi
    unix:!macx: INCLUDEPATH += /usr/include/atlas
} else {
    INCLUDEPATH += /opt/kaldi/src
    INCLUDEPATH += /opt/kaldi/tools/openfst/include
    INCLUDEPATH += /opt/kaldi/tools/ATLAS_headers/include
    INCLUDEPATH += $$PWD/../../include
}


CONFIG(release, debug|release) {
        unix:!macx: LIBS += -L$$PWD/../../lib
}
CONFIG(debug, debug|release)
{
    unix:!macx: LIBS += -L$$PWD/../../lib_debug
}


SOURCES += main.cpp


