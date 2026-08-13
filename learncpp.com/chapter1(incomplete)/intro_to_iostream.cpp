#include <iostream>

int main(){
  // std::cout << "Enter two numbers: ";
  //
  // int x {};
  // std::cin >> x;
  //
  // int y{};
  // std::cin>> y;
  //
  // std::cout << "You entered " << x << " and " << y << "\n";
  //
  //quiz
  std::cout << "Enter a number: "; //will input 5b6
  int z{};
  std::cin>>z; //this extracts 5 from the input buffer
  int w{};
  std::cin>>w; // this will fail to extract because an int can't hold a character like b therefore, cin will fail and will be set to a failbit
  int h{};
  std::cin>>h; // since last extraction failed, this will also fail since the input buffer now containse a failbit so no extraction will happen
  std::cout<<"You entered " << z << " " << w << " "<< h <<  "\n"; // will print 5 0 0 , 0 because no extraction happened therefore w and h will take on their default values
  std::cin.get();
  return 0;
}
