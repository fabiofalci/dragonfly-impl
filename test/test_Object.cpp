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

SCENARIO( "Verify Object default altitude", "[test_Object.cpp]" ) {
    Object object;
    REQUIRE( object.getAltitude() == 2 );
}

SCENARIO( "Verify Object altitude", "[test_Object.cpp]" ) {
    Object object;
    object.setAltitude(3);
    REQUIRE( object.getAltitude() == 3 );
}

SCENARIO( "Verify Object negative altitude", "[test_Object.cpp]" ) {
    Object object;
    object.setAltitude(-2);
    REQUIRE( object.getAltitude() == 2 );
}

SCENARIO( "Verify Object invalid altitude", "[test_Object.cpp]" ) {
    Object object;
    object.setAltitude(16);
    REQUIRE( object.getAltitude() == 2 );
}
