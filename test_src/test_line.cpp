#include "test_line.h"
#include "line.h"
#include "linear_algebra.h"
#include <stdexcept>

void LineTest::ctorTest() {
    using geo::Line;
    using geo::Point3;
    using geo::Vector3;
    
    Line l1(Point3::origin(), Vector3::xAxis());
    
    CPPUNIT_ASSERT_THROW_MESSAGE("Expected exception for zero direction",
        Line(Point3::origin(), Vector3::zero()),
        std::invalid_argument);
        
    Line::createLineFromPoints(Point3::origin(), Point3(1,0,0));
    
    CPPUNIT_ASSERT_THROW_MESSAGE("Expected exception for equal points",
        Line::createLineFromPoints(Point3(1,2,3), Point3(1,2,3)),
        std::invalid_argument);
}

void LineTest::getBaseTest()
{
    using geo::Line;
    using geo::Point3;
    using geo::Vector3;
    
    Line line(Point3(1,1,1), Vector3(4,0,0));
    
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Expected base (1,1,1)", Point3(1,1,1), line.getBase());
}

void LineTest::getDirectionTest()
{
    using geo::Line;
    using geo::Point3;
    using geo::Vector3;
    
    Line line(Point3(1,1,1), Vector3::xAxis()*4);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Expected direction (1,0,0)", Vector3::xAxis(), line.getDirection());
    
    Line line2 = Line::createLineFromPoints(Point3(0,0,0), Point3(4,0,0));
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Expected direction (1,0,0)", Vector3::xAxis(), line2.getDirection());
}

void LineTest::containsTest()
{
    using geo::Line;
    using geo::Point3;
    using geo::Vector3;
    
    Line line = Line(Point3::origin(), Vector3::xAxis());
    
    CPPUNIT_ASSERT_MESSAGE("(0,0,0) should be on line", line.contains(Point3::origin()));
    CPPUNIT_ASSERT_MESSAGE("(1,0,0) should be on line", line.contains(Point3(1,0,0)));
    CPPUNIT_ASSERT_MESSAGE("(1,1,1) should not be on line", !line.contains(Point3(1,1,1)));
}

void LineTest::lineRelationTest()
{
    using geo::Line;
    using geo::Point3;
    using geo::Vector3;
    
    Line line(Point3::origin(), Vector3::xAxis());
    Line lineParallel(Point3(1,0,0), Vector3::xAxis());
    Line lineIntersecting(Point3::origin(), Vector3::yAxis());
    Line lineSkew(Point3(0,0,1), Vector3::yAxis());
    
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Lines should be equal", Line::LineRelation::EQUAL, line.lineRelation(line));
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Lines should be parallel", Line::LineRelation::PARALLEL, line.lineRelation(lineParallel));
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Lines should be intersecting", Line::LineRelation::INTERSECT, line.lineRelation(lineIntersecting));
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Lines should be skew", Line::LineRelation::SKEW, line.lineRelation(lineSkew));
}