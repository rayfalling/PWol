cmake_minimum_required(VERSION 3.24)

project("PWol" LANGUAGES C CXX)

# Set CXX flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Set Cmake build output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Binary/Library)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Binary)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Binary)

# Include Third Library
include(${CMAKE_SOURCE_DIR}/CMake/PWol.cmake)

# Include Third Library
include(${CMAKE_SOURCE_DIR}/CMake/3rdLibrary.cmake)

