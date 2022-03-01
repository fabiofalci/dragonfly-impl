
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

#include <Vector.h>

namespace df {

class Object {

    private: 
        int m_id;
        std::string m_type;
        Vector m_position;

    public:
        Object();
        virtual ~Object();

        void setId(float new_id);
        float getId() const;

        void setType(std::string new_type);
        std::string getType() const;

        void setPosition(Vector new_position);
        Vector getPosition() const;

};

}

#endif // __OBJECT_H__