#include <iostream>
#include "PR_2_objects.h"

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