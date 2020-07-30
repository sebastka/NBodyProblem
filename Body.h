#ifndef BODY_H
#define BODY_H

#include "Point.h"

struct Body {
  double m;
  Point r, v, a;

  Body(double m, Point r, Point v, Point a) : m(m), r(r), v(v), a(a) {}
};

#endif