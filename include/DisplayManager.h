#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__

#include <SFML/Graphics.hpp>

#include "Manager.h"

namespace df {

class DisplayManager : public Manager {

    private:
        DisplayManager();
        DisplayManager(DisplayManager const&);
        void operator=(DisplayManager const&);

    public:
        static DisplayManager& getInstance();

        int startUp();
        void shutDown();
};

}

#endif // __DISPLAY_MANAGER_H__
