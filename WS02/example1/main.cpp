#include <iostream>

#include "timing.h"

void foo()
{
    timing::timer *t = new timing::timer(42U);
    t->start();
    delete t;
}

int main()
{
    std::cout << "Hello Guys!\n";
    foo();
    std::cout << "Bye bye!\n";
    
    return 0;
}