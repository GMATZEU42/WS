#include "timing.h"

#include <iostream>
#include <chrono>
#include <thread>

namespace timing
{
    timer::timer(time_interval t)
    {
        std::cout << "Timer constructor\n";
        m_interval = t;
    };
    
    timer::~timer()
    {
        std::cout << "Timer destructor\n";
    };

    void timer::start()
    {
        std::cout << "Timer start!\n";        
        std::this_thread::sleep_for(std::chrono::milliseconds(m_interval));        
        std::cout << "Timer end!\n"; 
    };

    time_interval timer::getInterval()
    {
        return m_interval;
    }
}