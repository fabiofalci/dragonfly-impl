
#include <stdio.h>
#include "Manager.h"

int main(int argc, char *argv[]) {

    df::Manager *p_manager = new df::Manager;

    bool is_started = p_manager->isStarted();
    printf("Test %b\n", is_started);

    p_manager->startUp();
    is_started = p_manager->isStarted();
    printf("Test %b\n", is_started);

    p_manager->shutDown();
    is_started = p_manager->isStarted();
    printf("Test %b\n", is_started);

    return 0;
}