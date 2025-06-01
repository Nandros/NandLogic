
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

# Add Raylib
set(RAYLIB_PATH "libs/Raylib")
set(OPENGL_VERSION "3.3")
add_subdirectory(${RAYLIB_PATH})

# add_executable(${TARGET_NAME}
# 	src/Util/ErrorHandler.cpp
# 	src/main.cpp
# )

add_executable(${TARGET_NAME}
	src/test/windowTest.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
	raylib
)

# Add a message to indicate success
message(STATUS "NandLogic project configured successfully!")