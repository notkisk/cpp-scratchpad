#include <iostream>

int main() {
  int x{10};
  int y{4};

  std::cout << (double)x / y << '\n'; // C-style cast of x to double

  return 0;
}
