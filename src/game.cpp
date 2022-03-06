
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>

#include "LogManager.h"
#include "GameManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

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

void testObjectListIterator() {
    df::ObjectList *object_list = new df::ObjectList;

    df::Object *obj0 = new df::Object;
    obj0->setId(1);
    obj0->setType("Type1");
    object_list->insert(obj0);

    df::Object *obj1 = new df::Object;
    obj1->setId(2);
    obj1->setType("Type2");
    object_list->insert(obj1);

    df::Object *obj2 = new df::Object;
    obj2->setId(3);
    obj2->setType("Type3");
    object_list->insert(obj2);
    
    df::Object *obj3 = new df::Object;
    obj3->setId(4);
    obj3->setType("Type4");
    object_list->insert(obj3);

    df::Object *obj4 = new df::Object;
    obj4->setId(5);
    obj4->setType("Type5");
    object_list->insert(obj4);

    df::ObjectListIterator li(object_list);

    li.first();
    while (!li.isDone()) {
        df::Object *item = li.currentObject();
        std::cout << "The item is " << &item << std::endl;
        std::cout << "    ID is " << item->getId() << std::endl;
        std::cout << "    Type is " << item->getType() << std::endl;

        if (item->getId() == 1)
            item->setId(10);

        li.next();
    }

    li.first();
    df::Object *item = li.currentObject();
    std::cout << "The last item is " << &item << std::endl;
    std::cout << "    ID is " << item->getId() << std::endl;
    std::cout << "    Type is " << item->getType() << std::endl;
    printf("This item is %i = %i\n", &item, item->getId());
}

int main(int argc, char *argv[]) {
    // runGameManager();
    // testObjectList();
    testObjectListIterator();
    return 0;
}