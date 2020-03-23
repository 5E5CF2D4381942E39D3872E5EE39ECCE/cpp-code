#include <iostream>

#include "gtest/gtest.h"

// #include "SequentialList.h"
// #include "SequentialList2.h"
// #include "SequentialList3.h"
// #include "LinkedList.h"
#include "LinkedList2.h"

// void foo(int t) { std::cout << t << std::endl; }

// test for insert from the head
TEST(Suite1, Test1) {
  const size_t cap = 10;
  LinkedList2<int> s;
  for (LinkedList2<int>::size_type i = 0; i < cap; ++i) s.insert(0, i + 1);
  EXPECT_EQ(cap, s.size());

  size_t n = cap;
  for (int t : s) {
    EXPECT_EQ(t, n);
    --n;
  }

  EXPECT_EQ(n, 0);
}

// test for remove from the head
TEST(Suite1, Test2) {
  const size_t cap = 10;
  LinkedList2<int> s;
  for (LinkedList2<int>::size_type i = 0; i < cap; ++i) s.insert(0, i + 1);
  EXPECT_EQ(cap, s.size());

  size_t n = cap;
  while (n) {
    EXPECT_EQ(n, s.remove(0));
    --n;
  }

  EXPECT_EQ(n, 0);
  EXPECT_EQ(s.size(), 0);
}

// test for remove from the tail
TEST(Suite1, Test3) {
  const size_t cap = 10;
  LinkedList2<int> s;
  for (LinkedList2<int>::size_type i = 0; i < cap; ++i) s.insert(0, i + 1);
  EXPECT_EQ(cap, s.size());

  size_t n = cap;
  size_t v = 1;
  while (n) {
    EXPECT_EQ(v, s.remove(n - 1));
    --n;
    ++v;
  }

  EXPECT_EQ(n, 0);
  EXPECT_EQ(s.size(), 0);
}

// test for remove from the middle
TEST(Suite1, Test4) {
  const size_t cap = 10;
  LinkedList2<int> s;
  for (LinkedList2<int>::size_type i = 0; i < cap; ++i) s.insert(i, i + 1);
  EXPECT_EQ(cap, s.size());

  size_t n = cap;

  EXPECT_EQ(4, s.remove(3));
  EXPECT_EQ(s.size(), n - 1);
}

// test for removeAll
TEST(Suite1, Test5) {
  const size_t cap = 10;
  LinkedList2<int> s;
  for (LinkedList2<int>::size_type i = 0; i < cap / 2; ++i) {
    s.insert(i, i + 1);
    s.insert(i, i + 1);
  }
  EXPECT_EQ(cap, s.size());

  size_t n = cap;
  int i = 1;
  while (!s.isEmpty()) {
    EXPECT_EQ(2, s.removeAll(i));
    ++i;
  }
  EXPECT_EQ(s.size(), 0);
}

// test for contains
TEST(Suite1, Test6) {
  const size_t cap = 10;
  LinkedList2<int> s;
  for (LinkedList2<int>::size_type i = 0; i < cap / 2; ++i) {
    s.insert(i, i + 1);
    s.insert(i, i + 1);
  }
  EXPECT_EQ(cap, s.size());

  size_t n = 0;
  while (n < cap / 2) {
    EXPECT_EQ(2, s.contains(n + 1));
    ++n;
  }

  EXPECT_EQ(n, cap / 2);
}

// test for set & get
TEST(Suite1, Test7) {
  const size_t cap = 10;
  LinkedList2<int> s;
  for (LinkedList2<int>::size_type i = 0; i < cap; ++i) s.insert(i, i + 1);
  EXPECT_EQ(cap, s.size());

  size_t n = 0;

  for (int t : s) {
    EXPECT_EQ(s.get(n), n + 1);
    EXPECT_EQ(s.set(n, (n + 1) * 2), true);
    EXPECT_EQ(s.get(n), (n + 1) * 2);
    ++n;
  }
  EXPECT_EQ(n, cap);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
