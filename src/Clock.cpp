#include "Clock.h"
#include "LogManager.h"
#include <time.h>

namespace df {

Clock::Clock() {
    resetTime();
}

void Clock::resetTime() {
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    m_previous_time = spec.tv_sec * 1000000 + spec.tv_nsec / 1000;
    LM.writeLog("New clock: %ld", m_previous_time);
}

long int Clock::delta() {
    long int elapsed_time = split();
    resetTime();
    return elapsed_time;
}

long int Clock::split() const {
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);

    long int current_time = spec.tv_sec * 1000000 + spec.tv_nsec / 1000;
    long int elapsed_time = current_time - m_previous_time;

    LM.writeLog("Delta: %ld - %ld = %ld", current_time, m_previous_time, elapsed_time);

    return elapsed_time;
}

}