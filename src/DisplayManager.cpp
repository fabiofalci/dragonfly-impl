
#include "DisplayManager.h"

namespace df {

DisplayManager::DisplayManager() {
    setType("DisplayManager");
}

DisplayManager::DisplayManager(DisplayManager const&) {}

void DisplayManager::operator=(DisplayManager const&) {}

DisplayManager& DisplayManager::getInstance() {
    static DisplayManager *p_display_manager = new DisplayManager;
    return *p_display_manager;
}

int DisplayManager::startUp() {
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
    return 0;
}

sf::RenderWindow* DisplayManager::getWindow() const {
    return m_p_window;
}


}