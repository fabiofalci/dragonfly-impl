#include "EventMouse.h"

namespace df {

EventMouse::EventMouse() {
    setType(MSE_EVENT);
}

void EventMouse::setMouseButton(Mouse::Button new_button) {
    m_mouse_button = new_button;
}

Mouse::Button EventMouse::getMouseButton() const {
    return m_mouse_button;
}

void EventMouse::setMouseAction(EventMouseAction new_action) {
    m_mouse_action = new_action;
}

EventMouseAction EventMouse::getMouseAction() const {
    return m_mouse_action;
}

void EventMouse::setMousePosition(Vector new_position) {
    m_mouse_xy = new_position;
}

Vector EventMouse::getMousePosition() const {
    return m_mouse_xy;
}

Mouse::Button EventMouse::convertButton(sf::Mouse::Button button) {
    switch (button) {
        case sf::Mouse::Left: return Mouse::Button::LEFT;
        case sf::Mouse::Right: return Mouse::Button::RIGHT;
        case sf::Mouse::Middle: return Mouse::Button::MIDDLE;
    
        default:
            return Mouse::Button::UNDEFINED_MOUSE_BUTTON;
    }
}

}