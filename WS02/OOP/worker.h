#pragma once

#include "person.h"
#include "role_level.h"
#include <vector>

namespace people
{

	class Worker : public Person
	{
	public:
		Worker(std::string name, unsigned int age, std::string company) : 
			Person(name, age), m_company(company) {};
		~Worker()
		{
			for (auto rol : m_roleList)
			{
				delete rol;
			}
		};

		inline std::string getCompany() { return m_company; };

		void addRole(role::Role* rol);
		
		void printInfo();
	private:
		std::string m_company;
		std::vector<role::Role*> m_roleList;
	};
};

