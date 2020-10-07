#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int queue['n'];				//queue
int data;					//inputan
int head = 0;				//indeks paling kiri
int tail = -1;				//indeks paling kanan
int n;						//batas queue
int counter;				//jumlah anggota queue
bool isEmpty = true;

//insert kiri
void enqueue_kiri()
{
	cout << "Masukkan data: ";
	cin >> data;
	
	if (head > 0)
	{
		head--;
		queue[head] = data;
		counter++;
		
		cout << endl << "Data tersimpan";
	}
		else if (head == 0)
		{
			cout << "Overflow kiri";
		}
		
	isEmpty = false;
}

//insert kanan
void enqueue_kanan()
{
	cout << "Masukkan data: ";
	cin >> data;
	
	if (tail < n - 1)
	{
		tail++;
		queue[tail] = data;
		counter++;
		
		cout << endl << "Data tersimpan";
	}
		else
		{
			cout << "Overflow kanan";
		}	
	
	isEmpty == false;	
}

//delete kiri
void dequeue_kiri()
{
	if (head < tail + 1)
	{
		data = queue[head];
		head++;
		counter --;
		
		cout << "Data yang dihapus: " << data;
	}
		else
		{
			cout << "Queue underflow";
		}
}

//delete kanan
void dequeue_kanan()
{
	if (head < tail + 1)
	{
		data = queue[tail];
		tail--;
		counter --;
		
		cout << "Data yang dihapus: " << data;
	}
		else
		{
			cout << "Queue underflow";
		}
}

//display queue
void display()
{
	if (head != tail + 1)
	{
		cout << "Isi queue: ";
		
		for (int i = head; i <= tail; i++)
		{
			cout << "[" << queue[i] << "] ";
		}
	}
		else if (isEmpty == true)
		{
			cout << "Queue kosong";
		}
}

//clear queue
void reset()
{
	head = 0;
	tail = -1;
	isEmpty == true;
}

//main menu
void menu()
{
int menu;
	
	do
	{
		system("CLS");
		
		cout << "Batas queue: " << n << endl;
		cout << "Isi queue saat ini: " << counter << endl << endl;
		
		cout << "1. Insert kiri" << endl
			 << "2. Insert kanan" << endl
			 << "3. Delete kiri" << endl
			 << "4. Delete kanan" << endl
			 << "5. Display queue" << endl
			 << "6. Reset queue" << endl
			 << "7. Exit" << endl
			 << "Pilihan anda: ";
		cin >> menu;
		
		switch (menu)
		{
			case 1:
			{
				if (isEmpty == true)
				{
					enqueue_kanan();
					getch();
					break;
				}
					else
					{
						enqueue_kiri();
						getch();
						break;
					}
			}
			
			case 2:
			{
				enqueue_kanan();
				getch();
				break;
			}
			
			case 3:
			{
				dequeue_kiri();
				getch();
				break;
			}
			
			case 4:
			{
				dequeue_kanan();
				getch();
				break;
			}
			
			case 5:
			{
				display();
				getch();
				break;
			}
			
			case 6:
			{
				reset();
				cout << "Queue di-reset";
				getch();
				break;
			}
			
			case 7:
			{
				cout << "Exiting...";
				system("EXIT");
			}
		}
	}
	while (menu != 7);
}

//Main Program
int main()
{
	cout << "Masukkan batas queue: ";
	cin >> n;
	
	system("CLS");
	
	menu();
	
getch();
return 0;
}

