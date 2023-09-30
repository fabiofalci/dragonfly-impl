#include "EventKeyboard.h"

namespace df {

EventKeyboard::EventKeyboard() {
    setType(KEYBOARD_EVENT);
}

void EventKeyboard::setKey(Keyboard::Key new_key) {
    m_key_val = new_key;
}

Keyboard::Key EventKeyboard::getKey() const {
    return m_key_val;
}

void EventKeyboard::setKeyboardAction(EventKeyboardAction new_action) {
    m_keyboard_action = new_action;
}

EventKeyboardAction EventKeyboard::getKeyboardAction() const {
    return m_keyboard_action;
}

Keyboard::Key EventKeyboard::convertKey(sf::Keyboard::Key code) {
    switch (code) {
        case sf::Keyboard::A: return Keyboard::Key::A;
        case sf::Keyboard::B: return Keyboard::Key::B;
        case sf::Keyboard::C: return Keyboard::Key::C;
        case sf::Keyboard::D: return Keyboard::Key::D;
        case sf::Keyboard::E: return Keyboard::Key::E;
        case sf::Keyboard::Q: return Keyboard::Key::Q;
    
        default:
            return Keyboard::Key::UNDEFINED_KEY;
    }
}


}