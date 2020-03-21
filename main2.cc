#include <iostream>
#include "SequentialList2.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  const size_t cap = 10;
  SequentialList2<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) s.insert(i + 1);

  size_t n = 0;
  for (int t : s) {
    EXPECT_EQ(t, n);
    ++n;
  }

  EXPECT_EQ(n, cap);
}

void foo(int t) { std::cout << t << std::endl; }

int main(int, char**) {
  const size_t cap = 10;
  SequentialList2<int> s(cap);
  SequentialList2<int> s2(cap);

  for (decltype(s.size()) i = 0; i < cap; ++i)
    if (!s.insert(i + 1))
      std::cout << "error: when insert elem " << i + 1 << std::endl;

  s.traversal([&s2](int i) { s2.insert(i * 2); });

  s.traversal(foo);
  std::cout << "---" << std::endl;
  for (int t : s2) foo(t);

  return 0;
}
