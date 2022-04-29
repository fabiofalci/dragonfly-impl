#include <stdlib.h>

#include "Star.h"
#include "LogManager.h"
#include "GameManager.h"
#include "DisplayManager.h"

Star::Star() {
    setType("Star");
}

int Star::draw() {
    // DM.drawCh(getPosition(), 'H', df::Color::BLACK);
    DM.drawString(getPosition(), "Sta", df::Justification::LEFT_JUSTIFIED, df::Color::BLACK);
    return 0;
}

