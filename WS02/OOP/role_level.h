#pragma once

#include <string>
#include <map>

namespace role
{
	enum class RoleLevel
	{
		NONE,
		INTERN,
		J_DEVELOPER,
		S_DEVELOPER,
		MANAGER,
		CEO
	};

	class Role
	{
	public:
		Role(const std::string name = "", const unsigned int year = 0U, const unsigned int check = 0U, RoleLevel level = RoleLevel::NONE) : m_name(name), m_year(year),m_check(check), m_level(level) {};
		~Role() {};
		virtual void printRole();
	private:
		std::string m_name = "";
		unsigned int m_year = 0U;
		unsigned int m_check = 0U;
		RoleLevel m_level = RoleLevel::NONE;
		std::map<RoleLevel, std::string> m_levelMap{
			{RoleLevel::NONE , "Unemployed"},
			{RoleLevel::INTERN , "Intern"},
			{RoleLevel::J_DEVELOPER , "Junior Developer"},
			{RoleLevel::S_DEVELOPER , "Senior Developer"},
			{RoleLevel::MANAGER , "Manager"},
			{RoleLevel::CEO , "CEO"},

		};

	};

	class Intern : public Role
	{
	public:
		Intern(std::string name, unsigned int year, unsigned int jobYears) : Role(name, year, RoleLevel::INTERN), m_jobyears(jobYears) {};
		~Intern() {};
		void printRole() override;
	private:
		unsigned int jobYears = 0U;
	};

	class J_Developer : public Role
	{
	public:
		J_Developer(std::string name, unsigned int year, unsigned int projects) : Role(name, year, RoleLevel::J_DEVELOPER), m_Project(projects) {};
		~J_Developer() {};
		void printRole() override;
	private:
		unsigned int projects = 0U;
	};
	
	class S_Developer : public Role
	{
	public:
		S_Developer(std::string name, unsigned int year, unsigned int subordinates) : Role(name, year, RoleLevel::S_DEVELOPER), m_Subordinates(subordinates) {};
		~S_Developer() {};
		void printRole() override;
	private:
		unsigned int subordinates = 0U;
	};

	class Manager : public Role
	{
	public:
		Manager(std::string name, unsigned int year, unsigned int team) : Role(name, year, RoleLevel::MANAGER), m_Team(team) {};
		~Manager() {};
		void printRole() override;
	private:
		unsigned int team = 0U;
	};

	class CEO : public Role
	{
	public:
		CEO(std::string name, unsigned year, unsigned int contract) : Role(name, year, RoleLevel::CEO), m_Contract(contract) {};
		~CEO() {};
		void printRole() override;
	private:
		unsigned int contract = 0U;
	};

	class RoleFactory
	{
	public:
		Role* createRole(const RoleLevel roleLevel, const std::string name = "", const unsigned int year = 0U, const unsigned int jobYears = 0U, const unsigned int project = 0U, const unsigned int subordinates = 0U, const unsigned int team = 0U, const unsigned int contract = 0U);
	};
}

		