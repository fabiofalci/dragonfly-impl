#include <catch2/catch.hpp>

#include <GameManager.h>

using namespace df;

SCENARIO( "Verify GameManager not started when init", "[test_GameManager.cpp]" ) {
    REQUIRE( GM.isStarted() == false );
}

SCENARIO( "Verify GameManager game over init", "[test_GameManager.cpp]" ) {
    REQUIRE( GM.getGameOver() == false );
    GM.setGameOver(true);
    REQUIRE( GM.getGameOver() == true );
}

SCENARIO( "Verify GameManager type", "[test_GameManager.cpp]" ) {
    REQUIRE( GM.getType() == "GameManager" );
}

SCENARIO( "Verify GameManager startUp shutDown", "[test_GameManager.cpp]" ) {
    GM.startUp();
    REQUIRE( GM.isStarted() == true );
    REQUIRE( GM.getGameOver() == false );
    GM.shutDown();
    REQUIRE( GM.isStarted() == false );
    REQUIRE( GM.getGameOver() == true );
}
