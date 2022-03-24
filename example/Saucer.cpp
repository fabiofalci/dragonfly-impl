#include <stdlib.h>

#include "Saucer.h"
#include "LogManager.h"
#include "GameManager.h"

Saucer::Saucer() {
    setType("Saucer");
    step_count = 0;
}

int Saucer::eventHandler(const df::Event *p_e) {
    if (p_e->getType() == "STEP_EVENT") {
        LM.writeLog("Step event");

        if (++step_count == 100)
            GM.setGameOver(true);

        return 1;
    }
    LM.writeLog("Ignored event");
    return 0;
}
