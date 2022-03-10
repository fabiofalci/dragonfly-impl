#include <catch2/catch.hpp>

#include <Clock.h>

using namespace df;

SCENARIO( "Verify Clock", "[test_Clock.cpp]" ) {
    Clock *clock = new Clock;

    long int delta = clock->delta();
    REQUIRE( delta > 0 );

    long int split = clock->split();
    REQUIRE( split > 0 );

    long int split2 = clock->split();

    REQUIRE( split2 > split );
}
