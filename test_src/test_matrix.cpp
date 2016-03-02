#include "test_matrix.h"
#include "matrix.h"

void MatrixTest::determinantTest() {
    using geo::Matrix33;
    
    const double EPSILON = 0.00001;
    
    Matrix33 m(0,1,2,3,2,1,1,1,0);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Determinant wrong", 3, m.determinant(), EPSILON);
    
    Matrix33 m2(-2,2,-3,-1,1,3,2,0,-1);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Determinant wrong", 18, m2.determinant(), EPSILON);
}