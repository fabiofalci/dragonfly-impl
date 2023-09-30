#include <stdlib.h>

#include "Saucer.h"
#include "LogManager.h"
#include "GameManager.h"
#include "DisplayManager.h"

Saucer::Saucer() {
    setType("Saucer");
    step_count = 0;
}

int Saucer::eventHandler(const df::Event *p_e) {
    if (p_e->getType() == "STEP_EVENT") {
        // df::Vector position(getPosition().getX() + 1.2, getPosition().getY() + 2.9);
        // setPosition(position);
        // step_count++;
        // LM.writeLog("Moved object to (%f, %f) step count %i", getPosition().getX(), getPosition().getY(), step_count);
        // if (step_count == 100)
        //     GM.setGameOver(true);

        return 1;
    }
    if (p_e->getType() == "EventKeyboard") {

        LM.writeLog("Got keyboard event");
        return 1;
    }
    LM.writeLog("Ignored event %s", p_e->getType().c_str());
    return 0;
}

int Saucer::draw() {
    // DM.drawCh(getPosition(), 'H', df::Color::BLACK);
    DM.drawString(getPosition(), "Sau", df::Justification::LEFT_JUSTIFIED, df::Color::BLACK);
    return 0;
}

