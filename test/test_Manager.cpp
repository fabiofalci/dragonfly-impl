#include <catch2/catch.hpp>

#include <Manager.h>

using namespace df;

SCENARIO( "Verify Manager not started when init", "[test_Manager.cpp]" ) {
    Manager manager;
    REQUIRE( manager.isStarted() == false );
}

SCENARIO( "Verify Manager type", "[test_Manager.cpp]" ) {
    Manager manager;
    REQUIRE( manager.getType() == "Manager" );
}

SCENARIO( "Verify Manager startUp shutDown", "[test_Manager.cpp]" ) {
    Manager manager;
    manager.startUp();
    REQUIRE( manager.isStarted() == true );
    manager.shutDown();
    REQUIRE( manager.isStarted() == false );
}
