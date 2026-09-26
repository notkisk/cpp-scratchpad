#include <iostream>

struct Employee {
  int id{};
  int age{};
  double wage{};
};

struct Point {
  double x{};
  double y{};
};

struct Triangle {
  Point *a{};
  Point *b{};
  Point *c{};
};

int main() {
  Employee joe{1, 34, 65000.0};

  ++joe.age;
  joe.wage = 68000.0;

  Employee *ptr{&joe};
  std::cout << ptr->id
            << '\n'; // Better: use -> to select member from pointer to object
  // this is identical to the member selection operator(.) but in addition to
  // that it does a dereference before selection
  //
  Point a{1, 2};
  Point b{3, 7};
  Point c{10, 2};

  Triangle tr{&a, &b, &c};
  Triangle *tri_ptr{&tr};

  std::cout << (*(*tri_ptr).c).y << '\n'; // ugly as fuck!
  std::cout << tri_ptr->c->y
            << '\n'; // much nicer! using arrow operator is preferable
  return 0;
}
