#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyException : public exception
{
public:
	MyException(const string& message = "Unknown error!")
		: message(message) {}

	string isWhat() const
	{
		return message;
	}
private:
	string message;
};

class InvalidSymbolException : public MyException
{
public:
	InvalidSymbolException(const string& message = "Invalid symbol.")
		: MyException(message) {}
};

class InvalidSwitchException : public MyException
{
public:
	InvalidSwitchException(const string& message = "Invalid switch number.")
		: MyException(message) {}
};
