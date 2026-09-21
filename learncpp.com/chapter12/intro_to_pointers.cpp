#include <iostream>

int main() {
  int x{5};
  // std::cout << x << '\n';  // print the value of variable x
  // std::cout << &x << '\n'; // print the memory address of variable x

  std::cout << *(&x) << '\n';

  int *ptr;    // this is an uninitialized pointer aka wild pointer, it holds a
               // garbage address, dereferencing it leads to undefined behaviour
  int *ptr1{}; // this is a null pointer
  int *ptr3{&x}; // a pointer initialized with the address of variable x

  // std::cout << *ptr << '\n';
  int i{5};
  double d{7.0};

  // int *iPtr{&i}; // ok: a pointer to an int can point to an int object
  // int *iPtr2{
  //     &d}; // not okay: a pointer to an int can't point to a double object
  // double *dPtr{&d}; // ok: a pointer to a double can point to a double object
  // double *dPtr2{
  //     &i}; // not okay: a pointer to a double can't point to an int object
  //
  // int *lit_ptr{5}; // this is not okay, you can't point to a literal
  // int *lit_ptr2{0x0012FF7C}
  // // this is not okay too, its treated as an integral literal
  std::cout << typeid(x).name() << '\n';
  std::cout << typeid(&x).name() << '\n';
  {
    int x{5};
    int *ptr{&x};

    std::cout << *ptr << '\n'; // valid

    {
      int y{6};
      ptr = &y;

      std::cout << *ptr << '\n'; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout
        << *ptr
        << '\n'; // undefined behavior from dereferencing a dangling pointer
  }
  return 0;
}
