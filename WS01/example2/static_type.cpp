#include <iostream>

int main()
{
    // declaration
    int iVariable;
    // assegnation
    iVariable = 42;

    std::cout << iVariable << std::endl;

    // the follow line generate an error 
    // iVariable = "Quarantadue\n"

    // declaration/definition
    std::string sVariable = "Quarantadue\n";
    std::cout << sVariable;

    return 0;
}