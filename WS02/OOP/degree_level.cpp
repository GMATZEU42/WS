#include "degree_level.h"

#include <iostream>

namespace degree
{
	void Degree::printDegree()
	{
		std::cout << m_levelMap.at(m_level) << "\t"
			<< m_name << "\t"
			<< m_year << "\t";
	}

	void Phd::printDegree()
	{
		Degree::printDegree();
		std::cout << m_thesis << "\t" << m_vote << std::endl;
	}

	void Master::printDegree()
	{
		Degree::printDegree();
		std::cout << m_thesis << "\t" << m_vote << std::endl;
	}

	void SecondaryII::printDegree()
	{
		Degree::printDegree();
		std::cout << m_thesis << "\t" << m_vote << std::endl;
	}

	void SecondaryI::printDegree()
	{
		Degree::printDegree();
		std::cout << m_vote << std::endl;
	}

	void Primary::printDegree()
	{
		Degree::printDegree();
		std::cout << "" << std::endl;
	}

	Degree* DegreeFactory::createDegree(const DegreeLevel degreeLevel, const std::string name, unsigned int year, const std::string thesis, const unsigned int vote)
	{
		Degree *deg;
		switch (degreeLevel)
		{
		case DegreeLevel::PRIMARY:
			deg = new Primary(name, year);
			break;
		case DegreeLevel::SECONDARY_I:
			deg = new SecondaryI(name, year, vote);
			break;
		case DegreeLevel::SECONDARY_II:
			deg = new SecondaryII(name, year, thesis, vote);
			break;
		case DegreeLevel::MASTER:
			deg = new Master(name, year, thesis, vote);
			break;
		case DegreeLevel::PHD:
			deg = new Phd(name, year, thesis, vote);
			break;
		default:
			break;
		}
		return deg;
	}
}