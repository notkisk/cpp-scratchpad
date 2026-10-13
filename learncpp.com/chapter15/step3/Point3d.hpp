#ifndef POINT3D_HPP
#define POINT3D_HPP
class Vector3d;

class Point3d {
private:
  double m_x{};
  double m_y{};
  double m_z{};

public:
  Point3d(double x, double y, double z);
  void print() const;
  void moveByVector(const Vector3d &v);
};
#endif
