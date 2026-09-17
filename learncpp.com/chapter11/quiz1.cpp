#include <iostream>

template <int N> constexpr int factorial() {
  static_assert(N >= 0, "factorial(): N must be greater than or equal to 0");
  int temp{1};
  for (int i{2}; i <= N; ++i)
    temp *= i;
  return temp;
}

int main() {

  static_assert(factorial<0>() == 1);
  static_assert(factorial<3>() == 6);
  static_assert(factorial<5>() == 120);

  // factorial<-3>();
  std::cin.get();
  return 0;
}
