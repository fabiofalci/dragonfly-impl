#include <catch2/catch.hpp>

#include <InputManager.h>
// #include <DisplayManager.h>

using namespace df;

SCENARIO( "Verify InputManager not started when init", "[test_InputManager.cpp]" ) {
    REQUIRE( IM.isStarted() == false );
}

SCENARIO( "Verify InputManager not started if DM not started", "[test_InputManager.cpp]" ) {
    IM.startUp();
    REQUIRE( IM.isStarted() == false );
}

SCENARIO( "Verify InputManager type", "[test_InputManager.cpp]" ) {
    REQUIRE( IM.getType() == "InputManager" );
}

SCENARIO( "Verify InputManager startUp shutDown", "[test_InputManager.cpp]" ) {
    // DM.startUp();
    IM.startUp();
    // REQUIRE( IM.isStarted() == true );
    IM.shutDown();
    REQUIRE( IM.isStarted() == false );
}
