#include <iostream>

int main(){
int x= -500;
unsigned int constant = 0;
  int y = 2;
  int z = 2<<1;
  std::cout<<z << std::endl;
  std::cout << '/n';
  std::cout <<(bool)(x>constant) << std::endl; //signed -1 is bigger than unsigned 0!!
  std::cin.get();
  return 0;
}

