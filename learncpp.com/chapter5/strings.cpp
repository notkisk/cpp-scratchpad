#include <cstddef>
#include<string>
#include<iostream>

int main(){
  // std::string name {};
  // std::cout << "Enter your full name: ";
  // std::cin >> name; // this won't work as expected since std::cin breaks on whitespace
  //
  // std::cout << "Enter your favorite color: ";
  // std::string color{};
  // std::cin >> color;
  //
  // std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
  // //this will print Your name is John and your favourite color is Doe
  // //this happens because the first time when you enter your name, you typed in Jogn Doe, notice the whitespace in between John and Doe
  // //so, the first extraction >> will extract john until the first white space, so doe will be 
  // //left in the buffer for future extraction, now when the second extraction happens, it will extract Doe and therefore it will print out that way 
  // // the solution is to use std::getline to input text
  // std::cout << "Enter you full name: ";
  // std::getline(std::cin>>std::ws , name);
  //
  // std::cout << "Enter your favourite color: ";
  // std::getline(std::cin>>std::ws, color);
  //
  // std::cout << "Your name is " << name << " and your favourite color is " << color << '\n';
  // // std::ws will basically make std::cin ignore leading white spaces, for example when you have a cin to input something like a number
  // // if lets say you enter 2 and then press enter, what you just typed in is actual 2\n , so cin will extract 2 and leave that \n for futoure extraction 
  // // when the next cin comes in, it will find \n in the input stream so it will extract it and call it the input, so it won't even wait fo you to enter new input 
  // // int x {};
  // // std::cin >> x;
  // // std::cout << x << '\n';
  // // std::string y{};
  // // std::cin >>y;
  // // std::cout <<y;
  // std::string something {"Hi! my name is jeff"};
  // int length_of_something {static_cast<int>(something.length())};
  // std::cout << something << " has " << length_of_something<< " characters\n";
  // int another_length_of_something {static_cast<int>(std::ssize(something))};
  // std::cout << another_length_of_something;
  // //std::ssize returns a large integral type called ptrdiff_t, its usually larger than and int, so u have to static cast it to an int otherwise you will run into problems
  // another_length_of_something = std::ssize(something);
  std::ptrdiff_t x {};
  std::cout <<sizeof(x);//this will print 8, meaning std::ptrdiff_t word size is 8 bytes 
  using namespace std::string_literals; // this contains the s suffix 
  std::cout << "foo\n"; // no suffix is a C-style string literal 
  std::cout << "goo\n"s; // s suffix is a std::string literal, this will make it into an std::string instead of c-style literal 
  // constexpr std::string yay{"yay"}; this will yield an error, because constexp isn't supported at all in c++17(the version that introduced std::string)
  // if you need constexpr string, you gotta use std::string_view
  std::cin.get();

  return 0;

}
