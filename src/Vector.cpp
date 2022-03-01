
#include "Vector.h"

namespace df {

Vector::Vector(float init_x, float init_y) {
    m_x = init_x;
    m_y = init_y;
}

Vector::Vector() {
    m_x = 0;
    m_y = 0;
}

void Vector::setX(float new_x) {
    m_x = new_x;
}

float Vector::getX() const {
    return m_x;
}

void Vector::setY(float new_y) {
    m_y = new_y;
}

float Vector::getY() const {
    return m_y;
}

float Vector::getMagnitude() const {
    return 0;
}

void Vector::normalize() {

}

void Vector::scale(float s) {

}

Vector Vector::operator+(const Vector &other) const {
    return other;
}

}