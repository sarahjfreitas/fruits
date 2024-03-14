cmake_minimum_required(VERSION 3.28)
project(Fruits LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL2 REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/source)

include_directories(${SOURCE_DIR})
include_directories(${SOURCE_DIR}/headers)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(Fruits
  source/main.cpp
  source/game.cpp
  source/sprite.cpp
  source/player.cpp
  source/fruit.cpp
)

target_link_libraries(Fruits PRIVATE SDL2::SDL2)
target_link_libraries(Fruits PRIVATE SDL2_image::SDL2_image)
