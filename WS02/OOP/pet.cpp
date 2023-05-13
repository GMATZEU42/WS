#include "pet.h"
#include <iostream>

namespace pet {
	void Pet::printInfo() {
		std::cout << m_name << ", " << m_age << " years old" << std::endl;
	}

	void Dog::printInfo() {
		Pet::printInfo();
		std::cout << m_dogTypeMap.at(m_type) << std::endl;
	}

	void Cat::printInfo() {
		Pet::printInfo();
		std::cout << m_catTypeMap.at(m_type) << std::endl;
	}
}