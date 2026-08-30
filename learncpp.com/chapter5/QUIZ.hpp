#ifndef QUIZ_HPP
#define QUIZ_HPP
#include <string>
#include <string_view>
std::string getName(const unsigned int& personNumber);
unsigned int getAge(std::string_view personName);
void printResults(std::string_view person1Name,
                  const unsigned int& person1Age,
                  std::string_view person2Name,
                  const unsigned int& person2Age);
#endif

