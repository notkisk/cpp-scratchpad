#include <iostream>
constexpr bool isEven(int& a){
  return (a % 2) == 0;
}
int main(){
  int a {};
  
  std::cout << "Enter an Integer: ";
  std::cin >> a;
  if (isEven(a))
    std::cout << a << " is even";
  else
    std::cout << a << " is odd";
  return 0;
}
