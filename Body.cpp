#include <vector>
#include <math.h>

#include "Body.h"
#include "Point.h"

// 6.674 * 10^(-11) m^3 / (kg * s^2)
#define G 1.0

double Body::getDistanceTo(Body* b, bool squared) const {
  double ds = pow(b->r.x - r.x, 2) + pow(b->r.y - r.y, 2) + pow(b->r.z - r.z, 2);

  return squared ? ds : sqrt(ds);
}

