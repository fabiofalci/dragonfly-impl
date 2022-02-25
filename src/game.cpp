
#include <stdio.h>
#include <chrono>
#include <thread>

#include "LogManager.h"
#include "GameManager.h"
#include "Clock.h"

int main(int argc, char *argv[]) {
    GM.startUp();
    LM.setFlush(true);

    GM.run();

    GM.shutDown();
    return 0;
}