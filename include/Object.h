
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

#include "Event.h"
#include "Vector.h"

namespace df {

class Object {

  private:
    int m_id;
    std::string m_type;
    Vector m_position;
    int m_altitude;
    Vector m_direction;
    float m_speed;

  public:
    Object();
    virtual ~Object();

    void setId(float new_id);
    float getId() const;

    void setAltitude(float new_altitude);
    int getAltitude() const;

    void setType(std::string new_type);
    std::string getType() const;

    void setPosition(Vector new_position);
    Vector getPosition() const;

    void setDirection(Vector new_direction);
    Vector getDirection() const;

    void setSpeed(float new_speed);
    float getSpeed() const;

    void setVelocity(Vector new_velocity);
    Vector getVelocity() const;

    Vector predictPosition();

    virtual int eventHandler(const Event *p_e);

    virtual int draw();
};

} // namespace df

#endif // __OBJECT_H__
