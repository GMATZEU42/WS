#pragma once

#include <string>
#include <iostream>

namespace people
{
    class Person
    {
    public:
        Person(std::string name, unsigned int age) : m_name(name), m_age(age) {};
        virtual ~Person() {};
        
        inline std::string getName() { return m_name; };
        inline unsigned int getAge() { return m_age; };

        virtual void printInfo();

    private:
        std::string m_name = "";
        unsigned int m_age = 0U;
    };    
}
