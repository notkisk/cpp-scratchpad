#include <iostream>

struct Foo1 {
  short a{}; // will have 2 bytes of padding after a
  int b{};
  short c{}; // will have 2 bytes of padding after c
};

struct Foo2 {
  int b{};
  short a{};
  short c{};
};
struct st {
  char a;
  double b;
  char c;
};

int main() {
  std::cout << sizeof(Foo1) << '\n'; // prints 12
  std::cout << sizeof(Foo2) << '\n'; // prints 8
  std::cout << sizeof(st) << '\n';
  return 0;
}
