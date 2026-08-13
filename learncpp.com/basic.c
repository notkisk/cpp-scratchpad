#include <stdio.h>
#include <stdbool.h>

int add (int x, int y){
  return x+y;
}
int main(void){
  bool yay = true;
  printf("%zu\n",sizeof(bool));
  int something = add(1,2);
  int x = 10; // this is 4 bytes 2's compliment integer
  long y = 1000000; // this is 8 bytes 2's compliment integer too!
  char c = 'A'; //this is 1 byte
  short s = 'A'; // this is 2 bytes
  float f = 3.14f; //this is 4 bytes, its a single precision floating point
  double d = 3.14; // this is 8 bytes, its a double precision floating point
  unsigned int z; // this is also 4 bytes but in unsigned representation(no sign bit)
  unsigned long w; // this is 8 bytes but in unsigned representation (no sign bit)
  printf("Hello world! \n");
  printf("%zu\n", sizeof(int));
  printf("%zu\n", sizeof(long));
  printf("%zu\n", sizeof(float));
  printf("%zu\n", sizeof(double));
  printf("%zu\n", sizeof(short));
  return 0;
}

