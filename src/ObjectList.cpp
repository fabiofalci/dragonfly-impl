
#include "ObjectList.h"

namespace df {

ObjectList::ObjectList() {
}

int ObjectList::insert(Object *p_o) {
    if (isFull())
        return -1;

    m_p_obj[m_count] = p_o;
    m_count++;
    return 0;
}

int ObjectList::remove(Object *p_o) {
    for (int i=0; i < m_count; i++) {
        if (m_p_obj[i] == p_o) {
            m_p_obj[i] = m_p_obj[m_count - 1];
            m_count--;
            return 0;
        }
    }

    return -1;
}

void ObjectList::clear() {
    m_count = 0;
}

int ObjectList::getCount() const {
    return m_count;
}

bool ObjectList::isEmpty() const {
    return m_count == 0;    
}

bool ObjectList::isFull() const {
    return m_count == MAX_OBJECTS;
}

}