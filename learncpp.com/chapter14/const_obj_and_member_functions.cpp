#include <iostream>

struct Date {
  int year{};
  int month{};
  int day{};

  // you can overload a member function using that const
  // because const is part of the function signature
  void print() { std::cout << year << '/' << month << '/' << day; }
  void print() const { std::cout << year << '/' << month << '/' << day; }
};

void doSomething(const Date &date) { date.print(); }
int main() {
  Date s1{};
  s1.print(); // calls print()
  const Date s2{};
  s2.print(); // calls print() const
  return 0;
}
