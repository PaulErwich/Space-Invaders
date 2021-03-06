cmake_minimum_required(VERSION 3.20)
project(Space_Invaders)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/GameStates/GameStateBase.h src/GameStates/GameStateBase.cpp src/GameStates/GameMenu.cpp src/GameStates/GameMenu.h src/GameStates/GamePlay.cpp src/GameStates/GamePlay.h src/Helper/Helper.cpp src/Helper/Helper.h src/Helper/TextOption.cpp src/Helper/TextOption.h src/Wave.cpp src/Wave.h src/Player/Player.cpp src/Player/Player.h src/Ships/ShipBasic.cpp src/Ships/ShipBasic.h src/Projectile.cpp src/Projectile.h src/Queue.cpp src/Queue.h)
add_executable(Space_Invaders ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (Space_Invaders sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)