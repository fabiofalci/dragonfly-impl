#include "Object.h"
#include "Event.h"

class Saucer : public df::Object {

    private:
        int step_count;

    public:
        Saucer();
        int eventHandler(const df::Event *p_e) override;
        int draw() override;

};