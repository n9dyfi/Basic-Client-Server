QT += core network

QT -= gui

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
server.cpp

HEADERS += \
server.h
