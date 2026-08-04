#include <iostream>
#include <string>
#include <format>
#include <memory.h>
#include <cstring>
class Entity{
public:
  int x;
  std::string name;
  char* m_buffer;
  int m_size;
  Entity(Entity& other){
    
  std::cout << "Entity Copied" <<std::endl;
  }
  Entity(int& x, int &size, const char* string):x(x),m_size(size){
    m_buffer = new char[m_size];
    memcpy(m_buffer, string, m_size);
    std::cout <<std::format("initilized an entity with {}", x)<< std::endl;
  }
  Entity(int& x, std::string& name):x(x),name(name){
    
  }
};

int main(){
  int x = 0;
Entity e1{x};
Entity e2 = e1; // why its not calling the copy constructor?! printing shows  there exist a shallow copy! changing e1 changes e2 too! but the copy constructor is not called
  std::cout << std::format ("before e1 new assignmnet, e1.x = {} e2.x = {}", e1.x, e2.x)<<std::endl;
e1.x = 2;
  std::cout << std::format("e1.x = {} e2.x = {}", e1.x, e2.x)<<std::endl;
  std::cin.get();
  return 0;
}
