#include <stdlib.h>
#include <iostream>

#include "Saucer.h"
#include "LogManager.h"
#include "GameManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"

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
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        const df::EventKeyboard* p_event = dynamic_cast<const df::EventKeyboard*>(p_e);

        if (p_event->getKeyboardAction() == EventKeyboardAction::KEY_PRESSED) {
            LM.writeLog("Got pressed");
        } else if (p_event->getKeyboardAction() == EventKeyboardAction::KEY_RELEASED) {
            LM.writeLog("Got released");
        } else if (p_event->getKeyboardAction() == EventKeyboardAction::KEY_DOWN) {
            LM.writeLog("Got key down");
        }

        switch (p_event->getKey()) {
        case Keyboard::Key::A:
            LM.writeLog("Got keyboard event: A");
            break;
        case Keyboard::Key::B:
            LM.writeLog("Got keyboard event: B");
            break;
        case Keyboard::Key::C:
            LM.writeLog("Got keyboard event: C");
            break;
        case Keyboard::Key::D:
            LM.writeLog("Got keyboard event: D");
            break;
        case Keyboard::Key::Q:
            GM.setGameOver();
            break;
        case Keyboard::Key::UNDEFINED_KEY:
            LM.writeLog("Got keyboard event: undefined");
            break;
        default:
            LM.writeLog("Got keyboard event: unknow");
            break;
        }
        return 1;
    }

    if (p_e->getType() == df::MSE_EVENT) {
        const df::EventMouse* p_event = dynamic_cast<const df::EventMouse*>(p_e);

        if (p_event->getMouseAction() == EventMouseAction::CLICKED) {
            LM.writeLog("Clicked %f %f", p_event->getMousePosition().getX(), p_event->getMousePosition().getY());
        }
        if (p_event->getMouseAction() == EventMouseAction::MOVED) {
            // LM.writeLog("Move %i %i", p_event->getMousePosition().getX(), p_event->getMousePosition().getY());
        }
    }

    LM.writeLog("Ignored event %s", p_e->getType().c_str());
    return 0;
}

int Saucer::draw() {
    // DM.drawCh(getPosition(), 'H', df::Color::BLACK);
    DM.drawString(getPosition(), "Sau", df::Justification::LEFT_JUSTIFIED, df::Color::BLACK);
    return 0;
}

