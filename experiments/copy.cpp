#include <iostream>
#include <string>
#include <cstring>

class String{
private:
  char* m_buffer;
  unsigned int m_size;
public:
  String(const char* string){
    m_size = strlen(string);
    m_buffer = new char[m_size];
    memcpy(m_buffer, string, m_size);
  }
  char& operator [](unsigned int index){
    return m_buffer[index];
  }
  // String (const String& other):m_size(other.m_size)  {
  //   m_buffer = new char[m_size +1];
  //   memcpy(m_buffer, other.m_buffer, m_size + 1);
  //
  // };
  ~String(){
    delete [] m_buffer;
  }
  friend std::ostream& operator <<(std::ostream& stream, String & string);
};

  std::ostream& operator <<(std::ostream& stream, String & string){
    stream << string.m_buffer;
    return stream;
  }
int main(){
  String string = "nnul";
  String second = string;
  second[2] = 'a';
  std::cout << string << std::endl;
  std::cout <<second<<std::endl;
  std::cin.get();
  return 0;
}
