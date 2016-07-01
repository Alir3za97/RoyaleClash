cmake_minimum_required(VERSION 3.3)
project(RoyaleClash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp src/obj/cards/card.h src/obj/cards/card.cpp src/obj/towers/tower.h
        src/obj/towers/tower.cpp src/obj/towers/king.h src/obj/towers/king.cpp src/obj/towers/crown.h
        src/obj/towers/crown.cpp src/obj/cards/troops/troop.h src/obj/cards/troops/troop.cpp
        src/obj/cards/spells/spell.h src/obj/cards/spells/spell.cpp src/obj/cards/buildings/building.h
        src/obj/cards/buildings/building.cpp src/obj/cards/troops/lava_hound.h src/obj/cards/troops/lava_hound.cpp
        src/obj/cards/troops/balloon.h src/obj/cards/troops/balloon.cpp src/obj/cards/troops/minion_horde.h
        src/obj/cards/troops/minion_horde.cpp src/obj/cards/troops/ice_wizard.h src/obj/cards/troops/ice_wizard.cpp
        src/obj/cards/troops/dark_prince.h src/obj/cards/troops/dark_prince.cpp src/obj/cards/troops/miner.h
        src/obj/cards/troops/miner.cpp src/obj/cards/troops/valkyrie.h src/obj/cards/buildings/spawning_building.h
        src/obj/cards/buildings/spawning_building.cpp src/obj/cards/buildings/tower_building.h
        src/obj/cards/buildings/tower_building.cpp)
add_executable(RoyaleClash ${SOURCE_FILES})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)

qt5_use_modules(RoyaleClash Core Widgets Gui Multimedia)
target_link_libraries(RoyaleClash Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)
