#pragma once
#include <iostream>
#include <string>
#include "Structure.h"
using namespace std;

class Castle : public Structure
{
public:
	Castle(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0, const size_t& population = 0, const string& owner = "No owner");

	virtual void print() const override;
private:
	int id;
	enum class Type { CASTLE, VILLAGE, TOWN };
	Type type;
};

inline Castle::Castle(const float& value, const string& name, const size_t& age, const size_t& population, const string& owner)
	: Structure(value, name, age, population, owner)
{
	type = Type::CASTLE;
	id = 0;
}

inline void Castle::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Owner : " << getOwner() << endl;
	cout << "Population : " << getPopulation() << endl;
	cout << "Type : " << id << endl;
}
