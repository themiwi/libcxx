#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>

class Clock
{
    typedef std::chrono::nanoseconds                 duration;
    typedef duration::rep                            rep;
    typedef duration::period                         period;
    typedef std::chrono::time_point<Clock, duration> time_point;
    static const bool is_monotonic =                 false;

    static time_point now();
};

#endif  // CLOCK_H
