#include <iostream>
#include <string>

void foo(int) { std::cout << "foo int" << '\n'; }

void foo(double) { std::cout << "foo double" << '\n'; }

void foo(std::string) { std::cout << "foo string" << "\n"; }

int main() {

  foo('a');  // this char will be promoted to an int, so foo int will print
  foo(true); // this bool will be promoted to an int, so foo int will print
  foo(4.5f); // this float will be promoted to a double, so foo double will
             // print
  // in cases were there is a match made by applying numiric promotion and
  // conversion, the matches made by promotion takes precedence

  // function overloading resolution tkaes a couple of steps usually to resolve
  // step one, compiler searches for an exact match, during the search the
  // compiler can make a couple of trivial conversions, like from lvalue to
  // rvalue, or from a non const to const or from a refrence to non refrence, or
  // any qualifier conversion if no match found, compiler moves to next step in
  // the process step two, the compiler start doing numric promotions if
  // possible if a match found, process ends, if multiple matches found a
  // compiler ambiduos overlad error is raised, if no match commpiler tries to
  // do numeric conversions same thing, if match found, functino is resolved,
  // multiple of matches found, compiler error, no matches found we move to next
  // phase in the process of searching for an overload If no match is found via
  // numeric conversion, the compiler tries to find a match through any
  // user-defined conversions. Although we haven’t covered user-defined
  // conversions yet, certain types (e.g. classes) can define conversions to
  // other types that can be implicitly invoked. if no matches found, compiler
  // looks for matching functions that uses ellipsis
  std::cin.get();
  return 0;
}
/*

  void foo(double)
  {
  }

  void foo(std::string)
  {
  }

  int main()
  {
      foo('a'); // 'a' converted to match foo(double)

      return 0;
  }

*/

// #include <iostream>
//
// void print(char, int)
// {
// 	std::cout << 'a' << '\n';
// }
//
// void print(char, double)
// {
// 	std::cout << 'b' << '\n';
// }
//
// void print(char, float)
// {
// 	std::cout << 'c' << '\n';
// }
//
// int main()
// {
// 	print('x', 'a'); this will call foo(char, int) because first of all, all
// functions match first argument char, 	and then second argument a char can
// either be promoted to an int or converted to float or double, since promotion
// from char 	to int exists here, it will take precendece over conversion, so the
// first overload is called!
//
// 	return 0;
// }
