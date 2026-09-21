#include <iostream>

int main() {
  short value{7};      // &value = 0012FF60
  short otherValue{3}; // &otherValue = 0012FF54

  short *ptr{&value};

  std::cout << &value << '\n'; // this prints 0012FF60
  std::cout << value << '\n';  // this prints 7
  std::cout << ptr << '\n';    // this also prints 0012FF60
  std::cout << *ptr << '\n';   // this prints 7
  std::cout << '\n';

  *ptr = 9;

  std::cout << &value << '\n'; // this prints 0012FF60
  std::cout << value << '\n';  // this prints 9
  std::cout << ptr << '\n';    // this prints 0012FF60
  std::cout << *ptr << '\n';   // this prints 9
  std::cout << '\n';

  ptr = &otherValue;

  std::cout << &otherValue << '\n'; // this prints 0012FF54
  std::cout << otherValue << '\n';  // this prints 3
  std::cout << ptr << '\n';         // this prints 0012FF54
  std::cout << *ptr << '\n';        // this prints 3
  std::cout << '\n';

  std::cout << sizeof(ptr) << '\n'; // this prints 4(assuming 32 bit machine)
  std::cout << sizeof(*ptr)
            << '\n'; // this prints 2 (assuming short is 2 bytes)

  return 0;
}
