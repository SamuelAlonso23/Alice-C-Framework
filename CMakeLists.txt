cmake_minimum_required(VERSION 2.8)

project(Alice-C-Framework)

if(CMAKE_VERSION VERSION_LESS 3)
    add_definitions(-std=c++14)
else()
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

option(DOCS "Generate documentation" OFF)
option(EXAMPLES "Install code examples" ON)
option(TESTS "Install unit tests" OFF)

if(WIN32)
    set(CMAKE_INSTALL_PREFIX "C:\\Program Files\\Alice")
    set(CMAKE_INSTALL_ALICE ${CMAKE_INSTALL_PREFIX})
    set(CMAKE_INSTALL_EXAMPLES ${CMAKE_INSTALL_ALICE})
else()
    set(CMAKE_INSTALL_PREFIX /usr/include/Alice)
    set(CMAKE_INSTALL_ALICE /usr/share/doc/Alice)
    set(CMAKE_INSTALL_EXAMPLES ${CMAKE_INSTALL_ALICE})
endif()

install(DIRECTORY 
        Basic
        Collections
        Concepts
        Core
        Engine
        IO
        Math
        Memory
        Networking
        System
        Tests
        UI
        DESTINATION ${CMAKE_INSTALL_PREFIX})

install(FILES
        Configuration.hpp
        Database.hpp
        LICENSE
        OS.hpp
        README.md
        DESTINATION ${CMAKE_INSTALL_PREFIX})

if(DOCS)
    find_package(Doxygen)
    add_subdirectory(Docs)
endif()

if(EXAMPLES)
install(DIRECTORY
        Examples
        DESTINATION ${CMAKE_INSTALL_ALICE})
endif()

if(TESTS)
    include(CTest)
    add_subdirectory(Tests)
endif()