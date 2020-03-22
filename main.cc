#include <iostream>

#include "gtest/gtest.h"

// #include "SequentialList.h"
// #include "SequentialList2.h"
#include "SequentialList3.h"

// void foo(int t) { std::cout << t << std::endl; }

// test for insert from the head
TEST(Suite1, Test1) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) s.insert(0, i + 1);

  size_t n = cap;
  for (int t : s) {
    EXPECT_EQ(t, n);
    --n;
  }

  EXPECT_EQ(n, 0);
}

// test for insert from the tail
TEST(Suite1, Test2) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) s.insert(i, i + 1);

  size_t n = 0;
  for (int t : s) {
    EXPECT_EQ(t, n + 1);
    ++n;
  }

  EXPECT_EQ(n, cap);
}

// test for remove from the head
TEST(Suite1, Test3) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) s.insert(i, i + 1);

  size_t n = 0;
  while (!s.isEmpty()) {
    EXPECT_EQ(s.remove(0), n + 1);
    ++n;
  }

  EXPECT_EQ(n, cap);
}

// test for remove from the tail
TEST(Suite1, Test4) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) s.insert(i, i + 1);

  size_t n = cap;
  while (!s.isEmpty()) {
    EXPECT_EQ(s.remove(n - 1), n);
    --n;
  }

  EXPECT_EQ(n, 0);
}

// test for removeAll
TEST(Suite1, Test5) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap / 2; ++i) {
    s.insert(i, i + 1);
    s.insert(i, i + 1);
  }

  // s.traversal([](int a) { std::cout << a << std::endl; });

  size_t v = 2;
  size_t n = 0;
  while (!s.isEmpty()) {
    EXPECT_EQ(v, s.removeAll(n + 1));
    ++n;
  }
  EXPECT_EQ(n, cap / 2);
}

// test for contains
TEST(Suite1, Test6) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap / 2; ++i) {
    s.insert(i, i + 1);
    s.insert(i, i + 1);
  }

  size_t v = 2;
  size_t n = 0;
  for (int t : s) {
    EXPECT_EQ(v, s.contains(t));
    ++n;
  }
  EXPECT_EQ(n, cap);
}

// test for get
TEST(Suite1, Test7) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) {
    s.insert(i, i + 1);
  }

  size_t n = 0;
  for (int t : s) {
    EXPECT_EQ(n + 1, s.get(n));
    ++n;
  }
  EXPECT_EQ(n, cap);
}

// test for set
TEST(Suite1, Test8) {
  const size_t cap = 10;
  SequentialList3<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) {
    s.insert(i, i + 1);
  }

  size_t n = 0;
  for (int t : s) {
    EXPECT_EQ(n + 1, s.get(n));
    EXPECT_TRUE(s.set(n, (n + 1) * 2));
    EXPECT_EQ((n + 1) * 2, s.get(n));

    ++n;
  }

  EXPECT_EQ(n, cap);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
