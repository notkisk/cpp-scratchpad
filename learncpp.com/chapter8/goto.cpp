#include <iostream>
#include <cmath>

int main(){

float x {};
statementLabel:
  std::cout << "Enter a non negative number: ";
  std::cin >> x;

  if(x < 0.0)
    goto statementLabel;
  std::cout << "The square root of " << x <<  " is " << std::sqrt(x) << '\n';
  std::cin.get();
  return 0;
}

