#pragma once
#include <iostream>
#include <string>
#include "Biome.h"
using namespace std;

class Plain : public Biome
{
public:
	Plain(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0);

	virtual void print() const override;
private:
	int id;
	enum class Type { FOREST, WATER, PLAIN };
	Type type;
};

inline Plain::Plain(const float& value, const string& name, const size_t& age)
	: Biome(value, name, age)
{
	type = Type::PLAIN;
	id = 2;
}

inline void Plain::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Type : " << id << endl;
}
