#ifndef OMEGA_H
#define OMEGA_H

#include <vector>
#include "Body.h"

class Omega {
	private:
		std::vector<Body*> omega;
		bool verbose;
		const double G = 1.0;

		void update_a();
		void update_rv(double dt);
    	void print();

	public:
		Omega(bool verbose = false) : verbose(verbose) {};
		void add_body(Body* b) { omega.push_back(b); };
		void run(double dt, double t_0, double t_end);
};

#endif