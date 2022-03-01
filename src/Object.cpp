
#include "Object.h"

namespace df {

Object::Object() {
}

Object::~Object() {
}

void Object::setId(float new_id) {
    m_id = new_id;
}

float Object::getId() const {
    return m_id;
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

}