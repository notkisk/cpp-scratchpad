#include <iostream>
#include <string>
#include <string_view>

class Employee {
private:
  std::string m_name{"???"};
  int m_id{0};
  bool m_isManager{false};

public:
  Employee(std::string_view name,
           int id) // Employees must have a name and an id
      : m_name{name}, m_id{id} {
    std::cout << "Employee " << m_name << " created\n";
  }

  Employee(std::string_view name, int id,
           bool isManager) // They can optionally be a manager
      : m_name{name}, m_id{id}, m_isManager{isManager} {
    std::cout << "Employee " << m_name << " created\n";
  }
};

int main() {
  Employee e1{"James", 7};
  Employee e2{"Dave", 42, true};
}
