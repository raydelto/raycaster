cmake_minimum_required(VERSION 3.5)
project(Raycaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/SDL3" CACHE PATH "Path to SDL3 library")

find_package(SDL3 REQUIRED)

include_directories(${SDL3_INCLUDE_DIRS})

add_executable(raycaster src/main.cpp src/player.cpp src/map.cpp src/renderer.cpp)

target_link_libraries(raycaster ${SDL3_LIBRARIES})
