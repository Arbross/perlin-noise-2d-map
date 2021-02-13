#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PerlinNoise.h"
using namespace std;

class Biome abstract
{
public:
	Biome(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0);

	void setName(const string& name);
	void setAge(const size_t& age);

	float getValue() const;
	string getName() const;
	size_t getAge() const;

	virtual void print() const;
protected:
	float value;

	string name;
	size_t age;

	int id;
	enum class Type { FOREST, WATER, PLAIN, MOUNTAIN };
	Type type;
};

inline Biome::Biome(const float& value, const string& name, const size_t& age)
	: value(value), name(name), age(age)
{
	id = INT_MAX;
	type = Type::FOREST;
}

inline void Biome::setName(const string& name)
{
	this->name = name;
}

inline void Biome::setAge(const size_t& age)
{
	this->age = age;
}

inline float Biome::getValue() const
{
	return value;
}

inline string Biome::getName() const
{
	return name;
}

inline size_t Biome::getAge() const
{
	return age;
}

inline void Biome::print() const
{
	cout << "Value : " << value << endl;
	cout << "Name : " << name << endl;
	cout << "Age : " << age << endl;
	cout << "Type : " << id << "(Unknown)" << endl;
}
