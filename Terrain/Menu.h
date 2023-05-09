#pragma once
#include <iostream>
#include "ShowField.h"
using namespace std;

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
		int tmp = show.isMenu(menu_items, 6);
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
			number = show.isMenu(menu_items_d, 2);

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
			number = show.isMenu(menu_items_d, 2);

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
