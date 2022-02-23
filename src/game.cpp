
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

    df::LogManager &log_manager = df::LogManager::getInstance();
    log_manager.startUp();
    log_manager.writeLog("Testing log");
    log_manager.shutDown();
    return 0;
}