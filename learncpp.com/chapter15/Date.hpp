#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
private:
  int m_year{};
  int m_month{};
  int m_day{};

public:
  Date(int year, int month, int day);
  void print() const;

  int getYear() const { return m_year; }
  int getMonth() const { return m_month; }
  int getDay() const { return m_day; }
};

inline Date::Date(
    int year, int month,
    int day) // inline to avoid violating the odr rule, it's worth noting that
    // member functions are implicitly inline unless you define them outside of
    // the class
    : m_year{year}, m_month{month}, m_day{day}

{}

inline void Date::print() const {
  std::cout << "Date(" << m_year << ", " << m_month << " , " << m_day << ")\n";
}

#endif

// this approach has a big downside, modifying anything in this header file,
// will trigger a recompilation for any cpp file that includes it in the other
// hand, if you include only class declaration and put the definitions in a
// ceperate cpp file, later when you include it in multiple cpp files, any
// changes to the cpp file will only trigger it's compilation and other files
// won't get recompiled!
