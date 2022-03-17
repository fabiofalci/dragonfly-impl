#include <catch2/catch.hpp>

#include <EventStep.h>

using namespace df;

SCENARIO( "Verify EventStep empty constructor", "[test_EventStep.cpp]" ) {
    EventStep event_step;

    REQUIRE( event_step.getStepCount() == 0 );
}

SCENARIO( "Verify EventStep constructor", "[test_EventStep.cpp]" ) {
    EventStep event_step(10);

    REQUIRE( event_step.getStepCount() == 10 );
}

SCENARIO( "Verify EventStep type", "[test_EventStep.cpp]" ) {
    EventStep event_step;

    REQUIRE( event_step.getType() == "STEP_EVENT" );
}

SCENARIO( "Verify EventStep step count", "[test_EventStep.cpp]" ) {
    EventStep event_step;

    event_step.setStepCount(1);
    REQUIRE( event_step.getStepCount() == 1 );

    event_step.setStepCount(2);
    REQUIRE( event_step.getStepCount() == 2 );

    event_step.setStepCount(1101);
    REQUIRE( event_step.getStepCount() == 1101 );
}
