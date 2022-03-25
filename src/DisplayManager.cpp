
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


}