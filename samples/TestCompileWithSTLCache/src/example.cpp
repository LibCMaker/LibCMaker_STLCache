/*****************************************************************************
 * Project:  HtmlGrapheas
 * Purpose:  HTML text editor library
 * Author:   NikitaFeodonit, nfeodonit@yandex.com
 *****************************************************************************
 *   Copyright (c) 2017-2019 NikitaFeodonit
 *
 *    This file is part of the HtmlGrapheas project.
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

#include <stlcache/stlcache.hpp>

int main(int argc, char* argv[])
{
  stlcache::cache<int, std::string, stlcache::policy_none> c0(3);
  stlcache::cache<int, std::string, stlcache::policy_adaptive> c1(3);
  stlcache::cache<int, std::string, stlcache::policy_lfu> c2(3);
  stlcache::cache<int, std::string, stlcache::policy_lfuaging<3>> c3(3);
  stlcache::cache<int, std::string, stlcache::policy_lfuagingstar<3>> c4(3);
  stlcache::cache<int, std::string, stlcache::policy_lfustar> c5(3);
  stlcache::cache<int, std::string, stlcache::policy_lru> c6(3);
  stlcache::cache<int, std::string, stlcache::policy_mru> c7(3);

  c6.insert(1, "data1");
  c6.insert(2, "data2");
  c6.insert(3, "data3");
  c6.insert(4, "data4");

  if(c6.check(1)) {
    return 1;  // Must be removed by LRU policy.
  }

  c6.touch(2);

  c6.insert(5, "data5");

  if(c6.check(3)) {
    return 1;  // Must be removed by LRU policy (cause 2 is touched).
  }

  return 0;
}
