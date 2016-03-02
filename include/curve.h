#ifndef CURVE_H
#define CURVE_H

namespace geo {
namespace geometry {

class Point3;

//! The abstract Curve class represents a finite curve in a three dimensional euclidian space.
//! Interesting concrete subclasses are BSplineCurve and Segment.
class Curve {
public:
    virtual Point3 getStart() const = 0;
    virtual Point3 getEnd() cons = 0;
    virtual Point3 getMidpoint( const = 0;
    virtual Point3 getPoint(double parameter) const = 0;
    virtual double getLength() const = 0;
    virtual Vector3 derivative(double parameter) const = 0;
    virtual Vector3 secondDerivative(double parameter) const = 0;
};

}
};

#endif