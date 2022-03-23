#include "Object.h"
#include "Event.h"

class Saucer : public df::Object {

    public:
        Saucer();
        int eventHandler(const df::Event *p_e) override;

};