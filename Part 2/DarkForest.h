#pragma once
#include <iostream>
#include <string>
#include "Biome.h"
using namespace std;

class DarkForest : public Biome
{
public:
	DarkForest(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0, const int& id = 0);

	// Custom print
	virtual void print() const override;
private:
	int id_of_forest;
	enum class TypeOfForest { LIGHTFOREST, DARKFOREST };
	TypeOfForest typeOfForest;
};

inline DarkForest::DarkForest(const float& value, const string& name, const size_t& age, const int& id)
	: Biome(value, name, age, id)
{
	setID(id);
	type = Type::FOREST;
	typeOfForest = TypeOfForest::DARKFOREST;
}

inline void DarkForest::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Type : " << getID() << endl;
	cout << "Type of forest : " << id_of_forest << endl;
}
