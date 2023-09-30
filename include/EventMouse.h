
#ifndef __EVENT_MOUSE_H__
#define __EVENT_MOUSE_H__

#include <string>

#include "Event.h"
#include "Vector.h"

enum EventMouseAction {
    UNDEFINED_MOUSE_ACTION = -1,
    CLICKED,
    PRESSED,
    MOVED,
};

namespace Mouse {
enum Button {
    UNDEFINED_MOUSE_BUTTON = -1,
    LEFT,
    RIGHT,
    MIDDLE,
};
}

namespace df {

const std::string MSE_EVENT = "df::mouse";

class EventMouse : public Event {

    private:
        Mouse::Button m_mouse_button;
        EventMouseAction m_mouse_action;
        Vector m_mouse_xy;

    public:
        EventMouse();

        void setMouseButton(Mouse::Button new_button);
        Mouse::Button getMouseButton() const;
        void setMouseAction(EventMouseAction new_action);
        EventMouseAction getMouseAction() const;
        void setMousePosition(Vector new_position);
        Vector getMousePosition() const;

};

}

#endif // __EVENT_MOUSE_H__