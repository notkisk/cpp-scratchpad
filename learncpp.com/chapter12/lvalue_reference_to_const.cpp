#include <iostream>

int main() {
  // case 1
  const double &r1{
      5}; // temporary double initialized with value 5, r1 binds to temporary
  // double& d { 5 }; // this is not allowed, only const lvalue can bind to
  // rvalue even of differenct type as long as the conversion is allowed
  //
  std::cout << r1 << '\n'; // prints 5

  // case 2
  char c{'a'};
  const int &r2{
      c}; // temporary int initialized with value 'a', r2 binds to temporary

  std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)

  // WARNING: when you initilize a const lvalue reference to value of differenct
  // type, a temporary object of same reference type will be created and
  // initlized with the refered value, this means any attempts to modify the
  // refered object will not affect the reference thats because what you are
  // refering to is actually a temporary object rather than the assumed refered
  // object, be carefull kiddo, here is an example:
  short bombs{1}; // I can has bomb! (note: type is short)

  const int &you{bombs}; // You can has bomb too (note: type is int&) so this
                         // will basically create a temporary object of type int
                         // and initilize it with the value of bombs which is 1
  // any attenmpts to modify bombs will not refelect on the reference
  --bombs; // Bomb all gone, this will only modify bombs not the reference

  if (you) // You still has? this will evaluate to true because you is still
           // equal to 1
  {
    std::cout << "Bombs away!  Goodbye, cruel world.\n"; // Para bailar la bomba
  }

  // To avoid dangling references in such cases(referencing a temporary object),
  // C++ has a special rule: When a const lvalue reference is directly bound to
  // a temporary object, the lifetime of the temporary object is extended to
  // match the lifetime of the reference.
  //
  // lvalue references to const are much more flexible than normal lvlaue
  // references, because they can bind to modifiable lavlues, non modifiable
  // lvalues and even rvalues!
  //
  // WARNING: constexpr lvalue references can only bind to objects of static
  // duration, either global varialbes or local varibales marked as static
  // this is because the compiler knows where static objects will be stored in
  // memory so it treat the address of that static variable as a constatnt
  // knwown at compile time constexpr references can't bind to non static local
  // variables because the address of that local variable is not known untill
  // the function where that variable resides in is fired

  static const int s_x{6};
  [[maybe_unused]] constexpr const int &reference2{
      s_x}; // this is weird, but when you define a constepr reference to a
            // const, you have to apply both constexpr and const to it
  // the constexpr applies to the reference(so we can bind to a static) and
  // const applies to the type(because the referenced object type is const)

  return 0;
}
