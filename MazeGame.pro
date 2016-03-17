TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
LIBS += -LC:/SFML/lib

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include
INCLUDEPATH += C:/Boost/include
DEPENDPATH += C:/Boost/include

INCLUDEPATH += C:/Boost
LIBS += C:/Boost/stage/lib/libboost_filesystem-mgw49-mt-1_59.a
LIBS += C:/Boost/stage/lib/libboost_system-mgw49-mt-d-1_59.a
INCLUDEPATH += C:/Qt/Qt5.5.0/5.5/mingw492_32/lib \
  C:/SFML/lib \
  C:/Qt/Qt5.5.0/5.5/mingw492_32/bin \
  C:/Qt/Qt5.5.0/Tools/mingw492_32/bin \
  C:/Program Files/Common Files/Microsoft Shared/Windows Live \
  C:/Program Files (x86)/Common Files/Microsoft Shared/Windows Live \
  C:/Windows/system32 \
  C:/Windows \
  C:/Windows/System32/Wbem \
  C:/Windows/System32/WindowsPowerShell/v1.0 \
  C:/Program Files (x86)/Intel/OpenCL SDK/2.0/bin/x86 \
  C:/Program Files (x86)/Intel/OpenCL SDK/2.0/bin/x64 \
  C:/Program Files (x86)/Windows Live/Shared \
  C:/Program Files (x86)/MiKTeX 2.9/miktex/bin \
  C:/Qt/Qt5.5.0/Tools/mingw492_32/bin \
  %OPENCV_DIR%/bin \
  C:/Program Files (x86)/CMake/bin \
  C:/SFML/bin

HEADERS +=
