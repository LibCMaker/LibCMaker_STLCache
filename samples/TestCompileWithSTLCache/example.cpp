// The code is based on the code from <stlcache-source>/tests/test_lru.cpp


#include <string>

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
    return 1;  // Must be removed by LRU policy
  }

  c6.touch(2);

  c6.insert(5, "data5");

  if(c6.check(3)) {
    return 1;  // Must be removed by LRU policy (cause 2 is touched)
  }

  return 0;
}
