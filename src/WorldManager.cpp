#include "WorldManager.h"
#include "ObjectList.h"

namespace df {

WorldManager::WorldManager() {
    setType("WorldManager");
}

WorldManager& WorldManager::getInstance() {
    static WorldManager *p_world_manager = new WorldManager;
    return *p_world_manager;
}


int WorldManager::startUp() {
    Manager::startUp();
    return 0;
}

void WorldManager::shutDown() {
    Manager::shutDown();
}

int WorldManager::insertObject(Object *p_o) {
    return 0;
}

int WorldManager::removeObject(Object *p_o) {
    return 0;
}

ObjectList WorldManager::getAllObjects() const {
    ObjectList li;
    return li;
}

ObjectList WorldManager::objectsOfType(std::string type) const {
    ObjectList li;
    return li;
}

void WorldManager::update() {
}

int WorldManager::markForDelete(Object *p_o) {
    return 0;
}

}