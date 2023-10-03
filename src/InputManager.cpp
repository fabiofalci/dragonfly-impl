#include <iostream>

#include "InputManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
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
    sf::Keyboard::Key actionKey;

    while (renderWindow->pollEvent(event)) {
        
        if (event.type == sf::Event::KeyPressed) {
            EventKeyboard eventKeyboard;
            eventKeyboard.setKey(EventKeyboard::convertKey(event.key.code));
            if (eventKeyboard.getKey() != Keyboard::Key::UNDEFINED_KEY) {
                actionKey = event.key.code;
                eventKeyboard.setKeyboardAction(EventKeyboardAction::KEY_PRESSED);
                onEvent(&eventKeyboard);
                LM.writeLog("Sending keyboard pressed event");
            }
        } else if (event.type == sf::Event::KeyReleased) {
            EventKeyboard eventKeyboard;
            eventKeyboard.setKey(EventKeyboard::convertKey(event.key.code));
            if (eventKeyboard.getKey() != Keyboard::Key::UNDEFINED_KEY) {
                actionKey = event.key.code;
                eventKeyboard.setKeyboardAction(EventKeyboardAction::KEY_RELEASED);
                onEvent(&eventKeyboard);
                LM.writeLog("Sending keyboard released event");
            }
        } else if (event.type == sf::Event::MouseMoved) {
            EventMouse eventMouse;
            eventMouse.setMouseAction(EventMouseAction::MOVED);
            Vector vector(event.mouseMove.x, event.mouseButton.y);
            eventMouse.setMousePosition(vector);
            onEvent(&eventMouse);
            LM.writeLog("Sending mouse moved event");
        } else if (event.type == sf::Event::MouseButtonPressed) {
            EventMouse eventMouse;
            eventMouse.setMouseButton(EventMouse::convertButton(event.mouseButton.button));
            if (eventMouse.getMouseButton() != Mouse::Button::UNDEFINED_MOUSE_BUTTON) {
                eventMouse.setMouseAction(EventMouseAction::PRESSED);
                Vector vector(event.mouseButton.x, event.mouseButton.y);
                eventMouse.setMousePosition(vector);
                onEvent(&eventMouse);
                LM.writeLog("Sending mouse pressed event");
            }
        } else if (event.type == sf::Event::MouseButtonReleased) {
            EventMouse eventMouse;
            eventMouse.setMouseButton(EventMouse::convertButton(event.mouseButton.button));
            if (eventMouse.getMouseButton() != Mouse::Button::UNDEFINED_MOUSE_BUTTON) {
                eventMouse.setMouseAction(EventMouseAction::CLICKED);
                Vector vector(event.mouseButton.x, event.mouseButton.y);
                eventMouse.setMousePosition(vector);
                onEvent(&eventMouse);
                LM.writeLog("Sending mouse clicked event");
            }

        }
    }

    if (sf::Keyboard::isKeyPressed(actionKey)) {
        LM.writeLog("> Key is being pressed");
    }

}


}