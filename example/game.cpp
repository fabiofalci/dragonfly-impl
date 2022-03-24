
#include "LogManager.h"
#include "GameManager.h"
#include "Saucer.h"
#include "Vector.h"

void runGameManager() {
    GM.startUp();
    LM.setFlush(true);

    Saucer *saucer0 = new Saucer;
    df::Vector position0(1.0, 2.0);
    saucer0->setPosition(position0);

    Saucer *saucer1 = new Saucer;
    df::Vector position1(10.0, 35.0);
    saucer1->setPosition(position1);

    GM.run();

    GM.shutDown();
}

int main(int argc, char *argv[]) {
    runGameManager();
    return 0;
}