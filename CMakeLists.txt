cmake_minimum_required(VERSION 2.8)

project(json11)

if(CMAKE_VERSION VERSION_LESS "3")
    add_definitions(-std=c++11)
else()
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    include(CTest)
    add_subdirectory(Tests)
endif()