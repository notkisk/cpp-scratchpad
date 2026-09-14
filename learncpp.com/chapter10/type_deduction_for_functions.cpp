#include <iostream>

auto add(int x, int y) { return x + y; }

auto someFcn(bool b) {
  if (b)
    return 5; // return type int
  else
    return 6; // return type double
}
int main() {

  std::cin.get();
  return 0;
}
