#include <iostream>

#include "DisplayManager.h"

namespace df {

DisplayManager::DisplayManager() {
    setType("DisplayManager");
    m_p_window = NULL;
}

DisplayManager::DisplayManager(DisplayManager const&) {}

void DisplayManager::operator=(DisplayManager const&) {}

DisplayManager& DisplayManager::getInstance() {
    static DisplayManager *p_display_manager = new DisplayManager;
    return *p_display_manager;
}

int DisplayManager::startUp() {
    if (m_p_window != NULL)
        return 1;

    m_p_window = new sf::RenderWindow(sf::VideoMode(WINDOW_HORIZONTAL_PIXELS_DEFAULT, WINDOW_VERTICAL_PIXELS_DEFAULT), WINDOW_TITLE_DEFAULT);
    if (!m_p_window) {
        std::cout << "Error! Unable to allocate RenderWindow" << std::endl;
        return 0;
    }
    return Manager::startUp();
}

void DisplayManager::shutDown() {
    return Manager::shutDown();
}

int DisplayManager::drawCh(Vector world_pos, char ch, Color color) const {
    return 0;
}

int DisplayManager::getHorizontal() const {
    return m_window_horizontal_chars;
}

int DisplayManager::getVertical() const {
    return m_window_vertical_chars;
}

int DisplayManager::getHorizontalPixels() const {
    return m_window_horizontal_pixels;
}

int DisplayManager::getVerticalPixels() const {
    return m_window_vertical_pixels;
}

int DisplayManager::swapBuffers() {
    if (m_p_window == nullptr)
        return 1;
    
    m_p_window->display();
    m_p_window->clear();
    return 0;
}

sf::RenderWindow* DisplayManager::getWindow() const {
    return m_p_window;
}


}