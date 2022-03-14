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

SCENARIO( "Verify Vector magnitude", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector(1, 1);
    REQUIRE( vector->getMagnitude() == Approx(1.41421f) );

    vector->setXY(30, 2);
    REQUIRE(vector->getMagnitude() == Approx(30.06659f) );

    vector->setXY(0, 0);
    REQUIRE(vector->getMagnitude() == 0 );
}

SCENARIO( "Verify Vector scale", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector(1, 1);
    vector->scale(10);

    REQUIRE( vector->getX() == 10 );
    REQUIRE( vector->getY() == 10 );

    vector->setXY(5, 10);
    vector->scale(2);
    REQUIRE( vector->getX() == 10 );
    REQUIRE( vector->getY() == 20 );
}

SCENARIO( "Verify Vector normalize", "[test_Vector.cpp]" ) {
    Vector *vector = new Vector(1, 1);
    vector->normalize();

    REQUIRE( vector->getX() == Approx(0.70711f) );
    REQUIRE( vector->getY() == Approx(0.70711f) );

    vector->setXY(10, 20);
    vector->normalize();
    REQUIRE( vector->getX() == Approx(0.44721f) );
    REQUIRE( vector->getY() == Approx(0.89442f) );
}

