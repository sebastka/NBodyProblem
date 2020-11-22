#include <iostream>

#include "Point.h"
#include "Body.h"
#include "Omega.h"

int main() {
    Omega universe(true);

	// Sun
	universe.add_body(new Body(
		5.0, 
		Point(0.0, 0.0, 0.0), 
      	Point(0.0, 0.0, 0.0), 
      	Point(0.0, 0.0, 0.0)
    ));

	// Planet 1
	universe.add_body(new Body(
        1.0,
        Point(0.5, 0.5, 0.0),
        Point(0.0, -0.2, 0.0),
        Point(0.0, 0.0, 0.0)
    ));

    universe.run(0.001, 0.0, 10.0);

    return 0;
}