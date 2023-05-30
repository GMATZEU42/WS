#pragma once
#include <iostream>
#include <string>
#include <map>

namespace admin
{

	std::map<std::string, std::string> RgsAdmin{ {"Dario" , "qweerty69"}, {"Pippo" , "Sbuccianoci"} };
	class Admin
	{
	public:	
		Admin(std::string name = "", std::string password = "") : m_name(name), m_password(password) {};
		~Admin() {};
		void Adduser();
		
		void GetPassword();

		void ChangePassword();

		void ImmettiCredenziali();

	private:
		std::string m_name = "";
		std::string m_password = "";
	};

};
		