cmake_minimum_required(VERSION 2.8)

project(Alice-C-Framework)

if(CMAKE_VERSION VERSION_LESS "3")
    add_definitions(-std=c++14)
else()
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

option(BUILD_EXAMPLES "Build code examples" OFF)
option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_EXAMPLES)
add_subdirectory(Examples)
endif()

if(BUILD_TESTS)
    include(CTest)
    add_subdirectory(Tests)
endif()