#include <iostream>
#include "limited_input_deque_doubleLL.h"

using namespace std;

int main()
{
	system("chcp 1251");
	deque<int> myDeque;
	int a;
	do
	{
		system("cls");
		cout << "¬ведите число: ";
		cin >> a;
		myDeque.inLeft(&a);
	} while (a != 0);
	myDeque.printDeque();
	return 0;
}