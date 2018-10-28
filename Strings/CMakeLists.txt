# CMake Minimum Version
cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

# Build Type
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "-std=c++17")

project (coding_ground)
set (CODING_GROUND_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (CODING_GROUND_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set (CODING_GROUND_VERSION_MAJOR 1)
set (CODING_GROUND_VERSION_MINOR 0)
set (CODING_GROUND_VERSION_PATCH 0)

set (CODING_GROUND_SOURCES csvfile.cpp)
set (PROJECT_NAME coding_ground)

add_executable ( ${PROJECT_NAME} ${CODING_GROUND_SOURCES})
add_compile_options(-Wall -Wextra -Wpedantic -march=native)
