#include <iostream>

#include "gtest/gtest.h"

// #include "SequentialList.h"
// #include "SequentialList2.h"
// #include "SequentialList3.h"
// #include "LinkedList.h"
// #include "LinkedList2.h"
// #include "Stack.h"
#include "BracketMatching.h"

// void foo(int t) { std::cout << t << std::endl; }

// test for BMatch
TEST(Suite1, Test1) {
  BMatch b_match;
  std::string text = "[](int a) { std::cout << a << std::endl; }";
  std::string text2 = "[](int a) { std::cout << a << std::endl; }}";

  EXPECT_EQ(true, b_match(text));
  EXPECT_EQ(false, b_match(text2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
