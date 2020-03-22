#include <iostream>

#include "gtest/gtest.h"

// #include "SequentialList.h"
// #include "SequentialList2.h"
// #include "SequentialList3.h"
#include "LinkedList.h"

// void foo(int t) { std::cout << t << std::endl; }

// test for insert from the head
TEST(Suite1, Test1) {
  const size_t cap = 10;
  LinkedList<int> s;
  for (LinkedList<int>::size_type i = 0; i < cap; ++i) s.insert(i + 1);

  size_t n = cap;
  for (int t : s) {
    EXPECT_EQ(t, n);
    --n;
  }

  EXPECT_EQ(n, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
