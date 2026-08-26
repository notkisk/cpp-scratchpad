#include <iostream>

double get_user_input(){
  std::cout << "Please enter a double value: ";
  double value {};
  std::cin >> value;
  return value;
}
char get_operator(){
  std::cout << "Enter +, -, *, or /: ";
  char operation{};
  std::cin >> operation;
  return operation;
}

void print_result(double x, double y, char operation){
  double output{};
    if(operation == '+')
      output = x + y;
    else if(operation == '-')
        output = x - y;
    else if (operation == '*')
        output = x * y;
    else if (operation == '/')
          output = x / y;
    else 
      return;
  std::cout << x << ' ' << operation << ' ' << y << " is " << output << '\n';
}
int main(){
  double x{get_user_input()};
  double y {get_user_input()};
  char operation{get_operator()};
  print_result(x, y, operation);
  return 0;
}
