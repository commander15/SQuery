cmake_minimum_required(VERSION 3.20)

project(SQuery VERSION 1.0.0 LANGUAGES CXX)

#Output dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#Scripts
include(cmake/utils.cmake)
include(cmake/options.cmake)

#Qt
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)

set(QT_COMPONENTS Core)
if (SQuery_BUILD_TESTS)
    list(APPEND QT_COMPONENTS Test)
endif()

find_package(Qt5 REQUIRED COMPONENTS ${QT_COMPONENTS})

#GTest
if (SQuery_BUILD_TESTS)
    find_package(GTest REQUIRED)
endif()

#Subdirs
add_subdirectory(src)

if (SQuery_BUILD_TESTS)
    add_subdirectory(tests)
endif()
