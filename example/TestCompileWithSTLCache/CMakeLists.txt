# ****************************************************************************
#  Project:  LibCMaker_STLCache
#  Purpose:  A CMake build script for STLCache library
#  Author:   NikitaFeodonit, nfeodonit@yandex.com
# ****************************************************************************
#    Copyright (c) 2017-2018 NikitaFeodonit
#
#    This file is part of the LibCMaker_STLCache project.
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published
#    by the Free Software Foundation, either version 3 of the License,
#    or (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#    See the GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program. If not, see <http://www.gnu.org/licenses/>.
# ****************************************************************************

cmake_minimum_required(VERSION 3.2)

project(LibCMaker_STLCache_Compile_Test CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(cmr_PRINT_DEBUG ON)


#-----------------------------------------------------------------------
# Configure to find_package()
#-----------------------------------------------------------------------

# Set CMake's search path for find_*() commands.
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")

if(ANDROID)
  list(APPEND CMAKE_FIND_ROOT_PATH "${CMAKE_INSTALL_PREFIX}")
endif()

# To use our FindSTLCache.cmake.
list(APPEND CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake/LibCMaker_STLCache/cmake"
)


#-----------------------------------------------------------------------
# Set path to LibCMaker root
#-----------------------------------------------------------------------

set(LIBCMAKER_SRC_DIR "${PROJECT_SOURCE_DIR}/cmake/LibCMaker")
# Uncomment it if need functions from LibCMaker
#list(APPEND CMAKE_MODULE_PATH "${LIBCMAKER_SRC_DIR}/cmake/modules")


#-----------------------------------------------------------------------
# Set vars for LibCMaker_STLCache
#-----------------------------------------------------------------------

# Standard CMake vars.
#set(BUILD_SHARED_LIBS ON)

# Vars to lib_cmaker_stlcache().
set(STLCACHE_lib_VERSION  "0.2.20180405")
set(STLCACHE_DOWNLOAD_DIR "${PROJECT_BINARY_DIR}")
set(STLCACHE_UNPACKED_DIR "${PROJECT_BINARY_DIR}")
set(STLCACHE_BUILD_DIR    "${PROJECT_BINARY_DIR}/build_stlcache")

set(COPY_STLCACHE_CMAKE_BUILD_SCRIPTS ON)

set(STLCACHE_DIR "${CMAKE_INSTALL_PREFIX}")
set(ENV{STLCACHE_DIR} "${STLCACHE_DIR}")

# Library specific vars.


#-----------------------------------------------------------------------
# Build and install the STLCache
#-----------------------------------------------------------------------

include(
  ${PROJECT_SOURCE_DIR}/cmake/LibCMaker_STLCache/lib_cmaker_stlcache.cmake)

# Make compile, build and install the library at a config CMake phase.
lib_cmaker_stlcache(
  VERSION           ${STLCACHE_lib_VERSION}
  DOWNLOAD_DIR      ${STLCACHE_DOWNLOAD_DIR}
  UNPACKED_DIR  ${STLCACHE_UNPACKED_DIR}
  BUILD_DIR         ${STLCACHE_BUILD_DIR}
)


#-----------------------------------------------------------------------
# find_package()
#-----------------------------------------------------------------------

# Use newly got library.
find_package(STLCache REQUIRED)


#-----------------------------------------------------------------------
# Link to the library.
#-----------------------------------------------------------------------

# Build test executables.

add_executable(${PROJECT_NAME}
  ${PROJECT_SOURCE_DIR}/example.cpp
)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# STLCache
target_include_directories(${PROJECT_NAME} PRIVATE ${STLCACHE_INCLUDE_DIR})
