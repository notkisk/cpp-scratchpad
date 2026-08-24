#include<iomanip>
#include <iostream>
#include <limits>

int main(){
  std::cout << std::boolalpha;
  std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
  std::cout << "double: " << std::numeric_limits<double>::is_iec559 << "\n";
  std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << "\n";
  // by default, std::cout output only 6 siginificant digits:
  std::cout << 9.8765321f << "\n";
  std::cout << 987.654321f << '\n';
  std::cout << 987654.321f <<'\n';
  std::cout << 9876543.21f << '\n';
  std::cout << 0.0000987654321f << '\n';
  
  std::cout << std::setprecision(17); // show 17 digits of precision
  std::cout << 3.3333333333333333333333333333333f << '\n'; // f suffic means float
  std::cout << 3.3333333333333333333333333333333 << '\n'; // no suffix means double 
  long double x = 3.333333333333333333333333333333;
  std::cout << "long double is : " << sizeof(long double)  << " bytes"<< '\n';
  std::cout << x << '\n';
  double zero { 0.0 };

  double posinf { 5.0 / zero }; // positive infinity
  std::cout << posinf << '\n';

  double neginf { -5.0 / zero }; // negative infinity
  std::cout << neginf << '\n';

  double z1 { 0.0 / posinf }; // positive zero
  std::cout << z1 << '\n';

  double z2 { -0.0 / posinf }; // negative zero
  std::cout << z2 << '\n';

  double nan { zero / zero }; // not a number (mathematically invalid)
  std::cout << nan << '\n';

  std::cin.get();
  return 0;

}
