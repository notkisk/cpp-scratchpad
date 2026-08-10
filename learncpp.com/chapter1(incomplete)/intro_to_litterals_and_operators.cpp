#include <iostream>

int main(){

  std::cout << "Hi!" << std::endl;
  std::cout << 2+1<<"\n";
  std::cout << ((5*3) * 2^3) -5<<std::endl;
  //quizes
  //quiz 1:
  std::cout << 3+4 << '\n'; // this prints 7
  // quiz 2:
  std::cout << 3 + 4 -5 << '\n'; // this prints 2
  // quiz 3:
  std::cout << 2+3*4 << '\n'; // this prints 14
  //quiz 4:
  int x{2}; // this is called direct list initialization, its prefered over all other types of initialization because it is compatible with anything and it avoids narrowing conversions which results some unwanted outcomes
  // it also allow initialization with multiple values
  std::cout << (x=5) << '\n'; // this will print 5
  std::cin.get();
  return 0;
}
