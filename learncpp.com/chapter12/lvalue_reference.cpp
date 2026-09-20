#include <iostream>

int main() {
  int x{5};
  int &ref{x};
  std::cout << x << ref << '\n';
  x = 6;
  std::cout << x << ref << '\n';

  ref = 7;
  std::cout << x << ref << '\n';

  const int y{5};
  // int &invalidRef{y}; // this is invalid because a non const lvalue can't
  // bind to a constant object(or function)
  // int &invalidRef2{2}; // this is also invalid, and lvalue reference can't
  // bind to an rvalue

  // double &invalid3{x}; // this is invalid, because of type mismatch, this
  // will result in an int to double
  // conversion which results always in an rvalue, an you know rvalues can't be
  // binded to an lvalue reference this works for any conversion from anytype to
  // another, all dissallowed as far as i know

  int var1{5};
  int var2{6};

  int &ref1{x};

  ref1 = y;
  std::cout << x << '\n'; // you might expect this to print 5, but it won't, it
                          // will print 6 instead
  // this is because refrences can't be rebinded, so that assignment (ref1 = y)
  // is just a value assignement mearning it will just assign the value 6 to
  // whatever ref1 is referencing
  // so avoid doing that unless it's intentional!
  std::cin.get();
  return 0;
}
