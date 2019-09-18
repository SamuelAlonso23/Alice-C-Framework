cmake_minimum_required(VERSION 2.8.0)

project(examples)

if(CMAKE_VERSION VERSION_LESS 3)
    message("Setting version 3")
    add_definitions(-std=c++14)
else()
    message("Setting version")
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

if (WIN32)
    find_path(ALICE_INCLUDE_DIR NAMES Basic/Types.hpp
              HINTS "C:/Program Files/Alice")
else()
    find_path(ALICE_INCLUDE_DIR NAMES Basic/Types.hpp
              HINTS /usr/include/Alice)
endif()

add_subdirectory(Networking)