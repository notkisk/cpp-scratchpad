#include <iostream>

template <typename T> T max(T x, T y) {
  std::cout << "called max<int>(int, int)\n";
  return (x < y) ? y : x;
}

template <typename T> int someFcn(T, double) { return 5; }

int max(int x, int y) {
  std::cout << "called max(int, int)\n";
  return (x < y) ? y : x;
}
// this is is an abbreviated function template
auto max(auto x, auto y) { return (x < y) ? y : x; }
// and its equavlant to writing
// template <typename T, typename U>
// auto max(T x, U y)
// {
//     return (x < y) ? y : x;
// }
int main() {
  std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
  std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int)
  // (non-template
  //                                   // functions not considered)
  std::cout << max(1, 2) << '\n'; // calls max(int, int)
  someFcn(1, 3.4);                // matches someFcn(int, double)
  someFcn(1, 3.4f); // matches someFcn(int, double) -- the float is promoted
  // to
  //                    // a double
  someFcn(1.2, 3.4);   // matches someFcn(double, double)
  someFcn(1.2f, 3.4);  // matches someFcn(float, double)
  someFcn(1.2f, 3.4f); // matches someFcn(float, double) -- the float is
                       // promoted to a double
  //
  return 0;
}
