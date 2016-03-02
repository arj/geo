#ifndef PLANE_H
#define PLANE_H

#include <utility>
#include "linear_algebra.h"

namespace geo {

//! The line class represents a geometrical line in threedimensional euclidean
//! space.
class Line {
    
public:
    //! Create a line through two points.
    //! \param[in], point1, point2 The points the line should go throw.
    //!
    //! \throws std::invalid_argument if point1 and point2 are equal.
    static Line createLineFromPoints(Point3 point1, Point3 point2);
    
    //! Create a line from a base and a direction vector.
    //! \param[in] base The base point of the line
    //! \param[in] direction The direction of the line
    //!
    //! \throws std::invalid_argument if direction is zero.
    Line(Point3 base, Vector3 direction);
    
    //! \return Returns a base point for the line.
    Point3 getBase() const;
    
    //! \return Returns a normalized direction vector for the line.
    Vector3 getDirection() const;
    
    //! \return Returns true if the given point is on the line.
    bool contains(const Point3& point) const;
    
    //! LineRelation describes the possible relations of lines.
    enum class LineRelation {
        EQUAL, //!< The lines are equal
        INTERSECT, //!< The lines do intersect at some point
        PARALLEL, //!< The lines are parallel but not equal
        SKEW //! The lines are skew, i.e., neither parallel nor do they intersect
    };
    
    //! Get the relation of this line to another line.
    LineRelation lineRelation(const Line& line) const;
    
    //! Calculates the shortest distance between this line and another.
    //! \return Returns the point of the shortest distance.
    //!   If the lines intersect, the same point is returned twice.
    //!
    //! \throws std::invalid_argument if lines are parallel.
    std::pair<Point3, Point3> shortestDistance(const Line& line) const;
private:
    Point3 _base;
    Point3 _direction;
};

std::ostream& operator<<(std::ostream& output, const Line::LineRelation& lineRelation);

};

#endif