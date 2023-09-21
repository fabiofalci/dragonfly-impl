
#ifndef __EVENT_KEYBOARD_H__
#define __EVENT_KEYBOARD_H__

#include <string>

#include "Event.h"

namespace df {

class EventKeyboard : public Event {

    private:
        int m_keyboard_count;

    public:
        EventKeyboard();

};

}

#endif // __EVENT_KEYBOARD_H__