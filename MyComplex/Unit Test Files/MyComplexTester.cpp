
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "MyComplex.h"
#include <cmath>
#include <sstream>

using namespace std;

TEST_CASE( "Complex/Construct1", "0-arg constructor" ) {
    MyComplex c;
    REQUIRE( c.getRealPart() == Approx(0) );
    REQUIRE( c.getComplexPart() == Approx(0) );
}

TEST_CASE( "Complex/Construct2", "1-arg constructor" ) {
    MyComplex c(4);
    REQUIRE( c.getRealPart() == Approx(4) );
    REQUIRE( c.getComplexPart() == Approx(0) );
}

TEST_CASE( "Complex/Construct3", "2-arg constructor" ) {
    MyComplex c(4.3, -2);
    REQUIRE( c.getRealPart() == Approx(4.3) );
    REQUIRE( c.getComplexPart() == Approx(-2) );
}

TEST_CASE( "Complex/Index", "Index Operators" ) {
    MyComplex c;
    c[0] = 4;
    c[1] = -2;
    REQUIRE( c[0] == Approx(4) );
    REQUIRE( c[1] == Approx(-2) );
}

TEST_CASE( "Complex/AddSubt", "Addition and Subtraction" ) {
    MyComplex c1(5, 1);
    MyComplex c2(3, 2);
    MyComplex c3 = c1 + c2;
    REQUIRE( c3.getRealPart() == Approx(8) );
    REQUIRE( c3.getComplexPart() == Approx(3) );
    MyComplex c4 = c1 - c2;
    REQUIRE( c4.getRealPart() == Approx(2) );
    REQUIRE( c4.getComplexPart() == Approx(-1) );
}

TEST_CASE( "Complex/MultDiv", "Multiplication and Division" ) {
    MyComplex c1(2, 4);
    MyComplex c2(6, -2);
    MyComplex c3 = c1 * c2;
    REQUIRE( c3.getRealPart() == Approx(20) );
    REQUIRE( c3.getComplexPart() == Approx(20) );
    MyComplex c4 = c1 / c2;
    REQUIRE( c4.getRealPart() == Approx(.1) );
    REQUIRE( c4.getComplexPart() == Approx(.7) );
}

TEST_CASE( "Complex/AddAssign", "Addition Assignment" ) {
    MyComplex c1(5, 1);
    MyComplex c2(3, 2);
    c1 += c2;
    REQUIRE( c1.getRealPart() == Approx(8) );
    REQUIRE( c1.getComplexPart() == Approx(3) );
}

TEST_CASE( "Complex/SubAssign", "Subtraction Assignment" ) {
    MyComplex c1(5, 1);
    MyComplex c2(3, 2);
    c1 -= c2;
    REQUIRE( c1.getRealPart() == Approx(2) );
    REQUIRE( c1.getComplexPart() == Approx(-1) );
}

TEST_CASE( "Complex/MultAssign", "Multiplcation Assignment" ) {
    MyComplex c1(2, 4);
    MyComplex c2(6, -2);
    c1 *= c2;
    REQUIRE( c1.getRealPart() == Approx(20) );
    REQUIRE( c1.getComplexPart() == Approx(20) );
}

TEST_CASE( "Complex/DivAssign", "Division Assignment" ) {
    MyComplex c1(2, 4);
    MyComplex c2(6, -2);
    c1 /= c2;
    REQUIRE( c1.getRealPart() == Approx(.1) );
    REQUIRE( c1.getComplexPart() == Approx(.7) );
}

TEST_CASE( "Complex/Increment", "Pre and Post Increment" ) {
    MyComplex c1(5);
    REQUIRE( (c1++).getRealPart() == Approx(5) );
    REQUIRE( c1.getRealPart() == Approx(6) );

    MyComplex c2(5);
    REQUIRE( (++c2).getRealPart() == Approx(6) );
    REQUIRE( c2.getRealPart() == Approx(6) );
}

TEST_CASE( "Complex/Decrement", "Pre and Post Decrement" ) {
    MyComplex c1(5);
    REQUIRE( (c1--).getRealPart() == Approx(5) );
    REQUIRE( c1.getRealPart() == Approx(4) );

    MyComplex c2(5);
    REQUIRE( (--c2).getRealPart() == Approx(4) );
    REQUIRE( c2.getRealPart() == Approx(4) );
}

TEST_CASE( "Complex/Negative", "Unary Negation" ) {
    MyComplex c(4, -2);
    MyComplex c2 = -c;

    REQUIRE( c2.getRealPart() == Approx(-4) );
    REQUIRE( c2.getComplexPart() == Approx(2) );

    //Verify original is unmodified
    REQUIRE( c.getRealPart() == Approx(4) );
    REQUIRE( c.getComplexPart() == Approx(-2) );
}

TEST_CASE( "Complex/Insertion", "Stream Insertion" ) {
    MyComplex c(-4, -2);
    MyComplex c2(4, 2);

    stringstream s1;
    s1 << c;
    REQUIRE( s1.str() == "-4 - 2i" );

    stringstream s2;
    s2 << c2;
    REQUIRE( s2.str() == "4 + 2i" );
}

TEST_CASE( "Complex/Extraction", "Stream Extraction" ) {
    MyComplex c;
    MyComplex c2;
    char extra;
    //read in two consecutive complex numbers followed by a char
    stringstream s1("-4 - 2i 4 + 2i x");
    s1 >> c >> c2 >> extra;

    REQUIRE( c.getRealPart() == Approx(-4) );
    REQUIRE( c.getComplexPart() == Approx(-2) );
    REQUIRE( c2.getRealPart() == Approx(4) );
    REQUIRE( c2.getComplexPart() == Approx(2) );

    REQUIRE( extra == 'x');
}

TEST_CASE( "Complex/AddToDouble", "Add with a double" ) {
    MyComplex c1(2, 4);
    MyComplex c2 = c1 + 3.5;

    REQUIRE( c2.getRealPart() == Approx(5.5) );
    REQUIRE( c2.getComplexPart() == Approx(4) );

    MyComplex c3 = 3.5 + c1;
    REQUIRE( c3.getRealPart() == Approx(5.5) );
    REQUIRE( c3.getComplexPart() == Approx(4) );

    //Verify originl unchanged
    REQUIRE( c1.getRealPart() == Approx(2) );
}

