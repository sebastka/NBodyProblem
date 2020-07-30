#include <iostream>
#include <vector>
#include <math.h>

#include "Point.h"
#include "Body.h"
#include "Omega.h"

void Omega::debug() {
	std::cout << "[ ";
	for (int i = 0; i < n; ++i) {
		std::cout << "[\"" << omega[i]->r.x << "\", \"" << omega[i]->r.y << "\", \"" << omega[i]->r.z << "\"]";
		if (i < n-1) std::cout << ", ";
	}
	std::cout << " ], " << std::endl;

}

// Initializing dataset
Omega::Omega() {
	// 0
	omega.push_back(new Body(
		5.0, 
		Point(0.0, 0.0, 0.0), 
      	Point(0.0, 0.0, 0.0), 
      	Point(0.0, 0.0, 0.0)
    ));

	// 1
	omega.push_back(new Body(
        1.0,
        Point(0.5, 0.5, 0.0),
        Point(0.5, -0.5, 0.0),
        Point(0.0, 0.0, 0.0)
    ));

	// 2
	omega.push_back(new Body(
       	1.0,
       	Point(0.5, 0.0, 0.0),
        Point(-0.5, -0.5, 0.0),
        Point(0.0, 0.0, 0.0)
    ));

    n = omega.size();
}

void Omega::run(double dt, double t_0, double t_end) {
	debug();
	for(t = t_0; t <= t_end; t += dt) {
		update_a();
		update_rv(dt);
		//update_r();
		debug();
	}
}

double Omega::getDistance(const Body* a, const Body* b, bool squared) const {
	double ds = pow(b->r.x - a->r.x, 2) + pow(b->r.y - a->r.y, 2) + pow(b->r.z - a->r.z, 2);

	return squared ? ds : sqrt(ds);
}

void Omega::update_a() {
	Point a(0.0, 0.0, 0.0);

	for (int i = 0; i < n; ++i) {
		a = Point(0.0, 0.0, 0.0);

		for (int j = 0; j < n; ++j) {
			if (i != j) {
				a += G * (omega[j]->m / getDistance(omega[i], omega[j]), true) * (omega[j]->r - omega[i]->r);
			}
		}

		omega[i]->a = a;
	}
}

void Omega::update_rv(double dt) {
	for (int i = 0; i < n; ++i) {
		omega[i]->v += omega[i]->a * dt;
		omega[i]->r += omega[i]->v * dt;
	}
}
