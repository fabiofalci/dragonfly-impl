
#include <stdio.h>
#include <chrono>
#include <thread>

#include "LogManager.h"
#include "GameManager.h"
#include "Clock.h"

int main(int argc, char *argv[]) {
    GM.startUp();
    LM.setFlush(true);

    LM.writeLog("Testing log %s", "first");
    LM.writeLog("Testing log another line %s = %s and %i", "second time", "abc", 10);

    df::Clock *clock = new df::Clock;
    printf("Clock delta 1: %ld\n", clock->delta());
    printf("Clock delta 2: %ld\n", clock->delta());
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    printf("Clock delta 3 (sleep 3000): %ld\n", clock->delta());

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    printf("Clock split 1 (sleep 1000): %ld\n", clock->split());
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    printf("Clock split 2 (sleep 2000): %ld\n", clock->split());
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    printf("Clock split 3 (sleep 3000): %ld\n", clock->split());

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    printf("Clock delta 5 (sleep 3000): %ld\n", clock->delta());
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    printf("Clock delta 6: (sleep 3000) %ld\n", clock->delta());
    printf("Clock delta 7: %ld\n", clock->delta());

    GM.shutDown();
    return 0;
}