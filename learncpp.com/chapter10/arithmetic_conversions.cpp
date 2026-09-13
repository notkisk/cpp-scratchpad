#include <iostream>
#include <typeinfo>

int main() {
  int i{2};
  std::cout << typeid(i).name() << '\n'; // prints int

  double d{3.5};
  std::cout << typeid(d).name() << '\n'; // prints double

  std::cout << typeid(i + d).name() << '\n'; // prints double
  // basically, these integral and floating types are ranked, the ones ranked
  // low will be converted to the ones ranked high when doing arithmetics
  // ranking is as follows:
  // long doubld(highest rank)
  // double
  // float
  // long long
  // long
  // int(lowest rank)
  short a{4};
  short b{5};
  std::cout << typeid(a + b).name() << ' ' << a + b
            << '\n'; // this will print int, cause both operands are not listed
                     // in the preiority list
  // so they will undergo a integral promotion to int
  // when doing arithmetics on small width integral types, c++ promotes these to
  // int because int are fast on cpu's

  std::cout << std::boolalpha << (-3 < 5u)
            << '\n'; // this prints false, -3 will be converted to unsigned,
                     // which result in -3 being
  // equals to 2^32 -3 which is largest unsigned value -3, the the exoression
  // will evaluate to false even though -3 is smaller than 5! it does so,
  // because since -3 is in 2's compliment and for simlplicity lets use 8 bits
  // to represent it, -3 is 11111101', when converted  to unsigned int, 11111101
  // will be equal to 2⁸-3 in unsigned intn same bit representation, diffrent
  // interpertation
  std::cin.get();
  return 0;
}
