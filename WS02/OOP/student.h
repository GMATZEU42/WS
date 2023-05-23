#pragma once

#include "person.h"
#include "degree_level.h"

#include <vector>

namespace people
{
    class Student : public Person
    {
    public:
        Student(std::string name, unsigned int age, std::string alma_mater) : 
            Person(name, age), m_almaMater(alma_mater) {};
        ~Student()
        {
            for (auto deg : m_degreeList)
            {
                delete deg;
            }
        };

        inline std::string getAlmaMater() { return m_almaMater; };

        void addDegree(degree::Degree* deg);

        void printInfo();
    private:
        std::string m_almaMater;
        std::vector<degree::Degree*> m_degreeList;
    };
}