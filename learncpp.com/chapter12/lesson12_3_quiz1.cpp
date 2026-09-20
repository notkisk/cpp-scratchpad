#include <iostream>

int main() {
  int x{1};
  int &ref{x};

  std::cout << x << ref << '\n'; // this prints 11

  int y{2};
  ref = y;
  y = 3;

  std::cout << x << ref
            << '\n'; // this prints 22, because what that assignment is trying
                     // to do is just assigning a value to whatever the
                     // reference ref is reference in this case its assigning 2
                     // to x so its equavlant to writing x = 2

  x = 4;

  std::cout << x << ref
            << '\n'; // this prints 44, because as you know we can't rebind
                     // references, once set you can't rebind them, so x = 4
                     // will assign the value 4 to x and so the ref will
                     // reference to a variable x that equals to 4
  //

  return 0;
}
