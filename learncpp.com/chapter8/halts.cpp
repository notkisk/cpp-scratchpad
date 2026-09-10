#include <cstdlib>
#include <iostream>

void cleanup(){
  //code here to do any kind of clean up required
  std::cout << "clean up\n";
}

int main(){
  std::cout << 1 << "\n";
  // cleanup();
  // std::exit(0); // this terminates and returns status code 0 to the operating system, and it won't clean up local variables/function parameters
  // in addition to that, the qued functions in the stack won't be unwinded!
   
  std::atexit(cleanup); // register cleanup() to be called automatically when std::exit() is called  
  // std::terminate();
  std::exit(0);
  std::quick_exit(0); // unlike exit, this does not wipe out static objects stored in memory, 
  // this is particularly usefull in multithreaded programs where you call the quick_exit from a thread won't 
  // wipe out shared static objects stored in memory and used by other threads 
  std::at_quick_exit(cleanup); // this one is simmilar to atexit() but it behaves like quick_exit()
  std::cout << 2 << "\n";
  std::cin.get(); 
  return 0;

}
