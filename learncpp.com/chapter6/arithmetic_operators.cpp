#include <iostream>
#include <cmath>

int main()
{
	constexpr int apples { 12 };
	std::cout << "You have " << apples << " apples. Enter how many people to divide them between: ";
	int x {};
	std::cin >> x;

	std::cout << "Each person gets " << apples / x << " whole apples.\n"; // apples and x are int, so this is integer division
  std::cout << std::pow(3,4); 
	return 0;
}
