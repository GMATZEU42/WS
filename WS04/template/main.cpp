#include <iostream>
#include <typeinfo>

#include "calculator.h"

template<typename T>
void templatePrint(T value)
{
    std::cout << value << std::endl;
}

template <typename T>
class object
{
public:
    object(T value) : m_pValue(value) {};
    ~object() 
    {
        if (m_pValue)
        {
            delete m_pValue;
        }
    }
    object operator+(const object& other)
    {
        retrun new object(*m_pValue + other.m_pValue);
    }
private:
    T* m_pValue = nullptr;
};

int main()
{
    // case unsigned int
    templatePrint(typeid(calc::sum(21U, 21U)).name());
    
    // case int
    templatePrint(typeid(calc::sum(21, 21)).name());
    
    // case double
    templatePrint(typeid(calc::sum(21.0, 21.0)).name());

    // case string
    templatePrint(calc::sum(std::string("Ciao"), std::string("Mamma")));
    
    // end of the program
    return 0;
}