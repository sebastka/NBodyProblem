#ifndef BODY_H
#define BODY_H

#include "Point.h"

class Body {
	public:
		double m;
		Point r, v, a;

		Body(double m, Point r, Point v, Point a) : m(m), r(r), v(v), a(a) {}
		void setAcceleration(Point acceleration) { a =  acceleration; };
		double getDistanceTo(Body* b, bool squared = false) const;
};

#endif