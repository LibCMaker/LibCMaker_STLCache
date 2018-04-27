// The code is based on the code from <stlcache-source>/tests/test_lru.cpp


#include <string>

#include <stlcache/stlcache.hpp>

int main(int argc, char* argv[])
{
  stlcache::cache<int, std::string, stlcache::policy_lru> c1(3);

  c1.insert(1, "data1");
  c1.insert(2, "data2");
  c1.insert(3, "data3");
  c1.insert(4, "data4");

  if(c1.check(1)) {
    return 1;  // Must be removed by LRU policy
  }

  c1.touch(2);

  c1.insert(5, "data5");

  if(c1.check(3)) {
    return 1;  // Must be removed by LRU policy (cause 2 is touched)
  }

  return 0;
}
