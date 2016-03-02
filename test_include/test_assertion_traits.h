#ifndef TEST_ASSSERTION_TRAITS_H
#define TEST_ASSSERTION_TRAITS_H

#include <cppunit/TestAssert.h>
#include <sstream>
#include "linear_algebra.h"
#include "line.h"

namespace CPPUNIT_NS {

// template<>
// struct assertion_traits<geo::Point3>
// {
//     static bool equal(const geo::Point3& point1, const geo::Point3& point2 )
//     {
//         return point1 == point2;
//     }
 
//     static std::string toString(const geo::Point3& point)
//     {
//         OStringStream output;
//         output << "P(";
//         output << point.x << ",";
//         output << point.y << ",";
//         output << point.z;
//         output << ")";
//         return output.str();
//   }
// };

template<>
struct assertion_traits<geo::Line::LineRelation>
{
    static bool equal(const geo::Line::LineRelation& lineRelation1,
        const geo::Line::LineRelation& lineRelation2 )
    {
        return lineRelation1 == lineRelation2;
    }
 
    static std::string toString(const geo::Line::LineRelation& lineRelation)
    {
        OStringStream output;
        output << lineRelation;
        return output.str();
  }
};

template<>
struct assertion_traits<geo::Vector3>
{
    static bool equal(const geo::Vector3& vector1, const geo::Vector3& vector2 )
    {
        return vector1 == vector2;
    }
 
    static std::string toString(const geo::Vector3& vector)
    {
        OStringStream output;
        output << vector;
        return output.str();
  }
};
 
};
 
#endif