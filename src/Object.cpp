
#include "Object.h"
#include "WorldManager.h"

namespace df {

Object::Object() {
    WM.insertObject(this);
    setAltitude(df::MAX_ALTITUDE / 2);
}

Object::~Object() {
    WM.removeObject(this);
}

void Object::setId(float new_id) {
    m_id = new_id;
}

float Object::getId() const {
    return m_id;
}

void Object::setAltitude(float new_altitude) {
    if (new_altitude >= 0 && new_altitude <= df::MAX_ALTITUDE)
        m_altitude = new_altitude;
}

int Object::getAltitude() const {
    return m_altitude;
}

void Object::setType(std::string new_type) {
    m_type = new_type;
}

std::string Object::getType() const {
    return m_type;
}

void Object::setPosition(Vector new_pos) {
    m_position = new_pos;
}

Vector Object::getPosition() const {
    return m_position;
}

int Object::eventHandler(const Event *p_e) {
    return 0;
}

int Object::draw() {
    return 0;
}

}