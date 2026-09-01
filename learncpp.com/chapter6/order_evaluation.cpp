#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
  //   int x { 5 };
  //   int value{ add(x, x++) }; // undefined behavior: is this 5 + 6, or 6 + 6?
  //   // It depends on what order your compiler evaluates the function arguments in
  //   //g++ will evaluate it to 12, while clang++ to 11, this is because in g++ function arguments are evaluates
  // //from right to left, while in clang they are evaluated from left to right, the issue is cpp standard does not 
  // //define order of evlatuion ofr function arguments!!! why?! put an end to this shit!
  //   std::cout << value << '\n'; // value could be 11 or 12, depending on how the above line evaluates!
  //
  // std::cout << x ;
  int a {5};
  int b {5};
  std::cout << a << " "<< b <<'\n'; // this will print 5 5
  std::cout << ++a << " "<< --b <<'\n'; // this will print 6 4
  std::cout << a << " "<< b <<'\n'; // this will print 6 4 
  std::cout << a++ << " "<< b-- <<'\n'; // this will print 6 4
  std::cout << a << " "<< b <<'\n'; // this will print 7 3
  std::cout << --a << " "<< ++b <<'\n'; // this will print 6 4
  std::cout << a << " "<< b <<'\n'; // this will print 6 4
  std::cout << a++ << " "<< --b <<'\n'; // this will print 6 3
  std::cout << a << " "<< b <<'\n'; // this will print 7 3
  int y{1};
  y + ++y; // this is like (y + (++y)) increment y by one, so now y = 2, and then add y to it so essentially 2 + 2 = 4
    return 0;
}
