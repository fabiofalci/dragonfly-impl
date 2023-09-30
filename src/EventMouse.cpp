#include "EventMouse.h"

namespace df {

EventMouse::EventMouse() {
    setType(MSE_EVENT);
}

void EventMouse::setMouseButton(Mouse::Button new_button) {

}

Mouse::Button EventMouse::getMouseButton() const {
    return Mouse::Button::UNDEFINED_MOUSE_BUTTON;

}

void EventMouse::setMouseAction(EventMouseAction new_action) {

}

EventMouseAction EventMouse::getMouseAction() const {
    return EventMouseAction::UNDEFINED_MOUSE_ACTION;
}

void EventMouse::setMousePosition(Vector new_position) {

}

Vector EventMouse::getMousePosition() const {
    Vector vector(0, 0);
    return vector;
}

}