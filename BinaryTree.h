#ifndef DATA_STRUCTURE_BINARYTREE_H_
#define DATA_STRUCTURE_BINARYTREE_H_

#include <functional>
#include <vector>

class BinaryTree {
  struct Node;

 public:
  using size_type = unsigned long;
  using value_type = int;
  using node = Node;
  using pointer_to_node = node *;

  BinaryTree() = default;

  void create(pointer_to_node &tree, std::vector<int> &v) {
    int c = v.at(0);
    // std::cin >> c;
    if (c == 0) {
      tree = nullptr;
    } else {
      tree = new node();
      tree->data = c;
      v.erase(v.cbegin());
      create(tree->left, v);
      v.erase(v.cbegin());
      create(tree->right, v);
    }
  }

  void pre_traversal(pointer_to_node node,
                     const std::function<void(const value_type &v)> &f) {
    if (!node) return;

    f(node->data);
    pre_traversal(node->left, f);
    pre_traversal(node->right, f);
  }

  void mid_traversal(pointer_to_node node,
                     const std::function<void(const value_type &v)> &f) {
    if (!node) return;

    mid_traversal(node->left, f);
    f(node->data);
    mid_traversal(node->right, f);
  }
  void post_traversal(pointer_to_node node,
                      const std::function<void(const value_type &v)> &f) {
    if (!node) return;

    post_traversal(node->left, f);
    post_traversal(node->right, f);
    f(node->data);
  }

  pointer_to_node root() { return _M_root; }

  // TODO
  ~BinaryTree() {}

 private:
  struct Node {
    pointer_to_node right = nullptr;
    value_type data;
    pointer_to_node left = nullptr;
  };

  pointer_to_node _M_root = nullptr;
};

#endif  // DATA_STRUCTURE_BINARYTREE_H_
