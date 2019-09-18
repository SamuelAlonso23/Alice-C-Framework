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
option(PACK "Build installer packages with CPack" OFF)

if(WIN32)
    set(CMAKE_INSTALL_PREFIX "C:\\Program Files\\Alice")
    set(CMAKE_INSTALL_HEADERS ${CMAKE_INSTALL_PREFIX})
    set(CMAKE_INSTALL_SHARE ${CMAKE_INSTALL_PREFIX})
else()
    set(CMAKE_INSTALL_PREFIX /usr)
    set(CMAKE_INSTALL_HEADERS ${CMAKE_INSTALL_PREFIX}/include/Alice)
    set(CMAKE_INSTALL_SHARE ${CMAKE_INSTALL_PREFIX}/share/doc/Alice)
endif()

install(DIRECTORY 
        ${PROJECT_SOURCE_DIR}/Basic
        ${PROJECT_SOURCE_DIR}/Collections
        ${PROJECT_SOURCE_DIR}/Concepts
        ${PROJECT_SOURCE_DIR}/Core
        ${PROJECT_SOURCE_DIR}/Engine
        ${PROJECT_SOURCE_DIR}/IO
        ${PROJECT_SOURCE_DIR}/Math
        ${PROJECT_SOURCE_DIR}/Memory
        ${PROJECT_SOURCE_DIR}/Networking
        ${PROJECT_SOURCE_DIR}/System
        ${PROJECT_SOURCE_DIR}/UI
        DESTINATION ${CMAKE_INSTALL_HEADERS})

install(FILES
        ${PROJECT_SOURCE_DIR}/Configuration.hpp
        ${PROJECT_SOURCE_DIR}/Database.hpp
        ${PROJECT_SOURCE_DIR}/OS.hpp
        DESTINATION ${CMAKE_INSTALL_HEADERS})

if(DOCS)
    find_package(Doxygen)
    add_subdirectory(Docs)
endif()

if(EXAMPLES)
install(DIRECTORY
        Examples
        DESTINATION ${CMAKE_INSTALL_SHARE})
endif()

if(TESTS)
    include(CTest)
    add_subdirectory(Tests)
endif()

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

if (WIN32)
    set(PLATFORM "WINDOWS")
    set(PACKAGE "MSI")
elseif (APPLE)
    set(PACKAGE "APPLE")
    set(PLATFORM "APPLE")
    set(GENERATOR "APPLE")
else ()
    set(PACKAGE "DEB")
    set(PLATFORM "UBUNTU")
    set(GENERATOR "DEBIAN")
endif ()

set(CPACK_GENERATOR ${PACKAGE})

if(PACK)
    set(CPACK_PACKAGE_CONTACT "John R. Patek <jpatek@ubiqsecurity.com>")
    set(CPACK_PACKAGE_DESCRIPTION "Alice C++ Framework")
    set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
    set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
    set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
    set(CPACK_PACKAGE_VENDOR "Iris Technologies")
    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
    include (CPack)
endif()