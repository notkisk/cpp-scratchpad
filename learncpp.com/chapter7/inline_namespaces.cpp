#include <iostream>

namespace SOMETHINGS{
  namespace V1{
      void doSomething();
    }
    inline namespace V2{ //inline make the namespace content automatically available throgh the parent namespace, so you don't have to do SOMETHINGS::V2::doSomething(); you 
    // can just do doSomething(); or SOMETHINGS::doSomething();
        void doSomething();
      }
  }

int main(){
  // SOMETHINGS::V1::doSomething();
  // SOMETHINGS::doSomething(); // this will resolve to SOMETHINGS::V2::doSomething();
  // doSomething(); // this one will resolve to SOMETHINGS::V2::doSomething();
    std::cout << "Enter a positive number: ";
    int num{};
    std::cin >> num;


  if (num < 0){
    std::cout << "Negative number entered.  Making positive.\n";
    num = -num;
  }

  std::cout << "You entered: " << num;
    return 0;
  }


