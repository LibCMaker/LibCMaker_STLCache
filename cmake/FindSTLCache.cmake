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

# - Find STLCache library
# Find the STLCache includes
# This module defines
#  STLCACHE_INCLUDE_DIR, where to find stlcache.hpp
#  STLCACHE_FOUND, If false, do not try to use STLCache.

find_path(STLCACHE_INCLUDE_DIR
  NAMES stlcache/stlcache.hpp
  HINTS
    ENV STLCACHE_DIR
  PATH_SUFFIXES
    include
  NO_DEFAULT_PATH
)

# Handle the QUIETLY and REQUIRED arguments and set STLCACHE_FOUND to TRUE
# if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(STLCACHE DEFAULT_MSG STLCACHE_INCLUDE_DIR)

mark_as_advanced(STLCACHE_INCLUDE_DIR)
