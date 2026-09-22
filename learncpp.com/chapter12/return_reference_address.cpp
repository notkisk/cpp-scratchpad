#include <iostream>
#include <string>

std::string getHello() {
  return "Hello"; // implicit conversion to std::string
}

int main() {
  const std::string s{getHello()};

  std::cout << s;

  return 0;
}
