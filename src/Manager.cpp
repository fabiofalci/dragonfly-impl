#include "Manager.h"

namespace df {

    Manager::Manager() {
        setType("Manager");
    }

    Manager::~Manager() { }
    
    void Manager::setType(std::string type) {
        m_type = type;
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
    

}