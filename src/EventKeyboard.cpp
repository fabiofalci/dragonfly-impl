#include "EventKeyboard.h"

namespace df {

EventKeyboard::EventKeyboard() {
    setType("EventKeyboard");
}

void EventKeyboard::setKey(Keyboard::Key new_key) {
    m_key_val = new_key;
}

Keyboard::Key EventKeyboard::getKey() const {
    return Keyboard::Key::UNDEFINED_KEY;
}

void EventKeyboard::setKeyboardAction(EventKeyboardAction new_action) {
    m_keyboard_action = new_action;
}

EventKeyboardAction EventKeyboard::getKeyboardAction() const {
    return EventKeyboardAction::UNDEFINED_KEYBOARD_ACTION;
}

}