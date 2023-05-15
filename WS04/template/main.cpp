#include <iostream>
#include <typeinfo>

#include "calculator.h"

template<typename T>
void templatePrint(T value)
{
    std::cout << value << std::endl;
}

template <typename T>
class Object
{
public:
    Object(T value)
    {
        static_assert(std::is_literal_type(T));
        m_pValue = new T(value);
    };
    ~Object()
    {
        if (m_pValue)
        {
            delete m_pValue;
        }
    }
    Object operator+(const Object& other)
    {
        return Object(*m_pValue + *other.m_pValue);
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

    // case string: generate a static_assert compiler error
    //templatePrint(calc::sum(std::string("Ciao"), std::string("Mamma"))); 

    Object<int> iObj(42);
    Object<double> dObj(42.0);

    //auto sumObj = iObj + dObj;  // --> Compiler error
    
    // end of the program
    return 0;
}