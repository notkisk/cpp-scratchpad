#include <cmath>
#include <format>
#include <iostream>

class Point2d {
private:
  double m_x;
  double m_y;

public:
  Point2d() = default;
  constexpr explicit Point2d(double x) : Point2d{x, 0} {}
  constexpr Point2d(double x, double y) : m_x{x}, m_y{y} {}
  Point2d(const Point2d &point) : m_x{point.m_x}, m_y{point.m_y} {}

  double x() const { return m_x; }
  double y() const { return m_y; }

  void print() const { std::cout << *this << '\n'; }

  constexpr double distanceTo(const Point2d &second) const {
    return std::sqrt((x() - second.x()) * (x() - second.x()) +
                     (y() - second.y()) * (y() - second.y()));
  }

  friend std::ostream &operator<<(std::ostream &out, const Point2d &point) {
    return out << std::format("Point2d({}, {})", point.m_x, point.m_y);
  }
};

int main() {
  constexpr const Point2d first{};
  constexpr const Point2d second{3.0, 4.0};

  first.print();
  second.print();

  std::cout << "Distance between two points: " << first.distanceTo(second)
            << '\n';

  std::cout << second << '\n';

  std::cin.get();
  return 0;
}
