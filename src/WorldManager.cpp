#include "WorldManager.h"
#include "LogManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

namespace df {

WorldManager::WorldManager() { setType("WorldManager"); }

WorldManager &WorldManager::getInstance() {
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

int WorldManager::insertObject(Object *p_o) { return m_updates.insert(p_o); }

int WorldManager::removeObject(Object *p_o) { return m_updates.remove(p_o); }

ObjectList WorldManager::getAllObjects() const { return m_updates; }

ObjectList WorldManager::objectsOfType(std::string type) const {
    ObjectList object_list;
    ObjectListIterator li(&m_updates);

    for (li.first(); !li.isDone(); li.next())
        if (li.currentObject()->getType() == type)
            object_list.insert(li.currentObject());

    return object_list;
}

void WorldManager::update() {
    ObjectListIterator li(&m_deletions);

    for (li.first(); !li.isDone(); li.next()) {
        m_updates.remove(li.currentObject());
        delete li.currentObject();
    }

    m_deletions.clear();

    ObjectListIterator i(&m_updates);
    for (i.first(); !i.isDone(); i.next()) {
        Vector new_pos = i.currentObject()->predictPosition();

        if (new_pos.getX() != i.currentObject()->getPosition().getX() ||
            new_pos.getY() != i.currentObject()->getPosition().getY()) {
            i.currentObject()->setPosition(new_pos);
        }
    }
}

int WorldManager::markForDelete(Object *p_o) {
    ObjectListIterator li(&m_deletions);

    for (li.first(); !li.isDone(); li.next())
        if (li.currentObject() == p_o)
            return 0;

    return m_deletions.insert(p_o);
}

int WorldManager::draw() {
    ObjectListIterator li(&m_updates);

    for (int i = 0; i <= MAX_ALTITUDE; i++) {
        for (li.first(); !li.isDone(); li.next()) {
            Object *p_obj = li.currentObject();
            if (p_obj->getAltitude() == i)
                p_obj->draw();
        }
    }

    return 0;
}

} // namespace df
