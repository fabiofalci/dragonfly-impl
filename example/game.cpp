
#include "LogManager.h"
#include "GameManager.h"
#include "Saucer.h"

void runGameManager() {
    GM.startUp();
    LM.setFlush(true);

    new Saucer;
    GM.run();

    GM.shutDown();
}

int main(int argc, char *argv[]) {
    runGameManager();
    return 0;
}