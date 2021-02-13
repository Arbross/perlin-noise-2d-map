#pragma once
#include <iostream>
#include <string>
#include "PerlinNoise.h"
using namespace std;

class Biome abstract
{
public:
	Biome(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0, const int& id = 0);

	// Setters
	void setName(const string& name);
	void setAge(const size_t& age);
	void setID(const int& id);

	// Getters
	float getValue() const;
	string getName() const;
	size_t getAge() const;
	int getID() const;

	virtual void print() const;
protected:
	// Fields
	float value;

	string name;
	size_t age;

	int id;
	enum class Type { FOREST, WATER, PLAIN, MOUNTAIN };
	Type type;
};

inline Biome::Biome(const float& value, const string& name, const size_t& age, const int& id)
	: value(value), name(name), age(age), id(id)
{
	setID(id);
}

inline void Biome::setName(const string& name)
{
	this->name = name;
}

inline void Biome::setAge(const size_t& age)
{
	this->age = age;
}

inline void Biome::setID(const int& id)
{
	this->id = id;
	type = static_cast<Type>(id);
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

inline int Biome::getID() const
{
	return id;
}

inline void Biome::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Type : " << getID() << endl;
}
