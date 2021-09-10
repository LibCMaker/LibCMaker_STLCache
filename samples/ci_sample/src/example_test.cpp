/*****************************************************************************
 * Project:  LibCMaker_STLCache
 * Purpose:  A CMake build script for STLCache library
 * Author:   NikitaFeodonit, nfeodonit@yandex.com
 *****************************************************************************
 *   Copyright (c) 2017-2019 NikitaFeodonit
 *
 *    This file is part of the LibCMaker_STLCache project.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published
 *    by the Free Software Foundation, either version 3 of the License,
 *    or (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    See the GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program. If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

// The code is based on the code from <stlcache-source>/tests/test_lru.cpp

#include <string> // NOTE: it is needed for Android NDK build.

#include <stlcache/stlcache.hpp>

#include "gtest/gtest.h"

TEST(Examle, test)
{
  stlcache::cache<int, std::string, stlcache::policy_lru> c6(3);

  c6.insert(1, "data1");
  c6.insert(2, "data2");
  c6.insert(3, "data3");
  c6.insert(4, "data4");

  // Must be removed by LRU policy.
  EXPECT_FALSE(c6.check(1));

  c6.touch(2);

  c6.insert(5, "data5");

  // Must be removed by LRU policy (cause 2 is touched).
  EXPECT_FALSE(c6.check(3));
}
