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
    REQUIRE( world_manager.removeObject(&obj0) == 0 );
    REQUIRE( world_manager.removeObject(&obj0) == -1 );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager destructor", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object *obj0 = new Object;
    delete obj0;
    REQUIRE( world_manager.removeObject(obj0) == -1 );

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
    
    ObjectList object_list = world_manager.getAllObjects();
    REQUIRE( object_list.isEmpty() == false );
    REQUIRE( object_list.getCount() == 3 );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager get objects of type", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object obj0, obj1, obj2;
    obj0.setType("CAR");
    obj1.setType("TREE");
    obj2.setType("CAR");
    
    REQUIRE( world_manager.objectsOfType("CAR").getCount() == 2 );
    REQUIRE( world_manager.objectsOfType("TREE").getCount() == 1 );
    REQUIRE( world_manager.objectsOfType("PLANE").getCount() == 0 );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager get objects of type elements", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object obj0, obj1, obj2;
    obj0.setType("CAR");
    obj1.setType("TREE");
    obj2.setType("CAR");
    
    ObjectList object_list = world_manager.objectsOfType("CAR");
    ObjectListIterator li(&object_list);
    li.first();
    REQUIRE( li.currentObject() == &obj0 );
    li.next();
    REQUIRE( li.currentObject() == &obj2 );
    li.next();
    REQUIRE( li.isDone() == true );

    world_manager.shutDown();
}

SCENARIO( "Verify WorldManager mark for delete", "[test_WorldManager.cpp]" ) {
    WorldManager &world_manager = WorldManager::getInstance();
    world_manager.startUp();

    Object obj0, obj1;

    world_manager.markForDelete(&obj0);
    REQUIRE( world_manager.markForDelete(&obj0) == 0 );
    REQUIRE( world_manager.markForDelete(&obj0) == 0 );
    REQUIRE( world_manager.markForDelete(&obj1) == 0 );

    world_manager.shutDown();
}
