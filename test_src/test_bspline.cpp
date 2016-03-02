#include "test_bspline.h"
#include "bspline.h"
#include "linear_algebra.h"

#include <stdexcept>
#include <iostream>

using geo::BSpline;
using geo::Point3;
using geo::Vector3;

void BSplineTest::ctorTest() {

    BSpline bspline({0.0, 0.0, 0.5, 0.5, 1.0, 1.0}, {Point3(1,0,-1), Point3(0,0,0), Point3(1,0,1)});

    std::cout << std::endl;
    std::cout << bspline.degree() << std::endl;
    std::cout << bspline.getStart() << std::endl;
    std::cout << bspline.getEnd() << std::endl;
    std::cout << bspline.getPoint(0.0) << std::endl;
    std::cout << bspline.getPoint(0.25) << std::endl;
}

