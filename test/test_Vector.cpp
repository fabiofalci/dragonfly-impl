#include <catch2/catch.hpp>

#include <Vector.h>

using namespace df;

SCENARIO( "Verify Vector init", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector(1, 3);
    REQUIRE( vector->getX() == 1 );
    REQUIRE( vector->getY() == 3 );
}

SCENARIO( "Verify Vector empty init", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector();
    REQUIRE( vector->getX() == 0 );
    REQUIRE( vector->getY() == 0 );
}

SCENARIO( "Verify Vector x", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector();
    vector->setX(10);
    REQUIRE( vector->getX() == 10 );
}

SCENARIO( "Verify Vector y", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector();
    vector->setY(11);
    REQUIRE( vector->getY() == 11 );
}

SCENARIO( "Verify Vector x and y", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector;
    vector->setXY(12, 13);
    REQUIRE( vector->getX() == 12 );
    REQUIRE( vector->getY() == 13 );
}

