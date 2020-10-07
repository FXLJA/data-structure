#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

//Main Program
int main()
{
int cash;
int input;
int cola = 30;
int sprite = 30;
int air = 20;
int tea = 25;

	cout << "Please enter your money: ";
	cin >> cash;
	
	while (cash > 0)
	{
		system("CLS");
		cout << "Your cash is: " << cash << endl << endl;
		
		cout << "1. Cola				30 NTD" << endl;
		cout << "2. Sprite			30 NTD" << endl;
		cout << "3. Mineral Water		20 NTD" << endl;
		cout << "4. Tea King 			25 NTD" << endl;
		cout << "Enter your choice : ";
		cin >> input;
		
		if (cash < 20)
		{
			cout << "Your money is not enough. Now exiting...";
			system("EXIT");
		}
		
		switch (input)
		{
			case 1:
			{
				cash = cash - 30;
				break;
			}
			
			case 2:
			{
				cash = cash - 30;
				break;
			}
			
			case 3:
			{
				cash = cash - 20;
				break;
			}
			
			case 4:
			{
				cash = cash - 25;
				break;
			}
		}
	}

getch();
return 0;
}
