#include "person.h"

#include <iostream>

namespace people
{
	void Person::printInfo()
	{
		if (m_age > 0)
		{
			std::cout << "I'm " << m_name << " and I'm " << m_age << " years old" << std::endl;
		}
		else
		{
			std::cout << "I'm " << m_name << " and I'm unknown years old" << std::endl;
		}
	}
}