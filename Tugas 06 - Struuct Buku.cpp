#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

struct Nama
{
string depan;
string tengah;
string belakang;
} nama;

struct Kode
{
char tipe;
int urut;
} kode;

struct Buku
{
string judul;
string *p_nama;
string *p_kode;
} buku;

//Main program
int main()
{
int menu;

	do
	{
		system("CLS");
		cout << "1. Input author" << endl;
		cout << "2. Input buku" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl;
		cout << "~ ";
		cin >> menu;
		
		switch (menu)
		{
			case 1:
			{
				cout << "Masukkan nama depan	: ";
				cin >> nama.depan;
				cout << "Masukkan nama tengah	: ";
				cin >> nama.tengah;
				cout << "Masukkan nama belakang	: ";
				cin >> nama.belakang;
				break;
			}
			
			case 2:
			{
				cout << "Judul buku	: ";
				cin >> buku.judul;
				cout << "Kategori	: ";
				cin >> kode.tipe;
				cout << "Nomor urut	:";
				cin >> kode.urut;
				break;
			}
			
			case 3:
			{
				if (nama.tengah == "tidak ada")
				{
					nama.tengah = " ";
				}
				
				if (nama.belakang == "tidak ada")
				{
					nama.belakang = " ";
				}
				
				cout << "Judul buku	: " << buku.judul << endl;
				cout << "Kode buku	: " << kode.tipe << "-" << kode.urut << endl;
				cout << "Nama author	: " << nama.depan << nama.tengah << nama.belakang;
				
				getch();
				
				break;
			}
			
			case 4:
			{
				system("EXIT");
			}
		}
	}
	while (menu != 4);
	
getch();
return 0;
}
