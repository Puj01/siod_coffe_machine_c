#include <iostream>
#include "PR_2_objects.h"
//#include "input_limited_deque.h"

using namespace std;

int main()
{
	system("chcp 1251");

	coffeeMachine CoffeBot(2500);
	int run;
	pot* pPot = NULL;


	do
	{
		pPot = new pot(250);
		run = CoffeBot.Run(*pPot);
		delete pPot;
	} while (run);
	return 0;
}

/*
cout << "Введите количество банок в упаковке: ";
	cin >> packSize;
	pack = new pot * [packSize];

	for (i = 0; i < packSize; i++)
	{
		pack[i] = new pot(250);
	}
*/