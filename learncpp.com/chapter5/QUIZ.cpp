#include <iostream>
#include <format>
#include "QUIZ.hpp" // provieds forward declaration in addition to
// both std::string and std::string_view headers

std::string getName(const unsigned int &personNumber){
  std::cout << std::format ("Enter the name of person #{}: ",personNumber);
  std::string personsName{};
  std::getline(std::cin>>std::ws, personsName);
  return personsName; 
}

unsigned int getAge(std::string_view personName){
  std::cout << std::format("Enter the age of {} :", personName);
  unsigned int personAge{};
  std::cin >> personAge;
  return personAge;
}

void printResults(std::string_view person1Name, const unsigned int &person1Age,
                  std::string_view person2Name, const unsigned int &person2Age){
  if (person1Age > person2Age)
    std::cout << std::format("{} (age {}) is older than {} (age {}).", person1Name, person1Age, person2Name, person2Age);
  else if (person1Age < person2Age)
    std::cout << std::format("{} (age {}) is older than {} (age {}).", person2Name, person2Age,person1Name, person1Age);
  else
    std::cout << std::format("{} (age {}) is same age as {} (age {}).", person1Name, person1Age,person2Name, person2Age);
}

// now time to define the functions


int main (){
  constexpr unsigned int number1 {1};
  constexpr unsigned int number2 {2}; // lol wtf is this! 
  const std::string person1Name{getName(number1)};
  unsigned int person1Age{getAge(person1Name)};
  const std::string person2Name{getName(number2)};
  unsigned int person2Age{getAge(person2Name)};
  printResults(person1Name, person1Age, person2Name, person2Age);
  std::cin.get();
  return 0;
}
