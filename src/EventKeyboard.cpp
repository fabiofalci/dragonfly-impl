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
        case sf::Keyboard::F: return Keyboard::Key::F;
        case sf::Keyboard::G: return Keyboard::Key::G;
        case sf::Keyboard::H: return Keyboard::Key::H;
        case sf::Keyboard::I: return Keyboard::Key::I;
        case sf::Keyboard::J: return Keyboard::Key::J;
        case sf::Keyboard::K: return Keyboard::Key::K;
        case sf::Keyboard::L: return Keyboard::Key::L;
        case sf::Keyboard::M: return Keyboard::Key::M;
        case sf::Keyboard::N: return Keyboard::Key::N;
        case sf::Keyboard::O: return Keyboard::Key::O;
        case sf::Keyboard::P: return Keyboard::Key::P;
        case sf::Keyboard::Q: return Keyboard::Key::Q;
        case sf::Keyboard::R: return Keyboard::Key::R;
        case sf::Keyboard::S: return Keyboard::Key::S;
        case sf::Keyboard::T: return Keyboard::Key::T;
        case sf::Keyboard::U: return Keyboard::Key::U;
        case sf::Keyboard::V: return Keyboard::Key::V;
        case sf::Keyboard::W: return Keyboard::Key::W;
        case sf::Keyboard::X: return Keyboard::Key::X;
        case sf::Keyboard::Y: return Keyboard::Key::Y;
        case sf::Keyboard::Z: return Keyboard::Key::Z;
    
        default:
            return Keyboard::Key::UNDEFINED_KEY;
    }
}


}