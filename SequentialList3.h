#ifndef DATA_STRUCTURE_SEQUENTIALLIST3_H_
#define DATA_STRUCTURE_SEQUENTIALLIST3_H_

#include <functional>

template <typename T>
class SequentialList3 {
 public:
  using size_type = unsigned long;
  using value_type = T;
  using pointer_to_value = value_type *;
  using iterator = pointer_to_value;

  explicit SequentialList3(size_type cap = 10)
      : _M_start(new value_type[cap]),
        _M_finish(_M_start),
        _M_end_of_storage(_M_start + cap) {}

  void insert(int index, const value_type &data) {
    if (size() < capacity()) {
      for (size_type i = size(); i > index; --i) _M_start[i] = _M_start[i - 1];

      _M_start[index] = data;
      ++_M_finish;
    } else {
      throw std::out_of_range(__func__);
    }
  }

  value_type remove(size_type index) {
    if (index < size() && index >= 0) {
      value_type t = _M_start[index];

      for (size_type i = index; i < size() - 1; ++i) {
        _M_start[i] = _M_start[i + 1];
      }
      --_M_finish;

      return t;
    } else {
      throw std::logic_error(__func__);
    }
  }

  size_type removeAll(const value_type &data) {
    size_type n = 0;
    for (size_type it = 0; it < size(); ++it) {
      if (data == _M_start[it]) {
        remove(it);
        ++n;
        --it;
      }
    }

    return n;
  }

  size_type contains(const value_type &data) {
    size_type n = 0;
    for (size_type it = 0; it < size(); ++it) {
      if (data == _M_start[it]) ++n;
    }

    return n;
  }

  void traversal(const std::function<void(const value_type &)> &f) {
    for (const value_type &t : *this) f(t);
  }

  bool isEmpty() const { return 0 == size(); }

  value_type get(size_type index) {
    if (index > size() - 1) throw std::out_of_range(__func__);
    return _M_start[index];
  }

  bool set(size_type index, const value_type &v) {
    if (index < size() && index >= 0) {
      _M_start[index] = v;

      return true;
    } else {
      return false;
    }
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

#endif  // DATA_STRUCTURE_SEQUENTIALLIST3_H_
