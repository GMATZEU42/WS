#pragma once

#include <string>

namespace pet {
	class Pet {
	public:
		Pet(std::string name, unsigned int age) : m_name(name), m_age(age) {};
		~Pet() {}
		virtual void printInfo();
	private:
		std::string m_name;
		unsigned int m_age;
	};
}