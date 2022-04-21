#include <catch2/catch.hpp>

#include <Object.h>

using namespace df;

SCENARIO( "Verify Object id", "[test_Object.cpp]" ) {
    Object object;
    object.setId(1);
    REQUIRE( object.getId() == 1 );
}

SCENARIO( "Verify Object type", "[test_Object.cpp]" ) {
    Object object;
    object.setType("my type");
    REQUIRE( object.getType() == "my type" );
}

SCENARIO( "Verify Object position", "[test_Object.cpp]" ) {
    Object object;
    Vector vector(1, 2);
    object.setPosition(vector);
    REQUIRE( object.getPosition().getX() == 1 );
    REQUIRE( object.getPosition().getY() == 2 );
}

SCENARIO( "Verify Object altitude", "[test_Object.cpp]" ) {
    Object object;
    object.setAltitude(1);
    REQUIRE( object.getAltitude() == 1 );
}
