# cmake_minimum_required(VERSION 3.15)

# project(NandLogic LANGUAGES C CXX VERSION 5.1)

# add_executable(NandLogic main.cpp)

# find_package(RmlUi CONFIG REQUIRED)
# target_link_libraries(NandLogic PRIVATE RmlUi::RmlUi)

cmake_minimum_required(VERSION 3.15)

# Project name and version
set(PROJECT_NAME "NandLogic")
set(TARGET_NAME "${RMLUI_SAMPLE_PREFIX}${PROJECT_NAME}")
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include RmlUi library
# find_package(RmlUi CONFIG REQUIRED)


set(RMLUI_SHELL ON) # To enable backends
set(RMLUI_IS_ROOT_PROJECT ON) # Because RmlUi is include via add_subdirectory
add_subdirectory(RmlUi)

include_directories(RmlUi/Include)
include_directories(RmlUi)

# Add your source files
# set(SOURCES main.cpp)
# add_executable(NandLogic ${SOURCES})


add_executable(${TARGET_NAME} WIN32
	main.cpp
)

set_common_target_options(${TARGET_NAME})

target_link_libraries(${TARGET_NAME} PRIVATE rmlui_shell)

install_sample_target(${TARGET_NAME})

# Add a message to indicate success
message(STATUS "RmlUi project configured successfully!")