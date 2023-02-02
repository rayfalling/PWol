cmake_minimum_required(VERSION 3.24)

project("PWol" LANGUAGES C CXX)

# Set CXX flags
set(CMAKE_CXX_STANDARD 17)

# Set Cmake build output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Binary/Library)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Binary)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Binary)

# Include Directory
set("PWOL_INCLUDE_DIR" ${CMAKE_CURRENT_SOURCE_DIR}/Include)
include_directories(${PWOL_INCLUDE_DIR}/)
file(GLOB_RECURSE PWOL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/Include/*)

# Source Directory
aux_source_directory(Source PWOL_SOURCE)
#aux_source_directory(Source/File PWOL_SOURCE)
#aux_source_directory(Source/Buffer PWOL_SOURCE)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PWOL_INCLUDE} ${PWOL_SOURCE})

# set build option
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
mark_as_advanced(BUILD_SHARED_LIBS)

# Add final executable
add_executable(${PROJECT_NAME} ${PWOL_INCLUDE} ${PWOL_SOURCE})

# Dynamic properties
set(LIB_TYPE STATIC)
if (BUILD_SHARED_LIBS)
    # User wants to build Dynamic Libraries, so change the LIB_TYPE variable to CMake keyword 'SHARED'
    set(LIB_TYPE SHARED)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PWOL_SHARED)
endif (BUILD_SHARED_LIBS)

# Target properties
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER PWol)

