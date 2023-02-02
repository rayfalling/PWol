cmake_minimum_required(VERSION 3.24)

# Override Settings
set(SPDLOG_MASTER_PROJECT OFF)

set(SPDLOG_BUILD_ALL OFF)

if (BUILD_SHARED_LIBS)
    set(SPDLOG_BUILD_SHARED ON)
endif (BUILD_SHARED_LIBS)

set(SPDLOG_ENABLE_PCH ON)

if (WIN32)
    set(SPDLOG_WCHAR_SUPPORT ON)
    set(SPDLOG_WCHAR_FILENAMES ON)
else ()
    set(SPDLOG_WCHAR_SUPPORT OFF CACHE BOOL "non supported option" FORCE)
    set(SPDLOG_WCHAR_FILENAMES OFF CACHE BOOL "non supported option" FORCE)
endif ()

set(SPDLOG_FMT_EXTERNAL ON)

set(SPDLOG_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/Library/spdlog/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/Library/spdlog)

set_target_properties(spdlog PROPERTIES FOLDER PWol/Library)
