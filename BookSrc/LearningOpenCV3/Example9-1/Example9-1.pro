 # OpenCV
INCLUDEPATH += /opt/opencv/install/include
LIBS += $$system(libs_opencv_files)

# ROOT
INCLUDEPATH += /opt/root/install/include
LIBS += $$system(root-config --libs)
LIBS += $$system(root-config --glibs)

SOURCES += \
    main.cpp
