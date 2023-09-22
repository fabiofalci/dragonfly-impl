
#ifndef __EVENT_KEYBOARD_H__
#define __EVENT_KEYBOARD_H__

#include <string>

#include "Event.h"

const std::string KEYBOARD_EVENT = "df::keyboard";

enum EventKeyboardAction {
    UNDEFINED_KEYBOARD_ACTION = -1,
    KEY_PRESSED,
    KEY_RELEASED,
    KEY_DOWN,
};

namespace Keyboard {
enum Key {
    UNDEFINED_KEY = -1,
    SPACE, RETURN, ESCAPE, TAB, LEFTARROW, RIGHTARROW, UPARROW, DOWNARROW,
    PAUSE, MINUS, PLUS, TILDE, PERIOD, COMMA, SLASH, LEFTCONTROL,
    RIGHTCONTROL, LEFTSHIFT, RIGHTSHIFT, F1, F2, F3, F4, F5, F6, F7, F8,
    F9, F10, F11, F12, A, B, C, D, E, F, G, H, I , J, K, L, M, N, O, P, Q,
    R, S, T, U, V, X, Y, Z, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7,
    NUM8, NUM9, NUM0,
};
}

namespace df {

class EventKeyboard : public Event {

    private:
        Keyboard::Key m_key_val;
        EventKeyboardAction m_keyboard_action;

    public:
        EventKeyboard();

        void setKey(Keyboard::Key new_key);
        Keyboard::Key getKey() const;
        void setKeyboardAction(EventKeyboardAction new_action);
        EventKeyboardAction getKeyboardAction() const;

};

}

#endif // __EVENT_KEYBOARD_H__