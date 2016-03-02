#ifndef CURVE_H
#define CURVE_H

#include "linear_algebra.h"

namespace geo {

//! The abstract Curve class represents a finite curve in a three dimensional euclidian space.
//! Interesting concrete subclasses are BSplineCurve and Segment.
class Curve {
public:
    virtual Point3 getStart() const = 0;
    virtual Point3 getEnd() const = 0;
    virtual Point3 getMidpoint() const = 0;
    virtual Point3 getPoint(double parameter) const = 0;
    virtual double getLength() const = 0;
    virtual Vector3 firstDerivative(double parameter) const = 0;
    virtual Vector3 secondDerivative(double parameter) const = 0;
};

}

#endif
