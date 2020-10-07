//wash (VIP first)
//input (>6999 harusnya loop)

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int jumlah = 0;
long income = 0;
int income_vip = 15000;
int income_reguler = 10000;

struct PlatMotor
{
string kode_depan;
int angka;
string kode_belakang;	
} plat;

struct DataMotor
{	
int status_motor;
string level;
PlatMotor plat;
bool isVIP;
} data_motor [5];

DataMotor input;

void display()
{
	if (jumlah == 0)
	{
		cout << "No Motorcycle";
		cout << endl << endl;
	}
		else
		{
			for (int i = 0; i < jumlah; i++)
			{
				cout << i + 1 << ". \t" << data_motor[i].level << "\t : \t" 
					 << data_motor[i].plat.kode_depan << " " << data_motor[i].plat.angka << " " << data_motor[i].plat.kode_belakang << endl;
			}
		}
		
		cout << endl;
		
		cout << "Total Queue 	: " << jumlah << endl;
		cout << "Total Income 	: " << income;
		cout << endl << endl;
}

void add()
{
	for (int i = 0; i < 5; i++)
	{				
		cout << "Insert Plate (Number between 3000 - 6999) : ";
		cin >> data_motor[i].plat.kode_depan >> data_motor[i].plat.angka >> data_motor[i].plat.kode_belakang;
		
//		while (data_motor[i].plat.angka < 3000 || data_motor[i].plat.angka < 6999 || 
//		       data_motor[i].plat.kode_depan == " " || data_motor[i].plat.kode_belakang == " ")
//		{
//			cout << "Insert Plate (Number between 3000 - 6999) : ";
//			cin >> data_motor[i].plat.kode_depan >> data_motor[i].plat.angka >> data_motor[i].plat.kode_belakang;
//		}
		
		cout << "Insert type : ";
		cin >> data_motor[i].status_motor;
		
		if (data_motor[i].status_motor == 0)
		{
			data_motor[i].isVIP = false;
			data_motor[i].level = "Reguler";
		}
			else if (data_motor[i].status_motor == 1)
			{
				data_motor[i].isVIP = true;
				data_motor[i].level = "VIP";
			}

		break;
	}
	
	jumlah++;
}

void wash()
{
	for (int i = 0; i < 5; i++)
	{
		if (data_motor[i].status_motor == 1)
		{
			cout << "VIP Motorcycle " << data_motor[i].plat.kode_depan << data_motor[i].plat.angka << data_motor[i].plat.kode_belakang 
									  << " is washed. " << income_vip << " is paid";
			getch();
			
			income = income + income_vip;
			break;
		}
			else if (data_motor[i].status_motor == 0)
			{
				cout << "Reguler Motorcycle " << data_motor[i].plat.kode_depan << data_motor[i].plat.angka << data_motor[i].plat.kode_belakang 
											  << " is washed. " << income_reguler << " is paid";
				getch();
				
				income = income + income_reguler;
				break;
			}
	}
	
	jumlah--;	
}

void destroy()
{
	cout << "Insert Plate (Number between 3000 - 6999) : ";
	cin >> input.plat.kode_depan >> input.plat.angka >> input.plat.kode_belakang;
	
	for (int i = 0; i < 5; i++)
	{
		if (data_motor[i].plat.kode_depan 		== input.plat.kode_depan && 
			data_motor[i].plat.angka 	  		== input.plat.angka	   &&
			data_motor[i].plat.kode_belakang 	== input.plat.kode_belakang)
		{
			cout << data_motor[i].level << " Motorcycle \t" 
				 << data_motor[i].plat.kode_depan << " " << data_motor[i].plat.angka << " " << data_motor[i].plat.kode_belakang 
				 << " is canceled" << endl;
				 
			getch();
		}
	}
	
	jumlah--;
}

void menu()
{
int pilih;

	do
	{
		system("CLS");
		
		display();
		
		cout << "Washing Queue" << endl
			 << "==============" << endl
			 << "1. Add to queue" << endl
			 << "2. Wash from queue (VIP first)" << endl
			 << "3. Delete from queue" << endl
			 << "4. Wash all + exit" << endl
			 << "Pilih: ";
		cin >> pilih;
		
		switch (pilih)
		{
			case 1:
			{
				add();
				break;
			}
			
			case 2:
			{
				wash();
				break;
			}
			
			case 3:
			{
				destroy();
				break;
			}
			
			case 4:
			{
				//all();
				break;
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
