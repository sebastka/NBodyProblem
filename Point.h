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



/*

#ifndef TUPLE_H
#define TUPLE_H

struct Tuple {
  double x, y, z;

  Tuple(double x, double y, double z) : x(x), y(y), z(z) {}

  const Tuple& operator=(const Tuple& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; return *this; }

  bool operator==(const Tuple& rhs) const { return (x == rhs.x && y == rhs.y && z == rhs.z); }

  struct Tuple operator+(const Tuple& rhs) const { return Tuple(x + rhs.x, y + rhs.y, z + rhs.z); }
  struct Tuple operator-(const Tuple& rhs) const { return Tuple(x - rhs.x, y - rhs.y, z - rhs.z); }

  struct Tuple& operator+=(const Tuple& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
  struct Tuple& operator-=(const Tuple& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }

  struct Tuple& operator+=(double rhs) { x += rhs; y += rhs; z += rhs; return *this; }
  struct Tuple& operator-=(double rhs) { x -= rhs; y -= rhs; z -= rhs; return *this; }
  struct Tuple& operator*=(double rhs) { x *= rhs; y *= rhs; z *= rhs; return *this; }
  struct Tuple& operator/=(double rhs) { x /= rhs; y /= rhs; z /= rhs; return *this; }

  struct Tuple operator+(double rhs) const { return Tuple(x + rhs, y + rhs, z + rhs); }
  struct Tuple operator-(double rhs) const { return Tuple(x - rhs, y - rhs, z - rhs); }
  struct Tuple operator*(double rhs) const { return Tuple(x * rhs, y * rhs, z * rhs); }
  struct Tuple operator/(double rhs) const { return Tuple(x / rhs, y / rhs, z / rhs); }
};

inline Tuple operator+(double lhs, Tuple& rhs) { return rhs += lhs; }
inline Tuple operator-(double lhs, Tuple& rhs) { return rhs -= lhs; }
inline Tuple operator*(double lhs, Tuple& rhs) { return Tuple(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }
// Tuple / double is not commutative

#endif

*/