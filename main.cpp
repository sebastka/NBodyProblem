#include <iostream>

#include "Point.h"
#include "Body.h"
#include "Omega.h"

int main() {
    Omega universe;
    universe.run(0.1, 0.0, 10.0);

    return 0;
}