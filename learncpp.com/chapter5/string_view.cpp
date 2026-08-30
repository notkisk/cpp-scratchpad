#include <iostream>
#include <string_view>

void printSV(std::string_view str){
  std::cout << str << '\n';
}

int main(){
 //  // int x {5};
 //  // std::cout << x << '\n';
 //  // std::string s{ "Hello, world!" }; // s makes a copy of its initializer
 //  // std::cout << s << '\n';
 //  std::string_view s {"Hello, world!"};
 //  printSV(s);
 //  std::string_view s1 { "Hello, world!" }; // initialize with C-style string literal
 //  std::cout << s1 << '\n';
 //
 //  std::string s0{ "Hello, world!" };
 //  std::string_view s2 { s0 };  // initialize with std::string
 //  std::cout << s2 << '\n';
 //
 //  std::string_view s3 { s2 }; // initialize with std::string_view
 //  std::cout << s3 << '\n';
 //  std::string str {s};
 //  printSV(str);
 //  std::cout << static_cast<std::string>(s);
 // //assignment changes what std::string_view is viewing but not the value it is viewing!
 //  std::string name {"Jay"};
 //  std::string_view sv {name};
 //  std::cout << sv << '\n';
 //
 //  sv = "Ali";
 //  std::cout << sv << '\n';
 //
 //  std::cout << name << '\n'; // this will print Jay
 //  using namespace std::string_literals;
 //  using namespace std::string_view_literals;
 //
 //  std::cout << "foo\n"; // no suffix is a C-styl literal
 //  std::cout << "goo\n"s; // s suffix is a std::string literal 
 //  std::cout << "moo\n"sv; // sv suffix is a std::string_view literal
  // std::string something {"Hello, world!"};
  // std::cout <<something << '\n';
  // std::string_view something_sv {something};
  // std::cout << something_sv << '\n';
  // something = "Spartaaaa!";
  // std::cout << something << '\n';
  // std::cout << something_sv << '\n';
  //

  std::string_view sv{};

  { // create a nested block
      std::string s{ "Hello, world!" }; // create a std::string local to this nested block
      sv = s; // sv is now viewing s
  } // s is destroyed here, so sv is now viewing an invalid string

  std::cout << sv << '\n'; // undefined behavior
  std::string_view str_view {"Peach"};
  std::cout << str_view << '\n';

  str_view.remove_prefix(1);
  std::cout << str_view << '\n';

  str_view.remove_suffix(2);
  std::cout << str_view << '\n';

  str_view = "Peach";
  std::cout << str_view << '\n';
  return 0;
}
