#include <iostream>

int main(){
  int x {5};
  std::cout << "The value of x is: " << x << '\n';
  std::cout << "First part\tSecond part\n";
  std::cout << "Please enter a keyboard character: ";
  char ch{};
  std::cin.get(ch);
  std::cout << "You entered: " << ch << "\n";
  std::cin.get(ch);
  std::cout << "You entered: " << ch << '\n';

  std::cout << "This prints a single quote \' \n";
  std::cout << "This prints a double quote \" \n";
  std::cout << "This is a vertical tab \v";
  std::cout << "This is an alert \a";
  std::cout << "\nYou can clearly see what the vertical tab did there\n";
  std::cout << "\"This is quoted text\"\n";
  std::cout << "This string contains a single backslash \\\n";
  std::cout << "6F in hex is char '\x6F'\n";
  int y { 5 };
  // std::cout << "The value of x is " << y << '!\n'; // added exclamation point (it won't compile)

  std::cin.get();

  return 0;
}
