#ifndef CURVE_FACTORY_H
#define CURVE_FACTORY_H

namespace geo {
namespace geometry {

//! The abstract Curve class represents a finite curve in a three dimensional euclidian space.
//! Interesting concrete subclasses are BSplineCurve and Segment.
class CurveFactory {
public:
    //! Creates a polygon curve from a list of points.
    //! \warning This curve is not differentible at sharp bends.
    static Curve createPolygonCurve(const std::vector<Point3> polygon_points);
};

}
};

#endif