#pragma once

#include "person.h"
#include "map"

namespace people {

	enum class Role {
		EMPLOYEE,
		MANAGER,
		DIRECTOR,
		CEO
	};

	class Worker : public Person {
	public:
		Worker(std::string name, unsigned int age, std::string company, Role role) : Person(name, age), m_company(company), m_role(role) {};
		~Worker() {};
		void printInfo() override;
	private:
		std::string m_company;
		Role m_role;
		std::map<Role, std::string> m_roleMap{
			{Role::EMPLOYEE, "employee"},
			{Role::MANAGER, "manager"},
			{Role::DIRECTOR, "director"},
			{Role::CEO, "CEO"}
		};
	};

}

