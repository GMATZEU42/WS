#pragma once

#include <string>
#include <vector>
#include "pet.h"

namespace people
{
    class Person
    {
    public:
        Person(std::string name, unsigned int age) : m_name(name), m_age(age) {};
        virtual ~Person() {
            for (pet::Pet* pet : m_pets) {
                delete pet;
            }
        };
        
        inline std::string getName() { return m_name; };
        inline unsigned int getAge() { return m_age; };
        void addPet(pet::Pet* pet);
        void printPets();

        virtual void printInfo();

    private:
        std::string m_name;
        unsigned int m_age;
        std::vector<pet::Pet*> m_pets;
    };    
}
