
#ifndef __CLOCK_H__
#define __CLOCK_H__

namespace df {

class Clock {

    private: 
        long int m_previous_time;
        void resetTime();

    public:
        Clock();

        long int delta();
        long int split() const;
};

}

#endif // __CLOCK_H__