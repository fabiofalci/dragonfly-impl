#include <catch2/catch.hpp>

#include <ObjectListIterator.h>

using namespace df;

SCENARIO( "Verify ObjectListIterator isDone", "[test_ObjectListIterator.cpp]" ) {
    ObjectList object_list;

    ObjectListIterator li(&object_list);

    REQUIRE( li.isDone() == true );

    Object obj;
    object_list.insert(&obj);

    REQUIRE( li.isDone() == false );
}

SCENARIO( "Verify ObjectListIterator constructor sets first", "[test_ObjectListIterator.cpp]" ) {
    ObjectList object_list;

    Object obj0;
    object_list.insert(&obj0);

    Object obj1;
    object_list.insert(&obj1);

    ObjectListIterator li(&object_list);

    REQUIRE( li.currentObject() == &obj0 );
}

SCENARIO( "Verify ObjectListIterator next", "[test_ObjectListIterator.cpp]" ) {
    ObjectList object_list;

    Object obj0;
    object_list.insert(&obj0);

    Object obj1;
    object_list.insert(&obj1);

    ObjectListIterator li(&object_list);
    li.next();

    REQUIRE( li.currentObject() == &obj1 );
}

SCENARIO( "Verify ObjectListIterator isDone when iterating", "[test_ObjectListIterator.cpp]" ) {
    ObjectList object_list;

    Object obj0, obj1, obj2;
    object_list.insert(&obj0);
    object_list.insert(&obj1);
    object_list.insert(&obj2);

    ObjectListIterator li(&object_list);
    li.first();
    li.next();
    li.next();
    REQUIRE( li.isDone() == false );
    li.next();
    REQUIRE( li.isDone() == true );
}

SCENARIO( "Verify ObjectListIterator currentObject", "[test_ObjectListIterator.cpp]" ) {
    ObjectList object_list;

    Object obj0;
    object_list.insert(&obj0);

    Object obj1;
    object_list.insert(&obj1);

    ObjectListIterator li(&object_list);

    REQUIRE( li.currentObject() == &obj0 );
    li.first();
    REQUIRE( li.currentObject() == &obj0 );
    li.next();
    REQUIRE( li.currentObject() == &obj1 );
    li.next();
    REQUIRE( li.currentObject() == nullptr );
}
