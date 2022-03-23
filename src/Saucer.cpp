#include <stdlib.h>

#include "Saucer.h"
#include "LogManager.h"

Saucer::Saucer() {
    setType("Saucer");
}

int Saucer::eventHandler(const df::Event *p_e) {
    if (p_e->getType() == "STEP_EVENT") {
        LM.writeLog("Step event");
        return 1;
    }
    LM.writeLog("Ignored event");
    return 0;
}
