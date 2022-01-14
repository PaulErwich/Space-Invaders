cmake_minimum_required(VERSION 3.20)
project(Space_Invaders)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
add_executable(Space_Invaders Src/main.cpp)

target_link_libraries (Space_Invaders sfml-graphics sfml-window sfml-system sfml-network sfml-audio)