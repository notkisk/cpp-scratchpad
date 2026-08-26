#include <cstdint>
#include <iostream>

void print(int x) // print now takes an int parameter
{
	std::cout << x << '\n';
}
void quiz(){
  std::cout << "Enter a single character: ";
  char x{};
  std::cin>>x;
  std::cout << "You entered \'"<< x << "\'" <<" which has ASCII code " << static_cast<int>(x) << '.';
}
int main()
{
	print(static_cast<int>(5.5)); // warning: we're passing in a double value
  char ch {97}; // 97 is ASCII code for 'a'
  std::cout << ch << " has value " << static_cast<int>(ch) << '\n';
  int s { -1 };
  std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

  unsigned int u { 4294967295 }; // largest 32-bit unsigned int
  std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20
  std::cout << "Enter a number between 0 and 127: ";
  int8_t myInt{};
  std::cin>> myInt;

  std::cout << "You entered: " << static_cast<int>(myInt) << '\n'; // this will print 51, because int8_t is interperted as a char, so when you type in 35 you are actualy entereing '3' '5'
  // and then '3' will be extracted from the input buffer and 5 will be left in the input stream, '3' is represented with the int value of 51 in ASCII character encoding 
  quiz();
	return 0;
}
