#include <iostream>

int main() {
  const double a{3.0};
  auto b{a}; // WARNING: auto drops the const specifier!
  constexpr double c{5.0};
  constexpr auto d{c}; // WARNING: since constexpr is not a type specifier, auto
                       // won't infer it
  // and it it will be dropped too!

  std::cin.get();
  return 0;
}
