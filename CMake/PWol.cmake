cmake_minimum_required(VERSION 3.24)

# Dynamic properties
set(LIB_TYPE STATIC)
if (BUILD_SHARED_LIBS)
    # User wants to build Dynamic Libraries, so change the LIB_TYPE variable to CMake keyword 'SHARED'
    set(LIB_TYPE SHARED)
endif (BUILD_SHARED_LIBS)

# Custom debug macro
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(PWOL_DEBUG)
endif ()

# Include Directory
set("PWOL_INCLUDE_DIR" ${CMAKE_CURRENT_SOURCE_DIR}/Include)
include_directories(${PWOL_INCLUDE_DIR}/)
file(GLOB_RECURSE PWOL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/Include/*)

# Source Directory
aux_source_directory(Source PWOL_SOURCE)
aux_source_directory(Source/Common PWOL_SOURCE)
aux_source_directory(Source/Library PWOL_SOURCE)
aux_source_directory(Source/ConfigParser PWOL_SOURCE)

# Set use folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Set source group
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PWOL_INCLUDE} ${PWOL_SOURCE})

# set build option
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
mark_as_advanced(BUILD_SHARED_LIBS)

# Add final executable
add_executable(${PROJECT_NAME} ${PWOL_INCLUDE} ${PWOL_SOURCE})

if (BUILD_SHARED_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PWOL_SHARED)
endif (BUILD_SHARED_LIBS)

# Target properties
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER PWol)

# Link properties
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog PRIVATE fmt::fmt)

# Set copy config to binary dir
set("PWOL_CONFIG_DIR" ${CMAKE_CURRENT_SOURCE_DIR}/config/)
foreach("copy_file" ${PWOL_CONFIG_DIR})
    file(COPY ${copy_file} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/config)
endforeach()
