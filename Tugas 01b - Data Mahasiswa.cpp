#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

struct data
{

};

int main()
{
int i;
int x;
long nim ['x'];
string nama ['x'];
int uts ['x'];
int uas ['x'];
int tm ['x'];
float final ['x'];

	cout << "Jumlah mahasiswa: ";
	cin >> x;
	cout << endl;
	
	for (i = 1; i <= x; i++)
	{
		cout << "Masukkan nama mahasiswa: ";
		cin >> nama[i];
		cout << "Masukkan NIM: ";
		cin >> nim[i];
		cout << "Nilai Tugas: ";
		cin >> tm[i];
		cout << "Nilai UTS: ";
		cin >> uts[i];
		cout << "Nilai UAS: ";
		cin >> uas[i];
			
		final[i] = (uts[i] + uas[i] + tm[i]) / 3;
		cout << "Nilai akhir: " << final[i] << endl;
		
		if (final[i] >= 70 && final [i] <= 100)
		{
			cout << "Grade: A";	
		}
			else if (final[i] >= 40 && final[i] <= 69)
			{
				cout << "Grade: B";
			}
				else
				{
					cout << "Grade: C";
				}
		cout << endl << endl;
	}

getch();
}
