#include <iostream>

int g_x{};
int g_y;
void print() // this print() lives in the global namespace
{
	std::cout << " there\n";
}

namespace Foo
{
	void print() // this print() lives in the Foo namespace
	{
		std::cout << "Hello";
	}

	void printHelloThere()
	{
		print();   // calls print() in Foo namespace
		::print(); // calls print() in global namespace
	}
}

int main()
{
  int y;
	Foo::printHelloThere();
  std::cout << g_y << '\n' << y << '\n';
  std::cin.get();
	return 0;
}
