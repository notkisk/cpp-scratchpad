#include <iostream>
#include "CONSTANTS_H.h"
#include <typeinfo>

//don't use const for value parameters! because we generaly don't care if the funciton changes the value of the parameter 
//since it will just be a copy that will be destroyed when out of scope!
void printInt(const int x){
  std::cout << x << '\n';
}
//this returning a const fundamental type will be ignored by the compiler, for other types it might hurt performance because it impeds certain kinds of compiler optimizations!
// also it does not make any sese, whatever is returned will be destroyed, it is not like we will change the value on the global scope! 
const int getValue(){
  return 5;
}

/*why variables should be made constant:
 * 1- avoiding bugs, by  ensuring the value won't be changed!
 * 2- more opportunities for the compiler to optzmize the program
 * 3- it reduces the complexity of our program, like when you try to understand what a certain section
 * of the program is doing, constant values make it easy to infer whats something will return or do cause you already know the value of that constant!
 * and you don't have to worry about the value being changed. 
 * */

int main(){
  std::cout << "Enter your age: ";
  int age{};
  std::cin >> age;
  auto av = 1.56L;
  // these are called literal suffixes
  auto l = 5L;
  auto somthing = 3LL;
  auto cstyle = "Hello World!";
  auto weirdint = 'hi';//this will print a weird value, in ascii 'h' is 0x68 and 'i' is 0x69, the compliler will pack them into one number 
  //so it will be 0x6869 ! which prints 26729!!!! pretty weird stuff! this is an implementation defined representation, which means it differ from a compiler to another, for me i'm using g++ and it did what i just said! 
  //its called multi character litteral! 
  std::cout << "weird int: " << weirdint << '\t' << typeid(weirdint).name() << '\n';
  auto something_else = 5ull;
  auto something_else_else_else_else = 5ul;
  std::cout << sizeof(av) << '\n';
  const int constAge { age }; // initialize const variable using non-const value
  std::cout << 5 << '\n';  // 5 (no suffix) is type int (by default)
  std::cout << 5L << '\n'; // 5L is type long
  std::cout << 5u << '\n'; // 5u is type unsigned int
  age = 5;      // ok: age is non-const, so we can change its value
  // constAge = 6; // error: constAge is const, so we cannot change its value
  // printInt(5);
  double avogadro { 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
  double protonCharge { 1.6e-19 }; // charge on a proton is 1.6 x 10^-19
  std::cout << typeid(av).name() << '\n';
  std::cout << typeid(something_else).name() << '\n';
  std::cin.get();
  return 0;
}
