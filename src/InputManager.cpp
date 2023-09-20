#include <iostream>

#include "InputManager.h"
#include "DisplayManager.h"

namespace df {

InputManager::InputManager() {
    setType("InputManager");
}

InputManager& InputManager::getInstance() {
    static InputManager *p_input_manager = new InputManager;
    return *p_input_manager;
}

int InputManager::startUp() {
    if (!DM.isStarted()) {
        std::cout << "Error! DisplayManger has not started" << std::endl;
        return -1;
    }

    sf::RenderWindow *renderWindow = DM.getWindow();
    renderWindow->setKeyRepeatEnabled(false);
    Manager::startUp();
    return 0;
}

void InputManager::shutDown() {
    Manager::shutDown();
}

void InputManager::getInput() {

}


}