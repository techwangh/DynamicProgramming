TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    IntegerBreak.h \
    BadNeighbors.h \
    CoinChange.h \
    CountingBits.h \
    CountNumberswithUniqueDigits.h \
    ExamplesOnBook_CLRS.h \
    FlowerGarden.h \
    MaximalSquare.h \
    RussiandollEnvelopes.h \
    ZigZag.h

