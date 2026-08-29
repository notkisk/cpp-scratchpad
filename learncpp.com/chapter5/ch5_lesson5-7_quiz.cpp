#include <iostream>
#include <string>

std::string getName()
{
    std::cout << "Enter your full name: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;
}

int getAge()
{
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    return age;
}

int getComboLength(int age, std::string name)
{
    int nameLength{static_cast<int>(name.length())};

    return age+nameLength;
}

int main()
{
    std::string name{getName()};
    int age{getAge()};

    std::cout << "Your age + length of name is: " << getComboLength(age, name);

    return 0;
}
