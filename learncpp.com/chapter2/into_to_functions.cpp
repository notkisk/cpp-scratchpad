#include <iostream> // for std::cout
#include<cstdlib>


void doB()
{
    std::cout << "In doB()\n";
}

void doA()
{
    std::cout << "In doA()\n";

    doB();
}
int getValueFromUserUB(){
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;
}

// Definition of function main()
int main()
{   
    int num {getValueFromUserUB()};
    std::cout << num << " doubled is " << num * 2 << "\n"; 
    // std::cout << "Starting main()\n"; 
    //
    // doA(); //this will print In doA() and then In doB()
    // doB(); // this will print In doB()
    //
    // std::cout << "Ending main()\n";

    return EXIT_SUCCESS; // it has the same meaning as 0, both means the program excuted successfully
    // there is also EXIT_FALIURE which means the program did not excute successfully
    // both EXIT_SUCCESS and EXIT_FALIURE are preprocessors, later the preprocessor will replace them with either 0 or 1
}
