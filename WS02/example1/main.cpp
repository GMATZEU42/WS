#include <iostream>

#include "time.h"

void foo()
{
    time::timer t = time::timer();
    t.start();
    t.stop();
}

int main()
{
    std::cout << "Hello Guys!\n";
    foo();
    std::cout << "Bye bye!\n";
    
    return 0;
}