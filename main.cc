#include <iostream>

#include "gtest/gtest.h"

// #include "SequentialList.h"
// #include "SequentialList2.h"
// #include "SequentialList3.h"
// #include "LinkedList.h"
// #include "LinkedList2.h"
#include "Stack.h"

// void foo(int t) { std::cout << t << std::endl; }

// test for push & pop & isEmpty
TEST(Suite1, Test1) {
  Stack<int> a;
  const size_t cap = 10;
  int n = 0;
  while (n < cap) {
    a.push(n + 1);
    ++n;
  }
  EXPECT_EQ(n, cap);

  while (!a.isEmpty()) {
    EXPECT_EQ(n, a.top());
    a.pop();
    --n;
  }
  EXPECT_EQ(n, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
