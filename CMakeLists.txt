cmake_minimum_required (VERSION 2.8.11)

project (geo)

add_definitions(-std=c++11)

include_directories("${CMAKE_SOURCE_DIR}/include")

file(GLOB SOURCES "src/*.cpp")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")
FIND_PACKAGE(CppUnit REQUIRED)

IF (CPPUNIT_FOUND)
    file(GLOB TEST_SOURCES "test_src/*.cpp")
    add_executable(testgeo ${TEST_SOURCES} ${SOURCES})
    include_directories(${CPPUNIT_INCLUDE_DIRS})
    include_directories("${CMAKE_SOURCE_DIR}/test_include")
    target_link_libraries(testgeo ${CPPUNIT_LIBRARIES})
ENDIF(CPPUNIT_FOUND)

add_library (geo SHARED src/linear_algebra.cpp)