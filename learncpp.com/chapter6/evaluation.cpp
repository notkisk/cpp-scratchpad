#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int main()
{
  //g++ compiler evaluates arguments right to left, clang compiler evaluates arguments from left to right 
    printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous
  // if you try to input something like 1 2 3, you would assume the expression will be evaluated 
  // to 7, but since we are using g++ this will evaluate to 5, because x will be 3 y will be 2 and z will be 1
  // so final expressino will be resolved to 3 + (2 * 1) = 5 assuming u are using g++ 
  // for clang this would work the way you expect it to be 1 + (2 * 3) = 7
  
  // the fix is to split getValue() calls into different statements
  int a {getValue()};
  int b {getValue()};
  int c {getValue()};
  printCalculation(a,b, c);
  // quiz 
  int x {};
  int y {};
  int z {};
  // a)
  x = ((3 + 4) + 5);
  // b)
  x = (y = z);
  // c)
  z *= ((++y) +5);
  // d)
  (a || (b && c)) || x;
  return 0;
}
