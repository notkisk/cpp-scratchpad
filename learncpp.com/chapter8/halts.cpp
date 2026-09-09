#include <cstdlib>
#include <iostream>

void cleanup(){
  //code here to do any kind of clean up required
  std::cout << "clean up\n";
}

int main(){
  std::cout << 1 << "\n";
  // cleanup();
  // std::exit(0); // this terminates and returns status code 0 to the operating system
  
  std::atexit(cleanup); // register cleanup() to be called automatically when std::exit() is called  
  // std::terminate();
  std::exit(0);
  std::cout << 2 << "\n";
  std::cin.get(); 
  return 0;

}
