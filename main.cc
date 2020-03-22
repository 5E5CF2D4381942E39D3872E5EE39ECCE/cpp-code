#include <iostream>

#include "gtest/gtest.h"

#include "SequentialList.h"
#include "SequentialList2.h"

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

int main(int argc, char **argv) {
  const size_t cap = 10;
  SequentialList<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) {
    if (!s.insert(i + 1))
      std::cout << "error: when insert elem " << i + 1 << std::endl;
  }

  s.traversal();

  SequentialList2<int> s1(cap);
  SequentialList2<int> s2(cap);

  for (decltype(s1.size()) i = 0; i < cap; ++i)
    if (!s1.insert(i + 1))
      std::cout << "error: when insert elem " << i + 1 << std::endl;

  s1.traversal([&s2](int i) { s2.insert(i * 2); });

  s1.traversal(foo);
  std::cout << "---" << std::endl;
  for (int t : s2) foo(t);

  return 0;
}
