#include <catch2/catch.hpp>

#include <Object.h>

using namespace df;

SCENARIO( "Verify Object id", "[test_Object.cpp]" ) {
    Object *object = new Object;
    object->setId(1);
    REQUIRE( object->getId() == 1 );
}

SCENARIO( "Verify Object type", "[test_Object.cpp]" ) {
    Object *object = new Object;
    object->setType("my type");
    REQUIRE( object->getType() == "my type" );
}

SCENARIO( "Verify Object position", "[test_Object.cpp]" ) {
    Object *object = new Object;
    Vector *vector = new Vector(1, 2);
    object->setPosition(*vector);
    REQUIRE( object->getPosition().getX() == 1 );
    REQUIRE( object->getPosition().getY() == 2 );
}
