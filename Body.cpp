#include <vector>
#include <math.h>

#include "Body.h"
#include "Tuple.h"

// 6.674 * 10^(-11) m^3 / (kg * s^2)
#define G 1.0

class Body {
  public:
    double m;
    Tuple r, v, a;

    Body();
    double getDistanceTo(const Body& b, bool squared = false) const;
    void update_a(const std::vector<Body>& omega);
};

double Body::getDistanceTo(const Body& b, bool squared) const {
  double ds = pow(b.r.x - r.x, 2) + pow(b.r.y - r.y, 2) + pow(b.r.z - r.z, 2);

  return squared ? ds : sqrt(ds);
}

void update_a(std::vector<Body>& omega) {
  const int n = omega.size();
  Tuple a(0.0, 0.0, 0.0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        //a += G * (omega[j].m / omega[i].getDistanceTo(omega[j]), true) * (omega[j].r - omega[i].r);
        a += G * (omega[j].r - omega[i].r);
      }
    }

    omega[i].a = a;
  }
}

pub fn update_a(omega: &mut Vec<&mut Body>) {
  let mut a = Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0};
  for (i, mut b1) in omega.iter().enumerate() {
      for (j, b2) in omega.iter().enumerate() {
          if i != j {
              a += G * (b2.m / b1.distance(b2, Some(true))) * &(&b2.r - &b1.r);
          }
      }

      b1.a = a;
  }
}

pub fn init_data(omega: &mut Vec<Body>) {
    // 0
    omega.push(Body{
        m: 5.0,
        r: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 1
    omega.push(Body{
        m: 1.0,
        r: Tuple::Tuple{x: 0.5, y: 0.5, z: 0.0},
        v: Tuple::Tuple{x: 0.5, y: -0.5, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 2
    omega.push(Body{
        m: 1.0,
        r: Tuple::Tuple{x: 0.5, y: 0.0, z: 0.0},
        v: Tuple::Tuple{x: -0.5, y: -0.5, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });
}

/*
// Solar system
pub fn _init_data_solar_system(omega: &mut Vec<Body>) {
    /*  Units:
     *      r: 10^3 km
     *      v: 10^3 km/h
     *      a: 10^3 km/h^2
     */

    // 0 - Sun
    omega.push(Body{
        r: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 1 - Mercury
    omega.push(Body{
        r: Tuple::Tuple{x: 57909.175, y: 0.0, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 2  Venus
    omega.push(Body{
        r: Tuple::Tuple{x: 0.0, y: 108208.930, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 3 - Earth
    omega.push(Body{
        r: Tuple::Tuple{x: 0.0, y: 0.0, z: 149597.890},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 4 - Mars
    omega.push(Body{
        r: Tuple::Tuple{x: 227936.640, y: 0.0, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 5 - Jupiter
    omega.push(Body{
        r: Tuple::Tuple{x: 0.0, y: 778412.010, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 6 - Saturn
    omega.push(Body{
        r: Tuple::Tuple{x: 0.0, y: 0.0, z: 1426725.400},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 7 - Uranus
    omega.push(Body{
        r: Tuple::Tuple{x: 2870972.200, y: 0.0, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });

    // 8 - Neptune
    omega.push(Body{
        r: Tuple::Tuple{x: 0.0, y: 4498252.900, z: 0.0},
        v: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
        a: Tuple::Tuple{x: 0.0, y: 0.0, z: 0.0},
    });
}
*/
