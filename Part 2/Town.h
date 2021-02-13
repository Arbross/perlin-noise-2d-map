#pragma once
#include <iostream>
#include <string>
#include "Structure.h"
using namespace std;

class Town : public Structure
{
public:
	Town(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0, const size_t& population = 0, const string& owner = "No owner", const int& id = 0);

	// Custom print
	virtual void print() const override;
};

inline Town::Town(const float& value, const string& name, const size_t& age, const size_t& population, const string& owner, const int& id)
	: Structure(value, name, age, population, owner, id)
{
	setID(id);
}

inline void Town::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Owner : " << getOwner() << endl;
	cout << "Population : " << getPopulation() << endl;
	cout << "Type : " << getID() << endl;
}
