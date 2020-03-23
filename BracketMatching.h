#ifndef DATA_STRUCTURE_BRACKETMATCHING_H_
#define DATA_STRUCTURE_BRACKETMATCHING_H_

#include <string>

#include "Stack.h"

class BMatch {
 public:
  using size_type = Stack<char>::size_type;

  bool operator()(const std::string &text) {
    size_type i = 0;
    while (i < text.size()) {
      switch (text[i]) {
        case '(':
        case '[':
        case '{':
          _M_stack.push(text[i]);
          break;

        case ')': {
          char t = '(';
          if (t == _M_stack.top())
            _M_stack.pop();
          else
            return false;
        }

        break;

        case ']': {
          char t = '[';
          if (t == _M_stack.top())
            _M_stack.pop();
          else
            return false;
        }

        break;
        case '}': {
          char t = '{';
          if (t == _M_stack.top())
            _M_stack.pop();
          else
            return false;
        }

        break;

        default:
          break;
      }

      ++i;
    }

    return true;
  }

 private:
  Stack<char> _M_stack;
};

#endif  // DATA_STRUCTURE_BRACKETMATCHING_H_
