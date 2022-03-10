#include <catch2/catch.hpp>

#include <GameManager.h>

using namespace df;

SCENARIO( "Verify GameManager isStarted", "[test_GameManager.cpp]" ) {
    REQUIRE( GM.isStarted() == false );
}
