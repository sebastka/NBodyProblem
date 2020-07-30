#ifndef OMEGA_H
#define OMEGA_H

#include <vector>
#include "Body.h"

class Omega {
	private:
		std::vector<Body*> omega;
		double n, t;

		const double G = 1.0;

	public:
		Omega();
		void run(double dt, double t_0, double t_end);
		void update_a();
		void update_rv(double dt);

    	double getDistance(const Body* a, const Body* b, bool squared = false) const;

    	void debug();
};

#endif