#ifndef DATA_STRUCTURE_LINKED2_LIST_H_
#define DATA_STRUCTURE_LINKED2_LIST_H_

#include <functional>

template <typename T>
class LinkedList2 {
  struct Node;

 public:
  class Iterator;

  using size_type = unsigned long;
  using value_type = T;
  using node = Node;
  using pointer_to_node = node *;
  using iterator = Iterator;

 public:
  LinkedList2() = default;

  void insert(size_type index, const value_type &elem) {
    if (index < 0 || index > size()) throw std::out_of_range(__func__);

    pointer_to_node t = new node();
    t->data = elem;

    if (!index) {
      // insert from the head
      if (!size()) _M_tail = t;  // init the tail

      t->next = _M_head;
      _M_head = t;
    } else {
      // insert from the middle or the tail
      size_type n = index - 1;
      iterator it = begin();
      while (n) {
        ++it;
        --n;
      }

      t->next = it._M_node->next;
      it._M_node->next = t;

      if (index + 1 == size()) ++_M_tail;  // update the tail
    }
  }

  value_type remove(size_type index) {
    if (index < 0 || index + 1 > size()) throw std::out_of_range(__func__);

    if (!index) {
      // remove from the head
      node retval = *_M_head;
      delete _M_head;
      _M_head = retval.next;

      return retval.data;
    } else {
      // remove from the tail
      size_type n = index - 1;
      iterator it = begin();
      while (n) {
        ++it;
        --n;
      }

      node retval = *(it._M_node->next);
      delete it._M_node->next;
      it._M_node->next = retval.next;

      if (index == size()) _M_tail = it._M_node;  // update the tail

      return retval.data;
    }
  }

  size_type removeAll(const value_type &data) {
    size_type n = 0;
    for (size_type i = 0; i < size(); ++i) {
      if (get(i) == data) {
        remove(i);
        ++n;
        --i;
      }
    }

    return n;
  }

  size_type contains(const value_type &data) const {
    size_type n = 0;
    for (const value_type &t : *this)
      if (t == data) ++n;

    return n;
  }

  value_type get(size_type index) const {
    if (index < 0 || index + 1 > size()) throw std::out_of_range(__func__);

    size_type n = index;
    iterator it = begin();
    while (n) {
      ++it;
      --n;
    }

    return *it;
  }

  bool set(size_type index, const value_type &v) {
    if (index < 0 || index + 1 > size()) return false;

    size_type n = index;
    iterator it = begin();
    while (n) {
      ++it;
      --n;
    }

    *it = v;
    return true;
  }

  void traversal(std::function<void(const value_type &)> f) const {
    for (const value_type &t : *this) f(t);
  }

  size_type size() const {
    size_type n = 0;
    for (const value_type &v : *this) {
      ++n;
    }

    return n;
  }

  bool isEmpty() const { return size() == 0; }

  iterator begin() const { return iterator(_M_head); }

  iterator end() const {
    // iterator it(_M_first);
    // while (it._M_node) ++it;

    return iterator(nullptr);
  }

  ~LinkedList2() {
    iterator it = begin();
    while (it != end()) {
      pointer_to_node t = it._M_node->next;
      delete it._M_node;

      it = iterator(t);
    }
  }

  class Iterator {
    friend class LinkedList2;

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

  pointer_to_node _M_head = nullptr;
  pointer_to_node _M_tail = nullptr;
};

#endif  // DATA_STRUCTURE_LINKED2_LIST_H_
