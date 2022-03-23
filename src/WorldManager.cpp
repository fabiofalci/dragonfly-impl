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
    ObjectList object_list;
    ObjectListIterator li(&m_updates);
    
    for (li.first(); !li.isDone(); li.next()) 
        if (li.currentObject()->getType() == type) 
            object_list.insert(li.currentObject());

    return object_list;
}

void WorldManager::update() {
}

int WorldManager::markForDelete(Object *p_o) {
    ObjectListIterator li(&m_deletions);

    for (li.first(); !li.isDone(); li.next()) 
        if (li.currentObject() == p_o)
            return 0;

    return m_deletions.insert(p_o);
}

}