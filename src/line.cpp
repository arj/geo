#include "line.h"
#include "linear_algebra.h"
#include "matrix.h"

#include <stdexcept>

namespace geo {

Line Line::createLineFromPoints(Point3 point1, Point3 point2)
{
    if (point1 == point2)
    {
        throw std::invalid_argument("Creating line with two equal points is not possible.");
    }
    
    return Line(point1, point2 - point1);
}
    
Line::Line(Point3 base, Vector3 direction) : _base(base), _direction(direction.normalized())
{
    if (direction == Vector3::zero()) {
        throw std::invalid_argument("Creating line with a zero direction vector is not possible.");
    }
}

Point3 Line::getBase() const
{
    return _base;
}

Vector3 Line::getDirection() const
{
    return _direction;
}

bool Line::contains(const Point3& point) const
{
    if (_base == point)
    {
        return true;
    }
    
    Point3 diff = point - _base;
    return diff.normalized() == _direction;
}

Line::LineRelation Line::lineRelation(const Line& line) const
{
    if (line._direction == this->_direction)
    {
        if (line.contains(this->_base))
        {
            return LineRelation::EQUAL;
        } else {
            return LineRelation::PARALLEL;
        }
    } else {
        std::pair<Point3, Point3> pair = this->shortestDistance(line);
        
        if (pair.first == pair.second)
        {
            return LineRelation::INTERSECT;
        } else {
            return LineRelation::SKEW;
        }
    }
}

std::pair<Point3, Point3> Line::shortestDistance(const Line& line) const
{
    const Vector3 v21 = line._base - this->_base;
    const Vector3 v1xv2 = this->_direction.crossed(line._direction);
    const Matrix33 m_t(v21, line._direction, v1xv2);
    const Matrix33 m_s(v21, this->_direction, v1xv2);
    const double len_v1xv2 = v1xv2.length();
    
    if (len_v1xv2 == 0)
    {
        throw std::invalid_argument("Lines are parallel");
    }
    
    const double t = m_t.determinant() / (len_v1xv2*len_v1xv2);
    const double s = m_s.determinant() / (len_v1xv2*len_v1xv2);
    Point3 p_t = this->_base + this->_direction * t;
    Point3 p_s = line._base + line._direction * s;
    
    return std::pair<Point3, Point3>(p_t,p_s);
}

std::ostream& operator<<(std::ostream& output, const Line::LineRelation& lineRelation)
{
    // TODO Avoid type switching?!
    switch (lineRelation)
    {
        case Line::LineRelation::EQUAL:
            output << "EQUAL";
            break;
        case Line::LineRelation::INTERSECT:
            output << "INTERSECT";
            break;
        case Line::LineRelation::PARALLEL:
            output << "PARALLEL";
            break;
        case Line::LineRelation::SKEW:
            output << "SKEW";
            break;
        default:
            throw std::invalid_argument("Unknown line relation");
    }
    
    return output;
}

};