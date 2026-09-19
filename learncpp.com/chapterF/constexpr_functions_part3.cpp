#include <iostream>
#include <type_traits>

consteval int greater(int x, int y) { return (x > y ? x : y); }

constexpr int foo(int x) {
  if (std::is_constant_evaluated()) // this returns true if the code is
                                    // evaluated at compile time!
    return x * 2;
  else
    return x * 3;
}

int main() {
  constexpr int g{greater(5, 6)};

  std::cout << greater(5, 6) << "is greater!\n";
  constexpr int x{5};
  std::cout << greater(x, 6);
  std::cin.get();
  return 0;
}
