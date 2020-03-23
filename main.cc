#include <iostream>
#include <string>
#include "gtest/gtest.h"

// #include "SequentialList.h"
// #include "SequentialList2.h"
// #include "SequentialList3.h"
// #include "LinkedList.h"
// #include "LinkedList2.h"
// #include "Stack.h"
// #include "BracketMatching.h"
#include "Queue.h"

// void foo(int t) { std::cout << t << std::endl; }

// test for pop & push & isEmpty & size
TEST(Suite1, Test1) {
  Queue<std::string> q;
  const size_t cap = 10;
  int n = cap;
  while (n) {
    q.push(std::to_string(n));
    --n;
  }
  EXPECT_EQ(cap, q.size());
  EXPECT_EQ(0, n);

  n = cap;
  while (!q.isEmpty()) {
    EXPECT_EQ(std::to_string(n), q.top());
    q.pop();
    --n;
  }
  EXPECT_EQ(0, q.size());
  EXPECT_EQ(0, n);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
