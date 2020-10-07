#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
int a = 5;
int *b;
b = &a;

	cout <<  "Nilai a 	= " << a << endl;
	cout << "Alamat a 	= " << &a << endl;
	cout << "b menunjuk pada = " << b << endl;
	cout << "Nilai b 	= " << *b << endl;
	
getch();
return 0;
}
