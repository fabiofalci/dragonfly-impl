#include "EventKeyboard.h"

namespace df {

EventKeyboard::EventKeyboard() {
    setType("EventKeyboard");
}

void EventKeyboard::setKey(Keyboard::Key new_key) {

}

Keyboard::Key EventKeyboard::getKey() const {
    return Keyboard::Key::UNDEFINED_KEY;
}

void EventKeyboard::setKeyboardAction(EventKeyboardAction new_action) {

}

EventKeyboardAction EventKeyboard::getKeyboardAction() const {
    return EventKeyboardAction::UNDEFINED_KEYBOARD_ACTION;
}

}