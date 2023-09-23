#include <iostream>

#include "InputManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"

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
    sf::RenderWindow *renderWindow = DM.getWindow();
    renderWindow->setKeyRepeatEnabled(true);
    Manager::shutDown();
}

void InputManager::getInput() {
    sf::RenderWindow *renderWindow = DM.getWindow();
    sf::Event event;

    while (renderWindow->pollEvent(event)) {
        
        if (event.type == sf::Event::KeyPressed) {
            EventKeyboard eventKeyboard;
            // eventKeyboard.setKey();
            // eventKeyboard.setKeyboardAction();
            onEvent(&eventKeyboard);
        } 
        if (event.type == sf::Event::KeyReleased) {
            EventKeyboard eventKeyboard;
            // eventKeyboard.setKey();
            // eventKeyboard.setKeyboardAction();
            onEvent(&eventKeyboard);

        }
        if (event.type == sf::Event::MouseMoved) {
            EventMouse eventMouse;
            // eventKeyboard.setMouseButton();
            // eventKeyboard.setMouseAction();
            // eventKeyboard.setMousePosition();
            onEvent(&eventMouse);

        }
        if (event.type == sf::Event::MouseButtonPressed) {

        }
    }

}


}