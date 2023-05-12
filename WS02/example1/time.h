#pragma once

using time_interval = unsigned int ;

namespace time
{
    class timer
    {
    public:
        timer(time_interval interval);
        ~timer();
        void start();
        void stop();
    private:
        time_interval m_interval;
    };


}