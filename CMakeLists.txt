cmake_minimum_required(VERSION 3.28)
project(Fruits LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package(SDL2 REQUIRED COMPONENTS)
find_package(SDL2_image REQUIRED)
#find_package(glfw3 REQUIRED)
#find_package(GLEW REQUIRED)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/source)

include_directories(${SOURCE_DIR})
include_directories(${SOURCE_DIR}/headers)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Add source to this project's executable.
add_executable(Fruits
  source/main.cpp
  source/game.cpp
  source/sprite.cpp
  source/player.cpp
  source/fruit.cpp
  source/background.cpp
)

target_link_libraries(Fruits PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(Fruits PRIVATE SDL2_image::SDL2_image)
#target_link_libraries(Fruits PRIVATE glfw GLEW::GLEW)


file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})