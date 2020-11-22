#include <iostream>
#include <vector>
#include <math.h>

#include "Point.h"
#include "Body.h"
#include "Omega.h"

void Omega::print() {
	std::cout << "[ ";

	for (auto body : omega)
		std::cout << "[\"" << body->r.x << "\", \"" << body->r.y << "\", \"" << body->r.z << "\"], ";

	std::cout << " ], " << std::endl;

}

void Omega::run(double dt, double t_0, double t_end) {
	for(double t = t_0; t <= t_end; t += dt) {
		update_a();
		update_rv(dt);

		if(verbose)
			print();
	}
}

void Omega::update_a() {
	for (auto body1 : omega) {
		Point a = Point(0.0, 0.0, 0.0);

		for (auto body2 : omega)
			if (body1 != body2)
				a += G * (body2->m / body1->getDistanceTo(body2, true)) * (body2->r - body1->r);

		body1->setAcceleration(a);
	}
}

void Omega::update_rv(double dt) {
	for (auto body : omega) {
		body->v += body->a * dt;
		body->r += body->v * dt;
	}
}
