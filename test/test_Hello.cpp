#include <catch2/catch.hpp>

#include <LogManager.h>

using namespace df;

SCENARIO( "Verify no argument returns Hello World", "[test_Hello.cpp]" )
{
    LM.startUp();
    REQUIRE( LM.isStarted() == true );
    LM.shutDown();
}
