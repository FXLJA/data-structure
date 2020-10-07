#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
int x;

	cout << "Masukkan angka: ";
	cin >> x;
	cout << endl;
	
	if (x < 0)
	{
		cout << "Bilangan negatif";
	}
		else if (x > 0)
		{
			cout << "Bilangan positif";
		}
		
		else if (x == 0)
		{
			cout << "Itu 0 budjank";
		}

getch();
}
