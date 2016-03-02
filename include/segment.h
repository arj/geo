#ifndef CURVE_H
#define CURVE_H

#include "curve.h"

namespace geo {
namespace geometry {

class Point3;

//! The Segment class represents a finite part of a line in a three dimensional
//! euclidian space.
class Segment : public Curve {
public:
    //! Creates a new segment, i.e., a straight connection between two points.
    //! \param[in] begin The begin of the segment (parameter=0)
    //! \param[in] end The end of the segment (parameter=length)
    Segment(Point3 begin, Point3 end);

    virtual Point3 getStart() const;
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