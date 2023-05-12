#include "student.h"

namespace people
{
	void Student::printInfo()
	{
		Person::printInfo();
		for (auto deg : m_degreeList)
		{
			deg->printDegree();
		}
	}

	void Student::addDegree(degree::Degree* deg)
	{
		m_degreeList.push_back(deg);
	}
}