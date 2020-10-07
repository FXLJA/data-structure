#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int n;
int val;
int cqueue['n'];
int front = 0;
int rear = -1;
int counter;

void insertCQ()
{
	if (counter == n)
	{
		cout << "Queue Overflow" << endl;
	}
		else 
		{
			cout << "Input data : ";
			cin >> val;
			
			rear = (rear + 1) % n;
			cqueue[rear] = val;
			counter++;
			cout << endl << endl << "Data tersimpan"; 
		}	
}

void deletCQ()
{
	if (counter == 0)
	{
		cout << "Queue Underflow" << endl;
	}
		else 
		{
			val = cqueue[front];
			front = (front + 1) % n;
			counter--;
			
			cout << "Indeks yang di-delete : " << val << endl;
			if (counter == 0)
			{
				front = 0;
				rear = -1;
			}
		}
}

void display()
{
	if (rear == -1)
	{
		cout << "Queue is empty" << endl;
	}
		else
		{
			cout << "Daftar antrian : " << endl;
			for (int i = front; i <= n - 1; i++)
			{
				cout << "[" << cqueue[i] << "] ";
			}
		}
}

int main() 
{   
int menu;

	cout << "Masukkan batas queue: ";
	cin >> n;
	
	system("CLS");
	
	do
	{
		system("CLS");

		cout << "Jumlah antrian " << counter << " dari " << n << endl << endl; 
		cout << "1. Insert" << endl
		 	 << "2. Delete" << endl
		 	 << "3. Display" << endl
		  	 << "4. Exit" << endl
		 	 << "Pilihan anda: ";
		cin >> menu;
   		cout << endl;
		switch (menu) 
		{
			case 1:
			{ 
				insertCQ();
				getch();
				break;
			}
			
			case 2: 
			{
				deletCQ();
				getch();
				break;
			}
			
			case 3: 
			{
				display();
				getch();
				break;
			}
			
			case 4: 
			{
				cout<<"Exiting...";
				system("EXIT");
			}
		}
	} 
	while (menu != 4);

return 0;
}
