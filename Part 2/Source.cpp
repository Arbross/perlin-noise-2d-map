#include <iostream>
#include <ctime>
#include "Menu.h"
#include "Exeptions.h"
using namespace std;

int main()
{
	srand(unsigned(time(0)));

	try {
		Menu menu;
		menu.showMenu();
	}
	catch (const InvalidSwitchException& msg)
	{
		cout << "Switch exception : " << msg.isWhat() << endl;
	}
	catch (const InvalidSymbolException& msg)
	{
		cout << "Symbol exception : " << msg.isWhat() << endl;
	}
	catch (const exception&)
	{
		cout << "Unknown exception.\n";
	}

	return 0;
}