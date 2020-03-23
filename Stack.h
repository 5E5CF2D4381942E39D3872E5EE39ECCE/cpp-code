#ifndef DATA_STRUCTURE_STACK_H_
#define DATA_STRUCTURE_STACK_H_

#include "SequentialList3.h"

template <typename T>
class Stack : protected SequentialList3<T> {
 public:
  using size_type = typename SequentialList3<T>::size_type;
  using value_type = typename SequentialList3<T>::value_type;
  using base_type = SequentialList3<value_type>;

  void push(const value_type &elem) { base_type::insert(size(), elem); }
  void pop() { base_type::remove(size() - 1); }
  value_type top() const { return base_type::get(size() - 1); }

  bool isEmpty() const { return base_type::isEmpty(); }
  size_type size() const { return base_type::size(); }
};

#endif  // DATA_STRUCTURE_STACK_H_
