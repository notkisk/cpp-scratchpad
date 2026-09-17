#include <iostream>

template <typename T> T getMax(T a, T b) { return (a > b) ? a : b; }

template <typename T> void print(T a, T b) {
  std::cout << std::format("a: {} b: {}", a, b) << '\n';
}

template <typename T, typename D> void printN(T a, D b) {
  std::cout << std::format("a: {} b: {}", a, b) << '\n';
}

int main() {
  getMax(1, 2);
  getMax(5.5f, 0.5f);
  getMax<double>(3.14, 2.71);
  using namespace std::string_view_literals;

  print<std::string_view>("Hello, "sv, "World!"sv);

  std::cin.get();
  return 0;
}
