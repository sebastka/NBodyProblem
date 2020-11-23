#include "Point.h"
#include "Body.h"
#include "Omega.h"

int main() {
	/*
	**	universe(bool verbose, bool save)
	**		verbose: print to stdout
	**		dave: save to out.csv
	*/
    Omega universe(true, true);

	// Sun: mass = 5, is still and placed at the origin
	universe.add_body(new Body(
		5.0,
		Point(0.0, 0.0, 0.0), 
		Point(0.0, 0.0, 0.0), 
		Point(0.0, 0.0, 0.0)
	));

	// Planet 1: mass = 1
	universe.add_body(new Body(
		1.0,
		Point(0.5, 0.5, 0.0),
		Point(0.0, -0.2, 0.0),
		Point(0.0, 0.0, 0.0)
	));

	// run(delta t, t_0 and t_end)
    universe.run(0.001, 0.0, 10.0);

    return 0;
}