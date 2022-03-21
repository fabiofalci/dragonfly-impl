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
    m_updates.clear();
    m_deletions.clear();
    return 0;
}

void WorldManager::shutDown() {
    m_updates.clear();
    m_deletions.clear();
    Manager::shutDown();
}

int WorldManager::insertObject(Object *p_o) {
    return m_updates.insert(p_o);
}

int WorldManager::removeObject(Object *p_o) {
    return m_updates.remove(p_o);
}

ObjectList WorldManager::getAllObjects() const {
    return m_updates;
}

ObjectList WorldManager::objectsOfType(std::string type) const {
    return m_updates;
}

void WorldManager::update() {
}

int WorldManager::markForDelete(Object *p_o) {
    return 0;
}

}