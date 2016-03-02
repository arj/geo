#ifndef TEST_LINE_H
#define TEST_LINE_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class LineTest : public CppUnit::TestFixture {
    
    CPPUNIT_TEST_SUITE(LineTest);
	CPPUNIT_TEST(ctorTest);
	CPPUNIT_TEST(getBaseTest);
	CPPUNIT_TEST(getDirectionTest);
	CPPUNIT_TEST(containsTest);
	CPPUNIT_TEST(lineRelationTest);
	CPPUNIT_TEST(firstDerivativeTest);
	CPPUNIT_TEST(secondDerivativeTest);
	CPPUNIT_TEST_SUITE_END();

//public:
//    void setUp(void);
//    void tearDown(void);

protected:
    void ctorTest();
    void getBaseTest();
	void getDirectionTest();
    void containsTest();
    void lineRelationTest();
	void firstDerivativeTest();
	void secondDerivativeTest();
};

#endif
