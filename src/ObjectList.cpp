
#include "ObjectList.h"

namespace df {

ObjectList::ObjectList() {
}

int ObjectList::insert(Object *p_o) {
    if (m_count == MAX_OBJECTS)
        return -1;

    m_p_obj[m_count] = p_o;
    m_count++;
    return 0;
}

int ObjectList::remove(Object *p_o) {
    for (int i=0; i < MAX_OBJECTS; i++) {
        if (m_p_obj[i] == p_o) {
            m_p_obj[i] = m_p_obj[m_count - 1];
            m_count--;
            return 0;
        }
    }

    return -1;
}

void ObjectList::clear() {

}

int ObjectList::getCount() const {
    return -1;
}

bool ObjectList::isEmpty() const {
    return true;    
}

bool ObjectList::isFull() const {
    return false;    
}

}