# CMake For NandLogic project using RayLib

cmake_minimum_required(VERSION 3.15)

# Project name and version
set(PROJECT_NAME "NandLogic")
set(TARGET_NAME "${PROJECT_NAME}")
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
	raylib
	GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
	GIT_TAG "5.5"
	GIT_PROGRESS TRUE
)

set_target_properties(game PROPERTIES ENABLE_EXPORTS on)

FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} ${ui_sources})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib  game)

add_executable(${TARGET_NAME} WIN32
	main.cpp
)

# Add a message to indicate success
message(STATUS "NandLogic project configured successfully!")