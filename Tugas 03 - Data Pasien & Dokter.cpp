#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

	//Structs
	struct kode_penyakit
	{
	char jenis_penyakit;
	} kode;
	
	struct level_penyakit
	{
	char tingkat;
	} level;
	
	struct data_pasien
	{
	string nama_pasien;
	int tahun_daftar;
	struct kode_penyakit kode;		//A B C
	struct level_penyakit level;	//P S R
	};
	
	struct data_dokter
	{
	string nama_dokter;
	string harga_dokter;
	string harga_obat;
	string kode_dokter; 			//A B C
	struct kode_penyakit kode;
	};

//Main Program
int main()
{
int menu;
int x;
int y;
int i;
int j;
string sakit ['x'];
string kondisi ['x'];
struct data_pasien pasien ['x'];
struct data_dokter dokter ['y'];

	cout << "1. Menu Pasien" << endl;
	cout << "2. Menu Dokter" << endl;
	cout << "Pilihan: ";
	cin >> menu;
	
	switch (menu)
	{
		case 1:
		{
			system("cls");
			cout << "== DATA PASIEN == \n\n\n";
			cout << "Masukkan jumlah pasien: ";
			cin >> x;

				for (i = 1; i <= x; i++)
				{
					cout << "Nama pasien 	: ";
					cin >> pasien[i].nama_pasien;
					cout << "Tahun daftar 	: ";
					cin >> pasien[i].tahun_daftar;
					cout << "Urutan pasien 	: " << i << endl;
					cout << "Kode penyakit 	: ";
					cin >> pasien[i].kode.jenis_penyakit;
						if (pasien[i].kode.jenis_penyakit == 'A')
						{
							sakit[i] = "Jantung koroner";
						}
							else if (pasien[i].kode.jenis_penyakit == 'B')
							{
								sakit[i] = "Stroke";
							}
							
							else if (pasien[i].kode.jenis_penyakit == 'C')
							{
								sakit[i] = "HIV / AIDS";
							}
							
					cout << "Level penyakit 	: ";
					cin >> pasien[i].level.tingkat;
						if (pasien[i].level.tingkat == 'R')
						{
							kondisi[i] = "Ringan";
						}
							else if (pasien[i].level.tingkat == 'S')
							{
								kondisi[i] = "Sedang";
							}
							
							else if (pasien[i].level.tingkat == 'P')
							{
								kondisi[i] = "Parah";
							}
					cout << endl;
				}
				
				system("cls");
				for (i = 1; i <= x; i++)
				{
					cout << "Nama pasien 	: " << pasien[i].nama_pasien << endl;
					cout << "ID Pasien 	: " <<  pasien[i].level.tingkat << pasien[i].kode.jenis_penyakit << pasien[i].tahun_daftar - 2000 << i << endl;
					cout << "Penyakit 	: " << sakit[i] << endl;
					cout << "Kondisi 	: " << kondisi[i] << endl;
					cout << endl << endl;
				}
		break;
		}
		
		case 2:
		{
			system("cls");
			cout << "== DATA DOKTER == \n\n\n";
			cout << "Masukkan jumlah dokter: ";
			cin >> y;	
			
			for (j = 1; j <= y; j++)
			{
				cout << "Nama dokter 	: ";
				cin >> dokter[j].nama_dokter;
				cout << "Urutan dokter 	: " << j << endl;
				cout << "Kode penyakit 	: ";
				cin >> dokter[j].kode.jenis_penyakit;
					if (dokter[j].kode.jenis_penyakit == 'A')
					{
						sakit[j] = "Jantung koroner";
					}
						else if (dokter[j].kode.jenis_penyakit == 'B')
						{
							sakit[j] = "Stroke";
						}
						
						else if (dokter[j].kode.jenis_penyakit == 'C')
						{
							sakit[j] = "HIV / AIDS";
						}
						
				cout << "Harga dokter 	: ";
				cin >> dokter[j].harga_dokter;
				cout << "Harga obat 	: ";
				cin >> dokter[j].harga_obat;
				
				cout << endl;
			}
			
			system("cls");
			for (j = 1; j <= y; j++)
			{
				cout << "Nama dokter 	: " << dokter[j].nama_dokter << endl;
				cout << "ID dokter 	: " << dokter[j].kode.jenis_penyakit << j + 100 << endl;
				cout << "Spesialis 	: " << sakit[j] << endl;
				cout << "Harga dokter 	: " << dokter[j].harga_dokter << endl;
				cout << "Harga obat 	: " << dokter[j].harga_obat << endl;
				cout << endl << endl;
			}
		break;
		}
	}

getch();
return 0;
}
