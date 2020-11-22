#ifndef POINT_H
#define POINT_H

struct Point {
  double x, y, z;

  Point(double x, double y, double z) : x(x), y(y), z(z) {}

  struct Point operator-(Point rhs) const { return Point(x - rhs.x, y - rhs.y, z - rhs.z); }
  struct Point operator+=(Point rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
  struct Point operator*(double rhs) const { return Point(x * rhs, y * rhs, z * rhs); }
  
};

inline Point operator*(double lhs, Point rhs) { return Point(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }

#endif

