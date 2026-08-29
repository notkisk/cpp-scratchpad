#include<iostream>


// The return value of a non-constexpr function is not constexpr
int five()
{
    return 5;
}


int main(){
  int a { 5 };       // not const at all
  const int b { a }; // clearly not a constant expression (since initializer is non-const)
  const int c { 5 }; // clearly a constant expression (since initializer is a constant expression)
  //
  // because the use of const does not guarantee the variable to be evaluated at compile time(eg a non integral type marked with const and initlized with a constant expression)
  // c++ introduced the constexpr keyword, which ensure that we get a compile time constant variable, but it still has to be initlized 
  // with a constant expression, otherwise the compiler will throw compilation error!
  constexpr double gravity {9.8}; // ok: 9.8 is a constant expression(because its a literal)
  constexpr int sum { 1 + 2}; // ok: 1 + 2 is a constant expression, compiler will do a constant folding at compile time and evaluate it to 3
  constexpr int something {sum}; // ok: sum is a constant expression, therefore something is also a constant expression since its marked with constexpr and intilized with a constant expression
  
  std::cout << "Enter your agee: ";
  int age{};
  std::cin >> age;

  // constexpr int myAge {age}; // compilation error, because age is not a constant expression, and you can't intilized a constexpr with a non constant expression 
  // constexpr int f { five() };// compile error, the return type of five() is not a constexpr 
  //function normaly excute at runtime, the return value of a functino is not a constexpr even if it returns a constant expression like a literal
  //constexpr also works for non integral types like double or float! 
  constexpr double d {1.2}; // d can be used in constant expressions 
  const int val {(int)d}; // this is a constant expression! 
  static_assert(val == 1);// static assert is an assertion that is checked by the compiler at compile time 
  std::cin.get();
  return 0;
}
