#include <iostream>

template <typename T, typename U> struct Pair {
  T first{};
  U second{};
};

template <typename T, typename U> void print(Pair<T, U> p) {
  std::cout << '[' << p.first << ", " << p.second << ']';
}
template <typename T, typename U> constexpr T max(const Pair<T, U> &p) {
  return (p.first < p.second ? p.second : p.first);
}
template <typename T, typename U>
std::ostream &operator<<(std::ostream &out, const Pair<T, U> &p) {
  return out << p.first << ' ' << p.second << '\n';
}

template <typename T, typename U> struct Tuple {
  T first{};
  U second{};
};

template <typename T, typename U>
Tuple(T, U) -> Tuple<T, U>; // this is called CTAD deduction guide, or just a
                            // deduction guide
// it basically says, if you see Tuple(T, U) then instantiate this template
// overload Tuple<T, U> but this is for c++ 17 only, c++ 20 u don't have to do
// it fortunatly

int main() {
  Pair<int, int> p1{5, 6};
  std::cout << p1;

  Pair<double, double> p2{1.2, 3.4};
  std::cout << p2;

  Pair<double, double> p3{7.8, 9.0};
  std::cout << p3;
  std::cin.get();
  return 0;
}
