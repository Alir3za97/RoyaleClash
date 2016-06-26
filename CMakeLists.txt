cmake_minimum_required(VERSION 3.3)
project(RoyaleClash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp src/obj/cards/card.h src/obj/cards/card.cpp src/obj/towers/tower.h src/obj/towers/tower.cpp src/obj/towers/king.h src/obj/towers/king.cpp src/obj/towers/crown.h src/obj/towers/crown.cpp)
add_executable(RoyaleClash ${SOURCE_FILES})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

qt5_use_modules(RoyaleClash Core Widgets Gui Multimedia)
target_link_libraries(RoyaleClash Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)
