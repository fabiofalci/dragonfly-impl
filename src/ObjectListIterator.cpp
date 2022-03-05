
#include "ObjectListIterator.h"

namespace df {

ObjectListIterator::ObjectListIterator() {
}

ObjectListIterator::ObjectListIterator(const ObjectList *p_list) {
    m_p_list = p_list;
    first();
}

void ObjectListIterator::first() {

}

void ObjectListIterator::next() {

}

bool ObjectListIterator::isDone() const {
    return false;
}

// Object ObjectListIterator::*currentObject() const {
//     // return *m_p_list->m_p_obj[m_index];
//     return NULL;
// }

}