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

include(cmr_get_version_parts)
include(cmr_print_fatal_error)

function(cmr_stlcache_get_download_params
    version
    out_url out_sha out_src_dir_name out_tar_file_name)

  # https://codeload.github.com/akashihi/stlcache/legacy.tar.gz/master
  # https://github.com/akashihi/stlcache/archive/master.zip
  set(lib_base_url "https://github.com/akashihi/stlcache/archive")

  if(version VERSION_EQUAL "0.2.20180405")
    set(lib_sha
      "cbd12bdde57b22fd3f976c4faf30b9c2150acd0096e079c0030eb92bf2650874")
    set(lib_commit
      "b41f7a88e1aeb22b40d2472dfa84f3249076907b")
  endif()

  if(NOT DEFINED lib_sha)
    cmr_print_fatal_error("Library version ${version} is not supported.")
  endif()

  set(lib_src_name "stlcache-${lib_commit}")
  set(lib_tar_file_name "${lib_src_name}.tar.gz")
  set(lib_url "${lib_base_url}/${lib_commit}.tar.gz")

  set(${out_url} "${lib_url}" PARENT_SCOPE)
  set(${out_sha} "${lib_sha}" PARENT_SCOPE)
  set(${out_src_dir_name} "${lib_src_name}" PARENT_SCOPE)
  set(${out_tar_file_name} "${lib_tar_file_name}" PARENT_SCOPE)
endfunction()
