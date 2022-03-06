
#ifndef __OBJECT_LIST_ITERATOR_H__
#define __OBJECT_LIST_ITERATOR_H__

#include "Object.h"
#include "ObjectList.h"

namespace df {

class ObjectList;

class ObjectListIterator {

    private:
        ObjectListIterator();
        int m_index;
        const ObjectList *m_p_list;

    public:
        ObjectListIterator(const ObjectList *p_list); 

        void first();
        void next();

        bool isDone() const;

        Object *currentObject() const;
};

}


#endif // __OBJECT_LIST_ITERATOR_H__