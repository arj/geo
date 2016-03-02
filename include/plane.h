#ifndef PLANE_H
#define PLANE_H

namespace geo {
namespace geometry {

class Point3;
class Line;

class IntersectionResult {
public:
    enum class IntersectionResultType {
      Void,
      Point3,
      Line,
      Plane
    };
    
    static IntersectionResult makeVoid();
    static IntersectionResult makePoint3(const Point3 p);
    static IntersectionResult makeLine(const Line l);
    static IntersectionResult makePlane(const Plane p);

    bool isVoid();
    bool isPoint3();
    bool isLine();
    bool isPlane();
private:
    IntersectionResultType();
    
    IntersectionResultType _result_type;
};

//! The Plane class represents a geometrical plane in
//! a three dimensional euclidean space.
class Plane {
  
public:
    //! Create a plane by three collinear points.
    //! \param[in] p1,p2,p3 Three points that are collinear.
    //!
    //! \throws geo::geometry::IllegalArgumentException
    Plane(Point3 point1, Point3 point2, Point3 point3);
    
    //! Create a plane by a line and a point.
    //! \param[in] l The line which is embedded in the plane
    //! \param[in] p The point which is embedded in the plane
    //!
    //! \throws geo::geometry::IllegalArgumentException
    Plane(Line line, Point3 point);
    
    //! Create a plane by two parallel lines or two intersecting lines.
    //! \param[in] l1,l2 The parallel or intersecting lines that define a plane
    //!
    //! \throws geo::geometry::IllegalArgumentException
    Plane(Line line1, Line line2);
    
    //! Returns the minimal distance of a point to the plane.
    //! \param[in] p The point to calculate the distance from.
    //! \return The distance of the point to the plane.
    double distanceToPoint(const Point3 point) const;
    
    //! Calculates the intersection of the line and the plane.
    //! \param[in] l The line to check the intersection with.
    //! \return The result of the intersection.
    IntersectionResult intersection(const Line line) const;
    
    //! Calculates the intersection of two planes.
    //! \param[in] l The line to check the intersection with.
    //! \return The result of the intersection.
    IntersectionResult intersection(const Plane plane) const;
    
    //! \return Return the normalized normal vector of the plane.
    Vector3 normal() const;
    
    //! Moves the plane in direction of the normal vector.
    //! The plane is updated in-place. For a functional method see Plane::movedBy.
    //! \param[in] distance The distance the plane is moved.
    void moveBy(double distance);
    
    //! Returns a copy of the plane that is parallel to the existing plane
    //! with specific distance.
    //! For an in-place update see Plane::moveBy.
    //! \param[in] distance The distance the plane is moved.
    //! \return The new plane.
    Plane movedBy(double distance) const;
    
    //! Write plane equation in general form, i.e., \f$ax + by + cz + d = 0\f$
    //! to the output stream.
    //! \param[in] output The output stream to write to.
    //! \param[in] plane The plane to write.
    //! \return Returns the output stream for chaining.
    friend ostream &operator<<(ostream &output, const Plane& plane);
private:
    double _a;
    double _b;
    double _c;
    double _d;
};

}
};

#endif