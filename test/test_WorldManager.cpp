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

SCENARIO( "Verify WorldManager insertObject", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object obj0;
    REQUIRE( world_manager.insertObject(&obj0) == 0 );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager remove object not found", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object obj0;
    REQUIRE( world_manager.removeObject(&obj0) == -1 );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager insert and remove object", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object obj0;
    REQUIRE( world_manager.insertObject(&obj0) == 0 );
    REQUIRE( world_manager.removeObject(&obj0) == 0 );
    REQUIRE( world_manager.removeObject(&obj0) == -1 );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager get all objects empty", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    REQUIRE( world_manager.getAllObjects().isEmpty() == true );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager get all objects", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object obj0, obj1, obj2;
    world_manager.insertObject(&obj0);
    world_manager.insertObject(&obj1);
    world_manager.insertObject(&obj2);
    
    ObjectList object_list = world_manager.getAllObjects();
    REQUIRE( object_list.isEmpty() == false );
    REQUIRE( object_list.getCount() == 3 );

    world_manager.shutDown();
}
