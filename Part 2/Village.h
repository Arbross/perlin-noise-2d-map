#pragma once
#include <iostream>
#include <string>
#include "Structure.h"
using namespace std;

class Village : public Structure
{
public:
	Village(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0, const size_t& population = 0, const string& owner = "No owner");

	virtual void print() const override;
private:
	float value;

	string name;
	size_t age;
	size_t population;
	string owner;

	int id;
	enum class Type { CASTLE, VILLAGE, TOWN };
	Type type;
};

inline Village::Village(const float& value, const string& name, const size_t& age, const size_t& population, const string& owner)
	: Structure(value, name, age, population, owner)
{
	type = Type::VILLAGE;
	id = 1;
}

inline void Village::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Owner : " << getOwner() << endl;
	cout << "Population : " << getPopulation() << endl;
	cout << "Type : " << id << endl;
}
