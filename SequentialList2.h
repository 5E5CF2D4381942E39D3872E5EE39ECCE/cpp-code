#ifndef DATA_STRUCTURE_SEQUENTIALLIST2_H_
#define DATA_STRUCTURE_SEQUENTIALLIST2_H_

#include <functional>

template <typename T>
class SequentialList2 {
 public:
  using size_type = unsigned long;
  using value_type = T;
  using pointer_to_value = value_type *;
  using iterator = pointer_to_value;

  SequentialList2(size_type cap = 10)
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

  void traversal(const std::function<void(const value_type &)> &f) {
    for (const value_type &t : *this) f(t);
  }

  size_type size() const { return _M_finish - _M_start; }
  size_type capacity() const { return _M_end_of_storage - _M_start; }

  iterator begin() { return _M_start; }
  iterator end() { return _M_finish; }

 private:
  pointer_to_value _M_start;
  pointer_to_value _M_finish;
  pointer_to_value _M_end_of_storage;
};

#endif  // DATA_STRUCTURE_SEQUENTIALLIST2_H_
