#include <iostream>
#include <stdlib.h>

#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "GameManager.h"
#include "LogManager.h"
#include "Saucer.h"

Saucer::Saucer() {
    setType("Saucer");
    step_count = 0;
}

int Saucer::eventHandler(const df::Event *p_e) {
    // if (p_e->getType() == "STEP_EVENT") {
    //     df::Vector pos = getPosition();
    //     pos.setX(pos.getX() + 0.06);
    //     setPosition(pos);
    //     return 1;
    // }
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        const df::EventKeyboard *p_event = dynamic_cast<const df::EventKeyboard *>(p_e);

        if (p_event->getKeyboardAction() == EventKeyboardAction::KEY_PRESSED) {
            LM.writeLog("Got pressed");
        } else if (p_event->getKeyboardAction() == EventKeyboardAction::KEY_RELEASED) {
            LM.writeLog("Got released");
        } else if (p_event->getKeyboardAction() == EventKeyboardAction::KEY_DOWN) {
            LM.writeLog("Got key down");
        }

        switch (p_event->getKey()) {
        case Keyboard::Key::W:
            LM.writeLog("Got keyboard event: W");
            setPosition(df::Vector(getPosition().getX(), getPosition().getY() - 0.1));
            break;
        case Keyboard::Key::A:
            LM.writeLog("Got keyboard event: A");
            setPosition(df::Vector(getPosition().getX() - 0.1, getPosition().getY()));
            break;
        case Keyboard::Key::S:
            LM.writeLog("Got keyboard event: S");
            setPosition(df::Vector(getPosition().getX(), getPosition().getY() + 0.1));
            break;
        case Keyboard::Key::D:
            LM.writeLog("Got keyboard event: D");
            setPosition(df::Vector(getPosition().getX() + 0.1, getPosition().getY()));
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
        const df::EventMouse *p_event = dynamic_cast<const df::EventMouse *>(p_e);

        if (p_event->getMouseAction() == EventMouseAction::CLICKED) {
            LM.writeLog("Clicked %f %f", p_event->getMousePosition().getX(), p_event->getMousePosition().getY());
        }
        if (p_event->getMouseAction() == EventMouseAction::MOVED) {
            // LM.writeLog("Move %i %i", p_event->getMousePosition().getX(), p_event->getMousePosition().getY());
        }
    }

    // LM.writeLog("Ignored event %s", p_e->getType().c_str());
    return 0;
}

int Saucer::draw() {
    // DM.drawCh(getPosition(), 'H', df::Color::BLACK);
    DM.drawString(getPosition(), "Sau", df::Justification::LEFT_JUSTIFIED, df::Color::BLACK);
    return 0;
}
