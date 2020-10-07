#include <iostream>
#include <conio.h>
#include <cstdlib>

#define n 10

using namespace std;

int S[n];
int mov[2];
int X;
int Y;
int pil = 0;

int *top1;
int *top2;
int *dasar1;
int *dasar2;
int *helpI;

void awal()
{
top1 = &S[-1];
top2 = &S[n];
dasar1 = &S[-1];
dasar2 = &S[n];
helpI = &S[-1];
}

void push1(int x)
{
	top1 = top1+1;
	*top1 = x;
}

void push2(int y)
{
	top2 = top2 - 1;
	*top2 = y;
}

void pop1()
{
	X = *top1;
	*top1 = 0;
	top1 = top1 - 1;
}

void pop2()
{
	Y = *top2;
	*top2 = 0;
	top2 = top2+1;
}

int BisaDiisi(int k)
{
	if (top2 - top1 > k)
		return 1;
		
		else
			return 0;
}

int BisaDiambil1()
{
	if (top1 > dasar1)
		return 1;
	
		else
			return 0;
}

int BisaDiambil2()
{
	if (top2 < dasar2)
		return 1;
	
		else
			return 0;
}

void tampil()
{
	cout << "\n================ data menjadi ===================" << endl;
		
		while (helpI != (dasar2 - 1))
		{
			helpI++;
			cout << *helpI << " ";
		}
	
	cout << "\n======================================================" << endl;
	
	helpI = &S[-1];
}

void tampilMenu()
{
	system("cls");
	
	cout << "========================================================" << endl;
	cout << "1. isi stack 1 (kiri)" << endl;
	cout << "2. isi stack 2 (kanan)" << endl;
	cout << "3. isi kedua stack" << endl;
	cout << "4. pop stack 1" << endl;
	cout << "5. pop stack 2" << endl;
	cout << "6. pop kedua stack" << endl;
	cout << "=========================================================" << endl;
	
	cout << "pilihan anda : ";
	cin >> pil;

}

//Main program
int main()
{
	awal();

	do
	{
		tampilMenu();
		
		cout << endl;
		
		switch(pil)
		{
			case 1: 
				if (BisaDiisi(1))
				{
					cout << "masukkan bilangan = ";
					cin >> X;
					push1(X);
				}
					else
					{
						cout << "maaf tidak ada tempat untuk push";
					}
					
				break;
				
			case 2: 
				if (BisaDiisi(1))
				{
					cout << "masukkan bilangan = ";
					cin >> Y;
					push2(Y);
				}
					else
					{
						cout << "maaf tidak ada tempat untuk push";
					}
					
				break;
				
			case 3: 
				if (BisaDiisi(2))
				{
					cout << "masukkan bilangan 1= ";
					cin >> X;
					push1(X);
					cout << "masukkan bilangan 2= ";
					cin >> Y;
					push2(Y);
				}
					else
					{
						cout << "maaf ruang tidak cukup";
					}
				
				break;
			
			case 4: 
				if (BisaDiambil1())
				{
					pop1();
					cout << "data yang diambil = "<<X << endl;
				}
					else
					{
						cout << "maaf stack 1 tidak ada isinya" << endl;
					}
				
				break;
				
			case 5: 
				if (BisaDiambil2())
				{
					pop2();
					cout << "angka yang diambil = "<<Y << endl;
				}
					else
					{
						cout << "maaf stack 2 tidak ada isinya" << endl;
					}
				
				break;
				
				case 6: 
					if (BisaDiambil1() && BisaDiambil2())
					{
						pop1();
						pop2();
						cout << "isi yang baru di pop = "<<X<<" dan "<<Y << endl;
					}
						else
						{
							cout << "maaf salah satu atau kedua stack tidak ada isinya" << endl;
						}
				
				break;
		}
		
		tampil();
		
		cout << "\nenter untuk mengulang dan esc untuk keluar !";
		
		do
		{
			mov[0] = getch();
			if(mov[0] == 27)
			exit(0);
		}
		while(mov[0] != 13);
	}
	while(mov[0] == 13);

getch();
}
