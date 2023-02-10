project(gui)
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# set_property(SOURCE main.h PROPERTY SKIP_AUTOMOC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_library(LIBIIO_LIBRARIES NAMES iio REQUIRED)
find_library(QWT_LIBRARIES NAMES qwt qwt-qt5 REQUIRED)

add_executable(gui main.cpp main_gui.h gui.h gui.cpp ui/main_gui.ui)
target_link_libraries(gui
        ${LIBIIO_LIBRARIES}
        ${QWT_LIBRARIES}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
