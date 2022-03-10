
#include "LogManager.h"
#include "GameManager.h"

void runGameManager() {
    GM.startUp();
    LM.setFlush(true);

    GM.run();

    GM.shutDown();
}

int main(int argc, char *argv[]) {
    runGameManager();
    return 0;
}