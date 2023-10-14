#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include <SFML/Window.hpp>
#include "Manager.h"

#define IM df::InputManager::getInstance()

namespace df {

class InputManager : public Manager {

    private:
        InputManager();
        InputManager(InputManager const&);

        void operator=(InputManager const&);

        void handlePressedKey(sf::Keyboard::Key key);


    public:
        static InputManager& getInstance();

        int startUp();
        void shutDown();
        void getInput();
        
};

}

#endif // __INPUT_MANAGER_H__