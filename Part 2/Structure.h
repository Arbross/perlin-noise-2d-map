#pragma once
#include <iostream>
#include <string>
using namespace std;

class Structure abstract
{
public:
	Structure(const float& value = 0.0, const string& name = "Noname", const size_t& age = 0, const size_t& population = 0, const string& owner = "No owner", const int& id = 0);

	// Setters
	void setName(const string& name);
	void setAge(const size_t& age);
	void setPopulation(const size_t& population);
	void setOwner(const string& owner);
	void setID(const int& id);

	// Getters
	float getValue() const;
	string getName() const;
	size_t getAge() const;
	size_t getPopulation() const;
	string getOwner() const;
	int getID() const;

	virtual void print() const;
protected:
	// Fields
	float value;

	string name;
	size_t age;
	size_t population;
	string owner;

	int id;
	enum class Type { CASTLE, VILLAGE, TOWN };
	Type type;
};

inline Structure::Structure(const float& value, const string& name, const size_t& age, const size_t& population, const string& owner, const int& id)
	: value(value), name(name), age(age), population(population), owner(owner), id(id)
{
	setID(id);
}

inline void Structure::setName(const string& name)
{
	this->name = name;
}

inline void Structure::setAge(const size_t& age)
{
	this->age = age;
}

inline void Structure::setPopulation(const size_t& population)
{
	this->population = population;
}

inline void Structure::setOwner(const string& owner)
{
	this->owner = owner;
}

inline void Structure::setID(const int& id)
{
	this->id = id;
	type = static_cast<Type>(id);
}

inline float Structure::getValue() const
{
	return value;
}

inline string Structure::getName() const
{
	return name;
}

inline size_t Structure::getAge() const
{
	return age;
}

inline size_t Structure::getPopulation() const
{
	return population;
}

inline string Structure::getOwner() const
{
	return owner;
}

inline int Structure::getID() const
{
	return id;
}

inline void Structure::print() const
{
	cout << "Value : " << getValue() << endl;
	cout << "Name : " << getName() << endl;
	cout << "Age : " << getAge() << endl;
	cout << "Population : " << getPopulation() << endl;
	cout << "Owner : " << getOwner() << endl;
	cout << "Type : " << getID() << endl;
}
