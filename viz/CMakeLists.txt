rock_find_qt4(OPTIONAL QtXml)
rock_find_qt5(OPTIONAL Xml)

if(ROCK_QT_VERSION_4)
    rock_vizkit_plugin(octomap-viz
        OcTreeVisualization.cpp
        DEPS envire_octomap
        DEPS_CMAKE QGLViewer octovis
        MOC OcTreeVisualization.hpp
        HEADERS OcTreeVisualization.hpp)
endif(ROCK_QT_VERSION_4)

if(ROCK_QT_VERSION_5)
    rock_vizkit_plugin_qt5(octomap-viz
        OcTreeVisualization.cpp
        DEPS envire_octomap
        DEPS_CMAKE QGLViewer octovis
        MOC5 OcTreeVisualization.hpp
        HEADERS OcTreeVisualization.hpp)
endif(ROCK_QT_VERSION_5)
