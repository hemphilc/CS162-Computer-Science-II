/**
  * @brief Assignment 2
  * @author Corey Hemphill
  */

//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Point.h"
#include "Rectangle.h"


TEST_CASE( "Rectangle/Constructor1", "no argument constructor" ) {
    Rectangle r1;
    Point p1(0, 0);
    REQUIRE( r1.getUpperLeftVertex().isSameAs(p1) == true );
    REQUIRE( r1.getHeight() == Approx(1) );
    REQUIRE( r1.getWidth() == Approx(1) );
}


TEST_CASE( "Rectangle/Constructor2", "2 argument constructor" ) {
    Point p1(1, 2);
    Point p2(6, -2);
    Rectangle r1(p1, p2);
    REQUIRE( r1.getUpperLeftVertex().isSameAs(p1) == true );
    REQUIRE( r1.getHeight() == Approx(4) );
    REQUIRE( r1.getWidth() == Approx(5) );
}


TEST_CASE( "Rectangle/Constructor3", "3 argument constructor" ) {
    Point p1(1, 5);
    Rectangle r1(p1, 2, 4);
    REQUIRE( r1.getUpperLeftVertex().isSameAs(p1) == true );
    REQUIRE( r1.getHeight() == Approx(2) );
    REQUIRE( r1.getWidth() == Approx(4) );
}


TEST_CASE( "Rectangle/getCenter", "no argument function" ) {
    Point p1(-2, 2);
    Point p2(0, 0);
    Rectangle r1(p1, 4, 4);
    Point p3(3, 0);
    Point p4(5.5, -2.5);
    Rectangle r2(p3, 5, 5);
    REQUIRE( r1.getCenter().isSameAs(p2) == true );
    REQUIRE( r2.getCenter().isSameAs(p4) == true );
}


TEST_CASE( "Rectangle/getArea", "no argument function" ) {
    Point p1;
    Rectangle r1(p1, 7, 4);
    Rectangle r2(p1, 23, 15);
    REQUIRE( r1.getArea() == Approx(28) );
    REQUIRE( r2.getArea() == Approx(345) );
}


TEST_CASE( "Rectangle/getPerimeter", "no argument function" ) {
    Point p1;
    Rectangle r1(p1, 12, 4);
    Rectangle r2(p1, 10, 11);
    REQUIRE( r1.getPerimeter() == Approx(32) );
    REQUIRE( r2.getPerimeter() == Approx(42) );
}


TEST_CASE( "Rectangle/shift", "2 argument function" ) {
    Point p1;
    Point p2(3, 4);
    Rectangle r1(p1, 12, 7);
    r1.shift(3, 4);
    Point p3;
    Point p4(-4, -3);
    Rectangle r2(p3, 3, 3);
    r2.shift(-4, -3);
    REQUIRE( r1.getUpperLeftVertex().isSameAs(p2) == true );
    REQUIRE( r2.getUpperLeftVertex().isSameAs(p4) == true );
}


TEST_CASE( "Rectangle/contains", "1 argument function" ) {
    Point p1(0, 4);
    Rectangle r1(p1, 4, 4);
    Point p2(2, 2);
    Point p3(4, 0);
    Point p4(0, 4);
    Point p5(1, -1);
    REQUIRE( r1.contains(p2) == true );
    REQUIRE( r1.contains(p3) == true );
    REQUIRE( r1.contains(p4) == true );
    REQUIRE( r1.contains(p5) == false );
}
