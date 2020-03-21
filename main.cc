#include "SequentialList.h"

#include <string>
int main(int argc, char **argv) {
  const size_t cap = 10;
  SequentialList<int> s(cap);
  for (decltype(s.size()) i = 0; i < cap; ++i) {
    if (!s.insert(i + 1))
      std::cout << "error: when insert elem " << i + 1 << std::endl;
  }

  s.traversal();

  return 0;
}
