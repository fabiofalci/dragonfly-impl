
#include <stdio.h>
// #include "Manager.h"
#include "LogManager.h"

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

    LM.startUp();
    LM.setFlush(true);
    LM.writeLog("Testing log %s\n", "first");
    LM.writeLog("Testing log another line %s = %s and %i\n", "second time", "abc", 10);
    LM.shutDown();
    return 0;
}