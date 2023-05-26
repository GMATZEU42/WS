#include <iostream>

#include "vld.h"

#include "console.h"
#include "very_pretty_library.h"


using amaris::Console;
using amaris::ConsoleColor;


int main()
{
    Console console(ConsoleColor::MAGENTA);
    // declaration and definition
    vpl::object obj(42);
    console.print(*obj.getSharedValue());
    // end of the program
    return 0;   
}



