#include <catch2/catch.hpp>

#include <ObjectList.h>

using namespace df;

SCENARIO( "Verify empty ObjectList isEmpty", "[test_ObjectList.cpp]" ) {
    ObjectList object_list;

    REQUIRE( object_list.isEmpty() == true );
    REQUIRE( object_list.isFull() == false );
}

SCENARIO( "Verify empty ObjectList getCount", "[test_ObjectList.cpp]" ) {
    ObjectList object_list;

    REQUIRE( object_list.getCount() == 0 );
}

SCENARIO( "Verify empty ObjectList remove", "[test_ObjectList.cpp]" ) {
    ObjectList object_list;

    Object obj0;

    REQUIRE( object_list.remove(&obj0) == -1 );
}

SCENARIO( "Verify ObjectList insert", "[test_ObjectList.cpp]" ) {
    ObjectList object_list;

    Object obj0;

    REQUIRE( object_list.insert(&obj0) == 0 );
    REQUIRE( object_list.getCount() == 1 );
}

SCENARIO( "Verify ObjectList multiple insert and remove", "[test_ObjectList.cpp]" ) {
    ObjectList object_list;

    Object obj0;
    Object obj1;
    Object obj2;
    Object obj3;
    Object obj4;

    REQUIRE( object_list.getCount() == 0 );
    
    REQUIRE( object_list.insert(&obj0) == 0 );
    REQUIRE( object_list.insert(&obj1) == 0 );
    REQUIRE( object_list.insert(&obj2) == 0 );
    REQUIRE( object_list.insert(&obj3) == 0 );
    REQUIRE( object_list.insert(&obj4) == 0 );

    REQUIRE( object_list.getCount() == 5 );

    REQUIRE( object_list.remove(&obj3) == 0 );
    REQUIRE( object_list.getCount() == 4 );
    REQUIRE( object_list.remove(&obj4) == 0 );
    REQUIRE( object_list.remove(&obj2) == 0 );
    REQUIRE( object_list.remove(&obj0) == 0 );
    REQUIRE( object_list.getCount() == 1 );
    REQUIRE( object_list.remove(&obj1) == 0 );
    REQUIRE( object_list.getCount() == 0 );

    REQUIRE( object_list.remove(&obj1) == -1 );
}

SCENARIO( "Verify full ObjectList isFull", "[test_ObjectList.cpp]" ) {
    ObjectList object_list;

    for (int i=0; i < MAX_OBJECTS + 2; i++) {
        if (i <= MAX_OBJECTS - 1) {
            REQUIRE( object_list.isFull() == false );
            Object obj;
            REQUIRE( object_list.insert(&obj) == 0 ); 
        } else {
            REQUIRE( object_list.isFull() == true );
            Object obj;
            REQUIRE( object_list.insert(&obj) == -1 ); 
            REQUIRE( object_list.getCount() == MAX_OBJECTS );
        }
    }
}

SCENARIO( "Verify ObjectList clear", "[test_ObjectList.cpp]" ) {
    ObjectList object_list;

    for (int i=0; i < MAX_OBJECTS; i++) {
        Object obj;
        object_list.insert(&obj);
    }
    REQUIRE( object_list.isFull() == true );

    object_list.clear();

    REQUIRE( object_list.getCount() == 0 );
    Object obj;
    REQUIRE( object_list.insert(&obj) == 0 ); 
    REQUIRE( object_list.getCount() == 1 );
}
