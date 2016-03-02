#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class MatrixTest : public CppUnit::TestFixture {
    
    CPPUNIT_TEST_SUITE(MatrixTest);
	// CPPUNIT_TEST(ctorTest);
	CPPUNIT_TEST(determinantTest);
	CPPUNIT_TEST_SUITE_END();

//public:
//    void setUp(void);
//    void tearDown(void);

protected:
    //void ctorTest();
    void determinantTest();
};

#endif