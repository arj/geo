#ifndef TEST_BSPLINE_H
#define TEST_BSPLINE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class BSplineTest : public CppUnit::TestFixture {
    
    CPPUNIT_TEST_SUITE(BSplineTest);
	CPPUNIT_TEST(ctorTest);

// private Tests
	CPPUNIT_TEST(findSpanTest);
	CPPUNIT_TEST_SUITE_END();

//public:
//    void setUp(void);
//    void tearDown(void);

protected:
    void ctorTest();
    void findSpanTest();
};

#endif
