#ifndef DATA_STRUCTURE_LINKED_LIST_H_
#define DATA_STRUCTURE_LINKED_LIST_H_

#include <functional>

template <typename T>
class LinkedList {
  struct Node;

 public:
  class Iterator;

  using size_type = unsigned long;
  using value_type = T;
  using node = Node;
  using pointer_to_node = node *;
  using iterator = Iterator;

 public:
  LinkedList() = default;

  void insert(const value_type &elem) {
    pointer_to_node t = new node();
    t->data = elem;
    t->next = _M_first;

    _M_first = t;
  }

  void traversal(std::function<void(const value_type &)> f) const {
    for (const value_type &t : *this) f(t);
  }

  iterator begin() const { return iterator(_M_first); }

  iterator end() const {
    // iterator it(_M_first);
    // while (it._M_node) ++it;

    return iterator(nullptr);
  }

  ~LinkedList() {
    iterator it = begin();
    while (it != end()) {
      pointer_to_node t = it._M_node->next;
      delete it._M_node;

      it = iterator(t);
    }
  }

  class Iterator {
    friend class LinkedList;

   public:
    explicit Iterator(node *pn) : _M_node(pn) {}

    iterator &operator++() {
      _M_node = _M_node->next;
      return *this;
    }

    iterator operator++(int dummy) {
      iterator t(_M_node);
      ++*this;

      return t;
    }

    value_type &operator*() { return _M_node->data; }

    value_type *operator->() { return &**this; }

    iterator &operator=(const iterator &rhs) {
      _M_node = rhs._M_node;

      return *this;
    }

    bool operator==(const iterator &rhs) const {
      return _M_node == rhs._M_node;
    }

    bool operator!=(const iterator &rhs) const { return !(*this == rhs); }

   private:
    pointer_to_node _M_node = nullptr;
  };

 private:
  struct Node {
    value_type data;
    pointer_to_node next = nullptr;
  };

  pointer_to_node _M_first = nullptr;
};

#endif  // DATA_STRUCTURE_LINKED_LIST_H_
