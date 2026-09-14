#include <iostream>

int main() {
  int n1{5};
  unsigned int u1 = n1;

  int n2{-5};
  unsigned int u2 = n2;
  std::cout << u2 << '\n'; // will print (2^32 -5) which equals to 4.294_967_291

  int u = static_cast<int>(static_cast<unsigned int>(
      -5));               // this convert -5 to unsigned int and back
  std::cout << u << '\n'; // prints -5
  int j = 3.9; // this will be converted from double 3.9 to int 3, basically it
               // get rid of the fractional part(no rounding like in python)
  float t = 3.9;
  int h = t;
  std::cout << j << '\n';
  std::cout << h << '\n';
  // Converting a value that has lost data back to the source type will result
  // in a value that is different than the original value: just like in
  // mathematics, matrices that losen information during a linear transformation
  // are not invertible(invertible matrix theorem)
  double d{static_cast<double>(
      static_cast<int>(3.5))}; // convert double 3.5 to int and back
  std::cout << d << '\n';      // prints 3

  double d2{static_cast<double>(static_cast<float>(
      1.23456789))};       // convert double 1.23456789 to float and back
  std::cout << d2 << '\n'; // prints 1.23457
  constexpr int s1{5};
  constexpr unsigned us1{s1}; // this is okay, because the value of s1 will be
                              // known at compile time, thus the compiler will
                              // know weither a narrowing conversion will happen
  // or not, in this case it won't, because 5 can be considered unsigned int
  // without any narrowing conversion
  constexpr int s2{-5};
  // unsigned int us2{
  //     s2}; // this will result in a compile error, the conversion is
  //     narrowing,
  // because the value will change from -5 to
  // 2^32 -5 which is considered a narrowing conversion and list initilization
  // disallow this type of conversion
  std::cin.get();
  return 0;
}
