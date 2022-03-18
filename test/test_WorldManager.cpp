#include <catch2/catch.hpp>

#include <WorldManager.h>

using namespace df;

SCENARIO( "Verify WorldManager init", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    REQUIRE( world_manager.isStarted() == false );
    REQUIRE( world_manager.getType() == "WorldManager");

    REQUIRE( world_manager.getAllObjects().isEmpty() == true );
    REQUIRE( world_manager.objectsOfType("dummy").isEmpty() == true );
}

SCENARIO( "Verify WorldManager startUp and shutDown", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    REQUIRE( world_manager.isStarted() == true );
    REQUIRE( world_manager.getAllObjects().isEmpty() == true );
    REQUIRE( world_manager.objectsOfType("dummy").isEmpty() == true );

    world_manager.shutDown();
    REQUIRE( world_manager.isStarted() == false );
}
