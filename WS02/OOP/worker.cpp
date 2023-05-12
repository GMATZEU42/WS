#include "worker.h"

#include <iostream>

namespace people
{
	void Worker::printInfo()
	{
		Person::printInfo();
		std::cout << "I'm a " << m_roleMap.at(m_role) << " at " << m_company << std::endl;
	}
}