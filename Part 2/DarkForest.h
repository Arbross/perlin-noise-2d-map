#pragma once
#include <iostream>
#include <string>
#include "Biome.h"
using namespace std;

class DarkForest : public Biome
{
public:
	DarkForest(const float& value = 0.0);

	virtual void print() const override;
private:
	int id;
	enum class Type { FOREST, WATER, PLAIN, MOUNTAIN };
	Type type;

	int id_of_forest;
	enum class TypeOfForest { LIGHTFOREST, DARKFOREST };
	TypeOfForest typeOfForest;
};

inline DarkForest::DarkForest(const float& value)
	: Biome(value)
{
	type = Type::FOREST;
	typeOfForest = TypeOfForest::DARKFOREST;

	id = 0;
	id_of_forest = 1;
}

inline void DarkForest::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Type : " << id << endl;
	cout << "Type of forest : " << id_of_forest << endl;
}
