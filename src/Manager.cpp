#include "Manager.h"
#include "ObjectList.h"
#include "WorldManager.h"

namespace df {

Manager::Manager() {
    setType("Manager");
    m_is_started = false;
}

Manager::~Manager() { }

void Manager::setType(std::string type) {
    m_type = type;
}

std::string Manager::getType() const {
    return m_type;
}

int Manager::startUp() {
    m_is_started = true;
    return -0;
}

void Manager::shutDown() {
    m_is_started = false;
}

bool Manager::isStarted() const {
    return m_is_started;
}
    
int Manager::onEvent(const Event *p_event) const {
    int count = 0;

    ObjectList all_objects = WM.getAllObjects();
    ObjectListIterator li(&all_objects);

    for (li.first(); !li.isDone(); li.next()) {
        li.currentObject()->eventHandler(p_event);
        count++;
    }

    return count;
}

}