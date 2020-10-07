#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

int jumlah = 0;
int indeks;
int i;

//Main struct
struct movie
{
char judul [100];
float rating;
int vote;
};

movie film[10];

//Menampilkan daftar film
void display()
{
	cout << "Number of movies: " << jumlah;
	cout << "\n\n\n";
	
	for (i = 0; i < 10; i++)
	{
		cout << "[" << i << "]" << "\t" << film[i].judul << "\t\t\t\t" << film[i].rating << ".0" << "\t\t\t" << film[i].vote << endl;			
	}
}

//Menambah film
void add()
{
	cout << "Title	: ";
	cin.ignore();
	cin.getline(film[jumlah].judul, 100);
	
	cout << "Rating	: ";
	cin >> film[jumlah].rating;
	
	jumlah++;
	
	if (jumlah > 10)
	{
		cout << "Maximum movies allowed is 10";
	}
}

void edit()
{
	cout << "Masukkan indeks: ";
	cin >> indeks;

	cout << "Title	: ";
	cin.ignore();
	cin.getline(film[indeks].judul, 100);
	
	cout << "Rating	: ";
	cin >> film[indeks].rating;	
}

//Delete film
void hapus()
{
	cout << "Pilih indeks: ";
    cin >> indeks;
    
    if (indeks >= 0 && indeks < jumlah)
	{
		for (int i = indeks; i < jumlah - 1; i++)
		{
			film[i] = film[i + 1];
		}
	}
		else 
		{
			cout << "Wrong Index!";
		}
}

//Menambah vote
void vote()
{
	cout << "Pilih indeks: ";
    cin >> indeks;
    
    film[indeks].vote = film[indeks].vote + 1;
}

//Main Program
int main()
{
int pilih;

	do
	{
	system("CLS");
	
	display();
	
	cout << endl << endl;
	
	cout << "1.	Add" << endl;
	cout << "2.	Edit" << endl;
	cout << "3.	Delete" << endl;
	cout << "4.	Vote" << endl;
	cout << "5.	Exit" << endl;
	cout << "Pilihan anda: ";
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
				edit();
				break;
			}
			
			case 3:
			{
				hapus();
				break;
			}
			
			case 4:
			{
				vote();
				break;
			}
			
			case 5:
			{
				system("EXIT");
			}
		}
	}
	while (pilih != 5);

getch();
return 0;
}
