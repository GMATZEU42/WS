#pragma once

using time_interval = unsigned int ;

namespace timing
{
    class timer
    {
    public:
        timer(time_interval interval);
        ~timer();
        void start();
        time_interval getInterval();
    private:
        time_interval m_interval;
    };
}