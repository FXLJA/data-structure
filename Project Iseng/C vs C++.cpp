#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
int a;
int b;
int c;
int d;

	printf("Hello World! \n");
	cout << "Hello World" << endl;
	
	printf("\n");
	cout << endl;
	
	cout << "Masukkan nilai a: ";
	cin >> a;
	
	printf("Masukkan nilai b: ");
	scanf("%d", &b);
	
	cout << "Masukkan nilai c: ";
	scanf("%d", &c);
	
	printf("Masukkan nilai d: ");
	cin >> d;
	
	cout << endl;
	printf("\n");
	
	cout << "A = " << a << endl;
	printf("B = %d \n", b);
	cout << "C = " << c << endl;
	printf("D = %d \n", d, "\n");

getch();
return 0;
}
