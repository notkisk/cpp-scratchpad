#include<iostream>

int five()
{
    return 5;
}

int main()
{
    int a{ 2 };             // initialize variable a with literal value 2
    int b{ 2 + 3 };         // initialize variable b with computed value 5
    int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d{ b };             // initialize variable d with variable value 5
    int e{ five() };        // initialize variable e with function return value 5
    // int x{ 2 + 3 }; // 2 + 3 is an expression that has no semicolon 
    // -- the semicolon is at the end of the statement containing the expression
    // the syntax is something like type identifier {expression} the whole thing is called a statement  
    1 + 3; // this is also an expression but its called expression statement because it ends with a semicolon
    2; // this one too! 
    //quizes:
    // int x; //this is a statement
    // int x = 5; // this is an expression statement
    // x = 5; //this is also an expression statement, x= 5 is a statement adding the semicolon makes it statement
    five(); // this is an expression statement, five() is an expression adding the semicolon makes it an expression statement
    // std::cout << x; // this is also an expression statement, the << is a binary operator meaning it takes two operands in here it takes std::cout and x
    
    //question #3:
    	std::cout << 2 + 3 << '\n'; //this prints 5 and goes to next line 

      int x{ 6 };
      int y{ x - 2 };//this prints 4
      std::cout << y << '\n';

      int z{};
      z = x;
      std::cout << z * x << '\n'; // this prints 36
  return 0;
}
