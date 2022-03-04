
#include <stdio.h>
#include <chrono>
#include <thread>

#include "LogManager.h"
#include "GameManager.h"
#include "ObjectList.h"

void runGameManager() {
    GM.startUp();
    LM.setFlush(true);

    GM.run();

    GM.shutDown();
}

void testObjectList() {
    df::ObjectList *object_list = new df::ObjectList;

    printf("ObjectList count: %i\n", object_list->getCount());

    df::Object *obj0 = new df::Object;
    df::Object *obj1 = new df::Object;
    df::Object *obj2 = new df::Object;
    df::Object *obj3 = new df::Object;
    df::Object *obj4 = new df::Object;

    printf("ObjectList remove: %i\n", object_list->remove(obj0));
    printf("ObjectList insert: %i\n", object_list->insert(obj0));
    printf("ObjectList count: %i\n", object_list->getCount());
    printf("ObjectList insert: %i\n", object_list->insert(obj1));
    printf("ObjectList insert: %i\n", object_list->insert(obj2));
    printf("ObjectList insert: %i\n", object_list->insert(obj3));
    printf("ObjectList insert: %i\n", object_list->insert(obj4));
    printf("ObjectList count: %i\n", object_list->getCount());
    printf("ObjectList remove: %i\n", object_list->remove(obj3));
    printf("ObjectList count: %i\n", object_list->getCount());
    printf("ObjectList remove: %i\n", object_list->remove(obj3));
    printf("ObjectList count: %i\n", object_list->getCount());
    printf("ObjectList remove: %i\n", object_list->remove(obj1));
    printf("ObjectList count: %i\n", object_list->getCount());

    for (int i=0; i < 5002; i++) {
        int success = object_list->insert(new df::Object);
        if (success == -1) {
            printf("List is full index %i, count %i\n", i, object_list->getCount());
        }
    }
}

int main(int argc, char *argv[]) {
    // runGameManager();
    testObjectList();
    return 0;
}