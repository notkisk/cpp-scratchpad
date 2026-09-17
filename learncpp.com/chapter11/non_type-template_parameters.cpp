#include <cmath>
#include <iostream>

template <int N> // declare a non-type template parameter of type int named N
void print() {
  std::cout << N << '\n'; // use value of N here
}

template <> void print<5>() { std::cout << 5 << '\n'; }

template <double D> double getSqrt() {
  static_assert(D >= 0, "getSqrt(): D must be non-negative");
  if constexpr (D >= 0)
    return std::sqrt(D);
  return 0.0;
}
int main() {
  constexpr int N{0};
  print<5>(); // 5 is our non-type template argument
  print<N>();
  std::cout << getSqrt<5.0>() << '\n';
  std::cout << getSqrt<-5.0>() << '\n';
  return 0;
}
