#ifndef DATA_STRUCTURE_QUEUE_H_
#define DATA_STRUCTURE_QUEUE_H_

#include <functional>
#include "LinkedList2.h"

template <typename T>
class Queue : protected LinkedList2<T> {
 public:
  using base_type = LinkedList2<T>;
  using size_type = typename base_type::size_type;
  using value_type = typename base_type::value_type;

  void push(const value_type &elem) { base_type::insert(size(), elem); }
  void pop() { base_type::remove(0); }
  value_type top() { return base_type::get(0); }

  bool isEmpty() const { return base_type::isEmpty(); }
  size_type size() const { return base_type::size(); }
};

#endif  // DATA_STRUCTURE_QUEUE_H_
