#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include "conio.h"
#include "PerlinNoise.h"
#include "Structure.h"
#include "Village.h"
#include "Castle.h"
#include "Town.h"
#include "Biome.h"
#include "DarkForest.h"
#include "LightForest.h"
#include "Lake.h"
#include "Plain.h"
#include "Mountain.h"
#include "Exeptions.h"
using namespace std;

template<int txt = 7, int bg = 0>
ostream& color(ostream& text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int isMenu(string menu_items[], int size)
{
	int key = 0, code = 0;

	do {
		key = (key + size) % size;
		for (int i = 0; i < size; i++)
		{
			SetPos(30, i);
			if (key == i)
			{
				cout << " "; SetColor(8); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}
		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80)
			{
				key++;
			}
			if (code == 72)
			{
				key--;
			}
		}
	} while (code != 13);
	return key;
}

class ShowField
{
public:
	ShowField();

	void fill();
	void print() const;
	void clear();

	string getValue() const;
	bool isValueEmpty() const;

	size_t getSizeOfMap() const;
	void setSizeOfMap(const size_t& sizeOfMap);

	void getStructure(const size_t& index) const;
	void getBiome(const size_t& index) const;

	void setStructure(const size_t& index);
	void setBiome(const size_t& index);

	void coutEndl(const size_t& count)
	{
		for (size_t i = 0; i < count; i++) { cout << endl; }
	}
private:
	PerlinNoise noise;

	vector<unique_ptr<Structure>> structure;
	vector<unique_ptr<Biome>> biome;
	vector<float> vec;

	size_t sizeOfMap;
	string value;
};

class Menu
{
public:
	void showMenu();
private:
	ShowField show;
};

void Menu::showMenu()
{
	while (true)
	{
		string menu_items[6];

		menu_items[0] = "1 - Create map";
		menu_items[1] = "2 - Save map";
		menu_items[2] = "3 - Load map";
		menu_items[3] = "4 - Set value";
		menu_items[4] = "5 - Get value";
		menu_items[5] = "6 - Exit";
		int tmp = isMenu(menu_items, 6);
		system("cls");

		switch (tmp)
		{
		case 0: {
			system("cls");
			show.clear();
			show.fill();
			show.print();
		} break;
		case 1: {
			system("cls");
			show.clear();
			show.fill();
			show.print();

			string path = ""; cout << "Enter the path : "; cin >> path;
			ofstream fin(path, fstream::app);

			if (!fin.is_open())
			{
				cerr << "Open of file error.\n";
				exit(0);
			}
			else {
				SetConsoleCP(1251);
				fin << show.getValue();
				SetConsoleCP(866);
			}
		} break;
		case 2: {
			string path = ""; cout << "Enter the path : "; getline(cin, path);
			ifstream fin;
			fin.open(path);

			if (!fin.is_open())
			{
				cerr << "Open of file error.\n"; exit(0);
			}
			else {
				char symbol;
				int i = 0;
				while (fin.get(symbol))
				{
					int sqrtMap = sqrt(show.getSizeOfMap());
					if (i % sqrtMap == 0) { cout << endl; }

					if (symbol == '0')
					{
						cout << color<9, 0> << "0 " << color;
					}
					else if (symbol == '1')
					{
						cout << color<11, 0> << "1 " << color;
					}
					else if (symbol == '2')
					{
						cout << color<10, 0> << "2 " << color;
					}
					else if (symbol == '3')
					{
						cout << color<2, 0> << "3 " << color;
					}
					else if (symbol == '4')
					{
						cout << color<8, 0> << "4 " << color;
					}
					else {
						cout << color<4, 0> << "x " << color;
						throw InvalidSymbolException("Invalid symbol exeption.");
					}
					++i;
				}
			}
		} break;
		case 3: {
			system("cls");
			string menu_items_d[2];
			int number = 0;

			menu_items_d[0] = "Structure";
			menu_items_d[1] = "Nature";
			number = isMenu(menu_items_d, 2);

			switch (number)
			{
			case 0: {
				int index = 0;
				cout << "Enter index : "; cin >> index;

				show.coutEndl(5);
				show.setStructure(index);
			} break;
			case 1: {
				int index = 0;
				cout << "Enter index : "; cin >> index;

				show.coutEndl(5);
				show.setBiome(index);
			} break;
			default: throw InvalidSwitchException("Invalid switch exeprion.");
				break;
			}
		} break;
		case 4: {
			system("cls");

			string menu_items_d[2];
			int number = 0;

			menu_items_d[0] = "Structure";
			menu_items_d[1] = "Nature";
			number = isMenu(menu_items_d, 2);

			switch (number)
			{
			case 0: {
				int index = 0;
				cout << "Enter index : "; cin >> index;

				show.coutEndl(5);
				show.getStructure(index);
			} break;
			case 1: {
				int index = 0;
				cout << "Enter index : "; cin >> index;

				show.coutEndl(5);
				show.getBiome(index);
			} break;
			default: throw InvalidSwitchException("Invalid switch exeprion.");
				break;
			}
		} break;
		case 5: {
			cout << "Bye!" << endl;
			exit(0);
		} break;
		default: throw InvalidSwitchException("Invalid switch exeprion.");
			break;
		}
	}
}

inline void ShowField::print() const
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	int i = 0;
	for (const auto& elem : vec)
	{
		size_t sqrtMap = sqrt(getSizeOfMap());
		if (i % sqrtMap == 0)
		{
			cout << endl;
		}

		if (elem <= -1.0)
		{
			cout << color<9, 0> << "0 " << color;
		}
		else if (elem >= -1.0 && elem <= 0)
		{
			cout << color<11, 0> << "1 " << color;
		}
		else if (elem > 0 && elem <= 0.5)
		{
			int n_tmp = rand() % 100;
			int new_tmp = rand() % 90;

			if (n_tmp <= 5)
			{
				if (new_tmp >= 0 && new_tmp <= 30)
				{
					cout << color<4, 0> << "2 " << color;
				}
				else if (new_tmp > 30 && new_tmp <= 60)
				{
					cout << color<14, 0> << "2 " << color;
				}
				else {
					cout << color<5, 0> << "2 " << color;
				}
			}

			cout << color<10, 0> << "2 " << color;
		}
		else if (elem > 0.5 && elem <= 1)
		{
			cout << color<2, 0> << "3 " << color;
		}
		else if (elem > 1)
		{
			cout << color<8, 0> << "4 " << color;
		}
		else {
			cout << color<4, 0> << "x " << color;
			throw InvalidSymbolException("Invalid symbol exeption.");
		}
		++i;
	}
	cout << endl;
}

inline void ShowField::clear()
{
	vec.clear();
}

inline void ShowField::setSizeOfMap(const size_t& sizeOfMap)
{
	this->sizeOfMap = sizeOfMap;
}

inline string ShowField::getValue() const
{
	return value;
}

inline bool ShowField::isValueEmpty() const
{
	if (!value.empty())
	{
		return true;
	}
	
	return false;
}

inline size_t ShowField::getSizeOfMap() const
{
	return sizeOfMap;
}

inline void ShowField::getStructure(const size_t& index) const
{
	int i = 0;
	for (const auto& elem : structure)
	{
		if (index == i)
		{
			elem.get()->print();
		}
		++i;
	}
}

inline void ShowField::getBiome(const size_t& index) const
{
	int i = 0;
	for (const auto& elem : biome)
	{
		if (index == i)
		{
			elem.get()->print();
		}
		++i;
	}
}

inline void ShowField::setStructure(const size_t& index)
{
	int i = 0;
	for (const auto& elem : structure)
	{
		if (index == i)
		{
			string menu_items[4];
			menu_items[0] = "1 - Set age";
			menu_items[1] = "2 - Set name";
			menu_items[2] = "3 - Set owner";
			menu_items[3] = "4 - Set population";
			int tmp = isMenu(menu_items, 4);

			switch (tmp)
			{
			case 0: {
				cout << "Enter age : "; int age = 0; cin >> age;
				elem.get()->setAge(age);
				system("cls");
				elem.get()->print();
			} break;
			case 1: {
				cout << "Enter name : "; string name = ""; cin >> name;
				elem.get()->setName(name);
				system("cls");
				elem.get()->print();
			} break;
			case 2: {
				cout << "Enter owner : "; string owner = ""; cin >> owner;
				elem.get()->setOwner(owner);
				system("cls");
				elem.get()->print();
			} break;
			case 3: {
				cout << "Enter population : "; int population = 0; cin >> population;
				elem.get()->setPopulation(population);
				system("cls");
				elem.get()->print();
			} break;
			default: throw InvalidSwitchException("Invalid switch exeprion.");
				break;
			}
		}
		++i;
	}
}

inline void ShowField::setBiome(const size_t& index)
{
	int i = 0;
	for (const auto& elem : biome)
	{
		if (index == i)
		{
			string menu_items[2];
			menu_items[0] = "1 - Set age";
			menu_items[1] = "2 - Set name";
			int tmp = isMenu(menu_items, 2);

			switch (tmp)
			{
			case 0: {
				cout << "Enter age : "; int age = 0; cin >> age;
				elem.get()->setAge(age);
				system("cls");
				elem.get()->print();
			} break;
			case 1: {
				cout << "Enter name : "; string name = ""; cin >> name;
				elem.get()->setName(name);
				system("cls");
				elem.get()->print();
			} break;
			default: throw InvalidSwitchException("Invalid switch exeprion.");
				break;
			}
		}
		++i;
	}
}

inline ShowField::ShowField()
{
	cout << "Enter size of map : "; cin >> sizeOfMap;
	value.resize(sizeOfMap);
}

inline void ShowField::fill()
{
	for (size_t i = 0; i < sizeOfMap; i++)
	{
		float n1 = rand() % 9 + 1; n1 /= 10;
		float n2 = rand() % 9 + 1; n2 /= 10;

		float tmp = noise.perlin(n1, n2);
		vec.push_back(tmp);

		if (tmp <= -1.0)
		{
			biome.push_back(make_unique<Lake>(tmp));
			value[i] = '0';
		}
		else if (tmp >= -1.0 && tmp <= 0)
		{
			biome.push_back(make_unique<Lake>(tmp));
			value[i] = '1';
		}
		else if (tmp > 0 && tmp <= 0.5)
		{
			int n_tmp = rand() % 100;
			int new_tmp = rand() % 90;

			if (n_tmp <= 10)
			{
				if (new_tmp >= 0 && new_tmp <= 30)
				{
					structure.push_back(make_unique<Castle>(tmp));
				}
				else if (new_tmp > 30 && new_tmp <= 60)
				{
					structure.push_back(make_unique<Town>(tmp));
				}
				else {
					structure.push_back(make_unique<Village>(tmp));
				}
			}

			biome.push_back(make_unique<Plain>(tmp));
			value[i] = '2';
		}
		else if (tmp > 0.5 && tmp <= 1)
		{
			int tmp = rand() % 100 + 1;

			if (tmp >= 50)
			{
				biome.push_back(make_unique<LightForest>(tmp));
			}
			else if (tmp < 50)
			{
				biome.push_back(make_unique<DarkForest>(tmp));
			}
			value[i] = '3';
		}
		else if (tmp > 1)
		{
			biome.push_back(make_unique<Mountain>(tmp));
			value[i] = '4';
		}
		else {
			throw InvalidSymbolException("Invalid symbol exeption.");
		}
	}
}
