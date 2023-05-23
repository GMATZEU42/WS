#include "role_level.h"
#include <iostream>

namespace role
{
	void Role::printRole()
	{	
		std::cout << m_levelMap.at(m_level) << "\t"
			<< m_name << "\t"
			<< m_year << "\t"
			<< m_check << "\t";
	}

	void Intern::printRole()
	{
		Role::printRole();
		std::cout << m_jobYears << std::endl;
	}

	void J_Developer::printRole()
	{
		Role::printRole();
		std::cout << m_projects << std::endl;
	}

	void S_Developer::printRole()
	{
		Role::printRole();
		std::cout << m_subordinates << std::endl;
	}

	void Manager::printRole()
	{
		Role::printRole();
		std::cout << m_team << std::endl;
	}

	void CEO::printRole()
	{
		Role::printRole();
		std::cout << m_contract << std::endl;
	}

	Role* RoleFactory::createRole(const RoleLevel roleLevel, const std::string name, const unsigned int year, const unsigned int jobYears, const unsigned int projects, const unsigned int subordinates, const unsigned int team, const unsigned int contract)
	{
		Role* rol;
		switch (roleLevel)
		{
		case RoleLevel::INTERN:
			rol = new Intern(name, year, jobYears);
			break;
		
		case RoleLevel::J_DEVELOPER:
			rol = new J_Developer(name, year, projects);
			break;
		
		case RoleLevel::S_DEVELOPER:
			rol = new S_Developer(name, year, subordinates);
			break;
		
		case RoleLevel::MANAGER:
			rol = new Manager(name, year, team);
			break;

		case RoleLevel::CEO:
			rol = new CEO(name, year, contract);
			break;		
		}

		return rol;
	}
}

