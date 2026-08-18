#include <iostream>
#define MY_NAME "Haithem"
#define HAITHEM
#include "things.h"


void foo(){
  #define SOMETHING "something"
  something();
}
int main(){
  int x = 0;
  x++;
  std::cout <<x;
  std::cout << SOMETHING ; // this works just fine, preprocessor doesn't understand nor care about cpp syntax
  #if 0
    int z = 10;
    /* multi line comment gets commented out 
    * usually this is not possible cause commenting a nested comment is not allowed
    * */ 
  #endif
  #ifdef HAITHEM //you might be wondering why this works since we defined HAITHEM to be nothing, how come 
  //the preprocessor didn't replace HAITHEM in ifdef with nothing? in most cases macro substitution does not occur when a macro identifier is used within another preprocessor command
  //with the exception of #if and #elif they do perform macro substitution
    std::cout << MY_NAME << "\n";  
  #endif 
}
