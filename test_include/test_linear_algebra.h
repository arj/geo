#ifndef TEST_LINEAR_ALGEBRA_H
#define TEST_LINEAR_ALGEBRA_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class Vector3Test : public CppUnit::TestFixture {
    
    CPPUNIT_TEST_SUITE(Vector3Test);
	CPPUNIT_TEST(ctorTest);
	CPPUNIT_TEST(operatorPlusTest);
	CPPUNIT_TEST(operatorPlusAssignTest);
	CPPUNIT_TEST(operatorMinusTest);
	CPPUNIT_TEST(operatorMinusAssignTest);
	CPPUNIT_TEST(operatorMultTest);
	CPPUNIT_TEST(operatorMultAssignTest);
	CPPUNIT_TEST(lengthTest);
	CPPUNIT_TEST(normalizeTest);
	CPPUNIT_TEST(crossedTest);
	CPPUNIT_TEST_SUITE_END();

//public:
//    void setUp(void);
//    void tearDown(void);

protected:
    void ctorTest();
    void operatorPlusTest();
    void operatorPlusAssignTest();
    void operatorMinusTest();
    void operatorMinusAssignTest();
    void operatorMultTest();
    void operatorMultAssignTest();
    void lengthTest();
    void normalizeTest();
    void crossedTest();
};

#endif