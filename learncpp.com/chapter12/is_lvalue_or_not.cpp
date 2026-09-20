#include <iostream>
#include <string>

template <typename T> constexpr bool is_lvalue(T &) { return true; }

template <typename T> constexpr bool is_lvalue(T &&) { return false; }

#define PRINTVCAT(expr)                                                        \
  {                                                                            \
    std::cout << #expr << " is an "                                            \
              << (is_lvalue(expr) ? "lvalue\n" : "rvalue\n");                  \
  }

int getint() { return 5; }

int main() {

  PRINTVCAT(5);                    // rvalue
  PRINTVCAT(getint());             // this will print rvalue
  int x{5};                        // 5 is an rvalue
  PRINTVCAT(x);                    // this is an lvalue
  PRINTVCAT(std::string{"Hello"}); // this is rvalue
  PRINTVCAT("Hello");              // this is an lvalue
  PRINTVCAT(++x); // this is an lvalue, because we adding 1 and then returning x
                  // identifier
  PRINTVCAT(x++); // in here we returning x value and then adding one, so this
                  // is an rvalue
}
