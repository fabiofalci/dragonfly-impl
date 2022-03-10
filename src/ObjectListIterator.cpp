#include <stdio.h>

#include "ObjectListIterator.h"

namespace df {

ObjectListIterator::ObjectListIterator() {
}

ObjectListIterator::ObjectListIterator(const ObjectList *p_list) {
    m_p_list = p_list;
    first();
}

void ObjectListIterator::first() {
    m_index = 0;
}

void ObjectListIterator::next() {
    if (m_index < m_p_list->m_count)
        m_index++;
}

bool ObjectListIterator::isDone() const {
    return m_index == m_p_list->m_count;
}

Object * ObjectListIterator::currentObject() const {
    return m_p_list->m_p_obj[m_index];
}

}