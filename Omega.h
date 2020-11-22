#ifndef OMEGA_H
#define OMEGA_H

#include <vector>
#include <fstream>
#include "Body.h"

class Omega {
	private:
		std::vector<Body*> omega;
		bool verbose, save;
		const double G = 1.0;

		std::ofstream handle;

		void update_a();
		void update_rv(double dt);
    	void print();
		void write();

	public:
		Omega(bool verbose = false, bool save = false);
		void add_body(Body* b) { omega.push_back(b); };
		void run(double dt, double t_0, double t_end);
};

#endif