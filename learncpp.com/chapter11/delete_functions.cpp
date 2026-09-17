#include <iostream>

void printInt(int x) { std::cout << x << '\n'; }

// void printInt(char) = delete; // calls to this function will halt compilation
// void printInt(bool) = delete; // calls to this function will halt compilation
// void printInt(long) = delete;
//
template <typename D> void printInt(D x) = delete;

int main() {
  printInt(97);   // okay
  printInt(5L);   // compile error: function deleted
  printInt('a');  // compile error: function deleted
  printInt(true); // compile error: function deleted

  printInt(5.0); // compile error: ambiguous match, because a double can be
                 // numerically converted to
  // an int, char, bool, long! detelted functions participate in function
  // overloading stages too, and delete does not mean it does not exist, it just
  // says i forbid this type of call

  return 0;
}
