#include "InputManager.h"

namespace df {

InputManager::InputManager() {
    setType("InputManager");
}

InputManager& InputManager::getInstance() {
    static InputManager *p_input_manager = new InputManager;
    return *p_input_manager;
}

int InputManager::startUp() {
    Manager::startUp();
    return 0;
}

void InputManager::shutDown() {
    Manager::shutDown();
}

void InputManager::getInput() {

}


}