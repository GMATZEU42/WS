#pragma once

#include <string>
#include <map>

namespace pet {
	enum class DogType {
		LABRADOR,
		PITBULL,
		HOUND
	};

	enum class CatType {
		A,
		B,
		C
	};

	class Pet {
	public:
		Pet(std::string name, unsigned int age) : m_name(name), m_age(age) {};
		~Pet() {}
		virtual void printInfo();
	private:
		std::string m_name;
		unsigned int m_age;
	};

	class Dog : public Pet {
	public:
		Dog(std::string name, unsigned int age, DogType type) : Pet(name, age), m_type(type) {};
		~Dog() {};
		void printInfo() override;
	private:
		DogType m_type;
		std::map<DogType, std::string> m_dogTypeMap{
			{DogType::LABRADOR, "Labrador"},
			{DogType::PITBULL, "Pitbull"},
			{DogType::HOUND, "Mastino"}
		};
	};

	class Cat : public Pet {
	public:
		Cat(std::string name, unsigned int age, CatType type) : Pet(name, age), m_type(type) {};
		~Cat() {};
		void printInfo() override;
	private:
		CatType m_type;
		std::map<CatType, std::string> m_catTypeMap{
			{CatType::A, "Non so"},
			{CatType::B, "nessuna razza"},
			{CatType::C, "di gatto"}
		};
	};
}