
#ifndef __EVENT_STEP_H__
#define __EVENT_STEP_H__

#include <string>

#include "Event.h"

namespace df {

class EventStep : public Event {

    private:
        int m_step_count;

    public:
        EventStep();
        EventStep(int init_step_count);

        void setStepCount(int new_step_count);
        int getStepCount() const;

};

}

#endif // __EVENT_STEP_H__