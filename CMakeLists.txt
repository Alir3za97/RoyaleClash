cmake_minimum_required(VERSION 3.3)
project(RoyaleClash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp.cpp)
add_executable(RoyaleClash ${SOURCE_FILES})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

qt5_use_modules(RoyaleClash Core Widgets Gui Multimedia)
target_link_libraries(RoyaleClash Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)
