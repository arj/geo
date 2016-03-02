#include "test_linear_algebra.h"
#include "linear_algebra.h"

#include <cmath>

void Vector3Test::ctorTest() {
    using geo::Vector3;
    Vector3 v(1,2,3);
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 1, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 2, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 3, v.z, EPSILON);
}

void Vector3Test::operatorPlusTest() {
    using geo::Vector3;
    
    Vector3 v1(1,2,3);
    Vector3 v2(0.1,0.2,0.3);
    
    Vector3 v = v1 + v2;
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 1.1, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 2.2, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 3.3, v.z, EPSILON);
}

void Vector3Test::operatorPlusAssignTest() {
    using geo::Vector3;
    
    Vector3 v(1,2,3);
    Vector3 v2(0.1,0.2,0.3);
    
    v += v2;
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 1.1, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 2.2, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 3.3, v.z, EPSILON);
}

void Vector3Test::operatorMinusTest() {
    using geo::Vector3;
    
    Vector3 v1(1.1,2.2,3.3);
    Vector3 v2(0.1,0.2,0.3);
    
    Vector3 v = v1 - v2;
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 1, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 2, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 3, v.z, EPSILON);
}

void Vector3Test::operatorMinusAssignTest() {
    using geo::Vector3;
    
    Vector3 v(1.1,2.2,3.3);
    Vector3 v2(0.1,0.2,0.3);
    
    v -= v2;
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 1, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 2, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 3, v.z, EPSILON);
}

void Vector3Test::operatorMultTest() {
    using geo::Vector3;
    
    Vector3 v1(1,2,3);
    
    Vector3 v = v1 * 0.1;
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 0.1, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 0.2, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 0.3, v.z, EPSILON);
}

void Vector3Test::operatorMultAssignTest() {
    using geo::Vector3;
    
    Vector3 v(1,2,3);
    
    v *= 0.1;
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 0.1, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 0.2, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 0.3, v.z, EPSILON);
}

void Vector3Test::normalizeTest()
{
    using geo::Vector3;
    
    Vector3 v(3,0,0);
    const double EPSILON = 0.00001;
    
    v.normalize();
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 1.0, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 0.0, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 0.0, v.z, EPSILON);
    
    v = Vector3(0,3,0);
    v.normalize();
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 0.0, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 1.0, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 0.0, v.z, EPSILON);
    
    v = Vector3(0,0,3);
    v.normalize();
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 0.0, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 0.0, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 1.0, v.z, EPSILON);
    
    v = Vector3(1,2,3);
    int const len = v.length();
    v.normalize();
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 1.0/len, v.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("y not correct", 2.0/len, v.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("z not correct", 3.0/len, v.z, EPSILON);
}

void Vector3Test::lengthTest()
{
    using geo::Vector3;
    
    const double EPSILON = 0.00001;
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Length not correct", 5, Vector3(5,0,0).length(), EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Length not correct", 5, Vector3(0,5,0).length(), EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Length not correct", 5, Vector3(0,0,5).length(), EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Length not correct", std::sqrt(1+4+9), Vector3(1,2,3).length(), EPSILON);
}

void Vector3Test::crossedTest()
{
    using geo::Vector3;
    
    const double EPSILON = 0.00001;
    
    Vector3 a(1,2,3);
    Vector3 b(-7,8,9);
    
    Vector3 res = a.crossed(b);
    
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", -6, res.x, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", -30, res.y, EPSILON);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("x not correct", 22, res.z, EPSILON);
}