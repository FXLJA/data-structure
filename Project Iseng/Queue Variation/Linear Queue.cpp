#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int n;
int isi;
int Queue['n'];
int rear = -1;		
int front = 0;

void reset()
{
	front = 0;
	rear = -1;
}

void insert()
{
	if( rear == n - 1 )
	{
		cout << "Queue Overflow or full." << endl;
	}
	
	else 
	{
		cout << "Input data : ";
		cin >> isi;

		rear++;
		Queue[rear] = isi;

		cout << endl << "Data tersimpan" << endl;
	}
}

void delet()
{
    if (front == rear + 1)
    {
        cout << "Queue is empty or underflow" << endl;
    }    
    	else 
    	{
	        isi = Queue[front];
	        front++;
	
	        cout << "Data yang keluar adalah " << isi << endl;
	        if (rear == n - 1 && front == n)
	        {
	            reset();
	        }
    	}
}

void display()
{
	if( rear == -1)
	{
		cout << "Queue is empty" << endl;
	}
		else
		{
			for (int i = front; i <= n-1; i++)
			{
				cout << "[" << Queue[i] << "] ";
			}
		}
}

int main()
{
	int menu;
	
	cout << "Masukan banyak antrian : ";
	cin >> n;
	
	do
	{
		system("CLS");
		
		cout << "1. Insert" << endl
			 << "2. Delete" << endl
			 << "3. Display" << endl
			 << "4. Exit" << endl
			 << "Pilih: ";
		cin >> menu;
		
		switch(menu)
		{
			case 1:
			{
				insert();
				getch();
				break;
			}
			
			case 2:
			{
				delet();
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
				cout << "Exiting...";
				system("EXIT");
			}
			
			default:
			{
				cout << "\n\tPilihan salah, pilih kembali!" << endl;
				getch();
				break;
			}
		}
	}
	while(menu != 4);

getch();
return 0;
}
