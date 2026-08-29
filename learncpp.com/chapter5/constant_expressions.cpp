#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y; // can only execute at runtime

    return y;      // this return expression is a runtime expression
}

// The return value of a non-constexpr function is a runtime expression
// even when the return expression is a constant expression
int five()
{
    return 5;      // this return expression is a constant expression
}

int main(){
  const int x {5};
  int not_constant {1};
  not_constant += 1;
  int z {not_constant };

  constexpr int y {x};
  // constexpr int h{not_constant}; the compiler will complain, constexpr can only be initilzzed by a expression that is evaluated at compile time 
  std::cin.get();
  // Literals can be used in constant expressions
  5;                           // constant expression
  1.2;                         // constant expression
  "Hello world!";              // constant expression

  // Most operators that have constant expression operands can be used in constant expressions
  5 + 6;                       // constant expression
  1.2 * 3.4;                   // constant expression
  8 - 5.6;                     // constant expression (even though operands have different types)
  sizeof(int) + 1;             // constant expression (sizeof can be determined at compile-time)

  // The return values of non-constexpr functions can only be used in runtime expressions
  getNumber();                 // runtime expression
  five();                      // runtime expression (even though the return expression is a constant expression)

  // Operators without constant expression operands can only be used in runtime expressions
  std::cout << 5;              // runtime expression (std::cout isn't a constant expression operand)
  /*Question #1

    For each statement, identify:

    Whether the initializer is a constant expression or non-constant expression.
    Whether the variable is a constant expression or non-constant expression.
   * */
  char a {'q'}; // the initilizer is constant expressions because its a literal and litrrals are evaluated at compile time 
  // the variable is not constant expression because it is not prefixed with const therefore its not a constant expression 
  const int b {0}; // this is a constant expression, both the initlizer and the variable, 0 is a literal and b is const integral with a constant exporession initlizer 
  //
  const double c {5.0}; // 5.0 is a constant expression because its a literal, c is not a constant expression because its not a const integral type 
  //Per the definition of a compile-time constant, only const integral variables with a constant expression initializer are compile-time constants. c is a double, which is not an integral type, so it does not meet this definition.
  const int d {a * 2}; //hmm; a is not a constant expression even though 'q' is a literal constant, d is not constant expression because its its initialized 
  //with a non constant expression a * 2 is nonn constant expression 
  // int e { c + 1.0 }; // c defined as const double c { 5.0 }; this not a constant expression, the niitialized is not a constant expression
  // and e is not marked as a const, therefore its not a constant expression 
  const int f { d * 2 }; // d defined as const int d { 0 }; Both d and 2 are constant expressions, so d * 2 is a constant expression.
  // f is a constant expression since it is a const integral type with a constant expression initializer.
  const int g { getNumber() }; // getNumber returns an int by value |> this is not a constant expresion, the initlizer is evaluated at runtime 
  // 
  const int h{}; 
  std::cout << h;
  return 0;
}
