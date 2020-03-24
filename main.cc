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
// #include "Queue.h"
#include "BinaryTree.h"

// void foo(int t) { std::cout << t << std::endl; }

// test for creat and traversal
TEST(Suite1, Test1) {
  BinaryTree b;
  std::vector<int> v{1, 2, 3, 0, 0, 4, 5, 0, 0, 0, 6, 0, 0};
  BinaryTree::pointer_to_node root = b.root();
  b.create(root, v);

  b.pre_traversal(root, [](int a) { std::cout << a << std::endl; });
  std::cout << "---" << std::endl;
  b.mid_traversal(root, [](int a) { std::cout << a << std::endl; });
  std::cout << "---" << std::endl;
  b.post_traversal(root, [](int a) { std::cout << a << std::endl; });
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
