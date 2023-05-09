#pragma once
#include <iostream>
#include <string>
#include "Biome.h"
using namespace std;

class Mountain : public Biome
{
public:
	Mountain(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0, const int& id = 0);

	// Custom print
	virtual void print() const override;
};

inline Mountain::Mountain(const float& value, const string& name, const size_t& age, const int& id)
	: Biome(value, name, age, id)
{
	setID(id);
}

inline void Mountain::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Type : " << getID() << endl;
}
