#include "worker.h"

namespace people
{
	void Worker::printInfo()
	{
		Person::printInfo();
		for (auto rol : m_roleList)
		{
			rol->printRole();
		}
	}

	void Worker::addRole(role::Role* rol)
	{
		m_roleList.push_back(rol);
	}
}