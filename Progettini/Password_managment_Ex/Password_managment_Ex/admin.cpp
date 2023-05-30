#include "admin.h"

auto AddUser(std::string name, std::string password)
{
	auto usr = admin::RgsAdmin.find(name);
	if (usr != admin::RgsAdmin.end())
	{
		std::cout << name + ", you are already registered" << std::endl;
	}
	else {

		admin::RgsAdmin.insert(name, password);
		std::cout << name + " thank you for your registration" << std::endl;
	};
};

auto GetPassword(std::string m_password) { return m_password; };

auto ChangePassword(std::string name, std::string m_password, std::string m_newpassword)
{
		admin::RgsAdmin[name] = m_newpassword;
		std::cout << name + ", your password is now " + m_newpassword << std::endl;
};

auto ImmettiCredenziali(std::string name, std::string password) 
{
	bool accesso = false;
	auto usr = admin::RgsAdmin.find(name);
	if (usr != admin::RgsAdmin.end())
	{
		std::cout << name + ", you are not registered" << std::endl;
	}
	else {
		accesso = true;
		std::cout << name + " thank you for loggin in" << std::endl;
	};
};