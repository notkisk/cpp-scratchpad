#include <iostream>
#include <limits>
#include <format>

// class Versioning{
// public:
//   std::string version {};
// private:
//   std::int16_t id{};
//
// };

namespace constants{
  inline constexpr std::string_view version {"0.0.8"};
}
namespace language{
static constexpr std::int16_t some_costant {10};
namespace V1{
  bool isVowel(char c){
    return (c == 'a' || c =='e' || c == 'i' || c == 'o' || c == 'u' 
    || c == 'A' || c == 'E' || c =='O' || c=='U');
  }
}


inline namespace V2{
  bool isVowel(char c)
  {
      switch (c)
      {
      case 'a': 
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
          return true;
      default:
          return false;
      }
  }
}

}

int calculate(const int& a, const int& b, char c){
  if (c == '\0') 
    return std::numeric_limits<int>().min();
  switch (c){
    case '+':
      std::cout << std::format ("performing {} operation", c);
      return a + b;
    case '-':
      std::cout << std::format("performing {} operation", c);
      return a - b;
    case '*':
      std::cout << std::format("performing {} operation ", c);
      return a * b;
    case '/':
      std::cout << std::format("performing {} operation", c);
      if (b == 0){
        std::cerr << "division by zero error! please try a diffrent operands" << std::endl;
        return std::numeric_limits<int>().min();
      }
      return a / b;
    case '%':
      std::cout << std::format ("peforming {} operation", c);
      return a % b;
    default:
      std::cerr << std::format("operator {} is not supported in version {} of the app",c,constants::version);
      break;
  }
}

int main(){

  // std::cout << calculate(0,1,'+') << std::endl;
  // std::cout << calculate(1,0,'/') << std::endl;
  // std::cout << calculate(10, 20, '-') << std::endl;
  // std::cout << calculate(5,5,'%') << std::endl;
  // std::cout << calculate(10, 5, '*');

  std::cout << "Enter an integer: ";
  std::int32_t a {};
  std::cin >> a;

  std::cout << "Enter another integer: ";
  std::int32_t b {};
  std::cin>> b;

  std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
  char op{};
  std::cin>> op;

  int result {calculate(a, b, op)};
  std::cout << a << " " << op << " " << b << " is " << result << '\n';

  std::int16_t iteration {};
  // while (true){
  //   if(iteration == 1) break;
  //     switch (2){
  //       case 1:
  //         std::cout << "case is 1" << "\n";
  //         break;
  //       case 2:
  //         std::cout << "case 2" << "\n";
  //         // continue;
  //         [[fallthrough]];
  //       case 3:
  //         //         std::cout << "case 3" << "\n";
  //         //       case 4:
  //         //         std::cout << "case 4" << "\n";
  //         //         continue;
  //         //         // [[fallthrough]];
  //         //       default:
  //         //         std::cout << "default case" << "\n";
  //         //         break;
  //         //     }
  //         //   ++iteration;
  //         //
  //         //   }
  //             int a; 
  //             int b{ 5 }; 
  //             int z{ 4 }; 
  //             int y{};
  //
  //           switch (2)
  //           {
  //             //this part won't be excuted, because the switch statemnt will just straight to the first matching case
  //             // solution is to put variable declaration/definitions outside the switch statement!
  //             // another solution is to put them inside of each case statement, so each case statement that utelizes a certain 
  //             // variable, that variable must be defined or declared inside the case statement
  //             /*
  //             int a; 
  //             int b{ 5 }; 
  //             int z{ 4 }; 
  //             int y{};
  //             */
  //             case 1:
  //                 y = 4; 
  //                 break;
  //             case 2:
  //                 y = 5; 
  //                 break;
  //             case 3:
  //                 break;
  //           }
  for (;;){

  }
  for(;i<10;){
    ++i;
  }
  std::cin.get();
  return 0;
} 
