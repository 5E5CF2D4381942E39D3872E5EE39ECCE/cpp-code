#ifndef DATA_STRUCTURE_SEQUENTIALLIST_H_
#define DATA_STRUCTURE_SEQUENTIALLIST_H_

#include <iostream>

template <typename T>
class SequentialList {
 public:
  using size_type = unsigned long;
  using value_type = T;
  using pointer_to_value = value_type *;

  explicit SequentialList(size_type cap = 10)
      : _M_start(new value_type[cap]),
        _M_finish(_M_start),
        _M_end_of_storage(_M_start + cap) {}

  bool insert(const value_type &elem) {
    if (size() < capacity()) {
      _M_start[size()] = elem;
      ++_M_finish;

      return true;
    }

    return false;
  }

  void traversal() const {
    for (pointer_to_value ite = _M_start; ite != _M_finish; ++ite)
      std::cout << *ite << std::endl;
  }

  size_type size() const { return _M_finish - _M_start; }

  size_type capacity() const { return _M_end_of_storage - _M_start; }

  ~SequentialList() {
    if (_M_start) delete[] _M_start;
  }

 private:
  pointer_to_value _M_start;
  pointer_to_value _M_finish;
  pointer_to_value _M_end_of_storage;
};

#endif  // DATA_STRUCTURE_SEQUENTIALLIST_H_
