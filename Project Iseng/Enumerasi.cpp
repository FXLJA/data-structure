#include <iostream>
#include <conio.h>

using namespace std;

enum prodi { TI = 21, SI = 11, Manajemen, Psikologi = Manajemen + 10};

int main() 
{
    cout << "Nilai enumerator untuk TI 		: " << TI << endl
    	 << "Nilai enumerator untuk SI 		: " << SI << endl
    	 << "Nilai enumerator untuk Manajemen	: " << Manajemen << endl
    	 << "Nilai enumerator untuk Psikologi 	: " << Psikologi << endl;

getch();
return 0;
}
