#include <iostream>
#include <ostream>
#include <type_traits>
#include <utility>
enum class Color // "enum class" defines this as a scoped enumeration rather
                 // than an unscoped enumeration
{
  red, // red is considered part of Color's scope region
  blue,
  green
};

enum class Fruit {
  banana, // banana is considered part of Fruit's scope region
  apple,
};

enum class Animals {
  chicken,
  dog,
  cat,
  elephant,
  duck,
  snake,

};

template <typename T>
  requires std::is_enum_v<T>
std::ostream &operator<<(std::ostream &out, T content) {
  return out << std::to_underlying(content);
}

template <typename T> constexpr auto operator+(T a) noexcept {
  return static_cast<std::underlying_type_t<T>>(a);
}

int main() {

  Color color{Color::red}; // note: red is not directly accessible, we have to
                           // use Color::red
  Fruit fruit{Fruit::banana}; // note: banana is not directly accessible, we
                              // have to use Fruit::banana
  using enum Color;
  using enum Animals;
  std::cout << +Color::blue << '\n';
  int t{};
  auto somthing{static_cast<Color>(t)};
  Color color2{1};
  std::cout << color2 << '\n';
  if (std::to_underlying(color) ==
      std::to_underlying(fruit)) // compile error: the compiler doesn't know how
                                 // to compare different types Color and Fruit
    std::cout << "color and fruit are equal\n";
  else
    std::cout << "color and fruit are not equal\n";

  return 0;
}
