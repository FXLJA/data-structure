#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

string stack[5];
string x;
int n = 5;
int top = -1;

int pilih;

void push()
{
	if (top < n - 1)
	{
		cout << "Masukkan input stack: ";
		cin >> x;
	
		top = top + 1;
		stack[top] = x;
		cout << endl;
	}
		else
		{
			cout << "Stack overflow";
			getch();
		}
}

void pop()
{
	if (top > -1)
	{
		cout << "Data yang diambil adalah " << stack[top] << endl;
		getch();
		
		top = top - 1;
		cout << endl;
	}
		else
		{
			cout << "Stack underflow";
			getch();
		}
}

void display()
{
	if (top >= 0)
	{
		for (int i = top; i >= 0; i--)
		{
			cout << endl << stack[i] << endl;
		}
		getch();
	}
		else
		{
			cout << "Stack kosong";
			getch();
		}
}

void menu()
{
	do
	{
		system("CLS");
	
		cout << "Stack" << endl << endl
			 << "1. Push" << endl
			 << "2. Pop" << endl
			 << "3. Display" << endl
			 << "4. Exit" << endl
			 << "Pilihan anda: ";
		cin >> pilih;
		
		switch (pilih)
		{
			case 1:
			{
				push();
				break;
			}
			
			case 2:
			{
				pop();
				break;
			}
			
			case 3:
			{
				display();
				break;
			}
			
			case 4:
			{
				cout << endl << "Exiting...";
				system("EXIT");
			}
		}
	}
	while (pilih != 4);
}

//Main Program
int main()
{
	menu();
	
getch();
return 0;
}
