#pragma once
#include <iostream>
#include <string>
#include "Biome.h"
using namespace std;

class LightForest : public Biome
{
public:
	LightForest(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0);

	virtual void print() const override;
private:
	int id;
	enum class Type { FOREST, WATER, PLAIN, MOUNTAIN };
	Type type;

	int id_of_forest;
	enum class TypeOfForest { LIGHTFOREST, DARKFOREST };
	TypeOfForest typeOfForest;
};

inline LightForest::LightForest(const float& value, const string& name, const size_t& age)
	: Biome(value, name, age)
{
	type = Type::FOREST;
	typeOfForest = TypeOfForest::LIGHTFOREST;
	
	id = 0;
	id_of_forest = 0;
}

inline void LightForest::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Type : " << id << endl;
	cout << "Type of forest : " << id_of_forest << endl;
}
