#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

	struct data_nama
	{
	string nama_depan;
	string nama_tengah;
	string nama_belakang;
	};
	
	struct data_nilai
	{
	int tm;
	int uts;
	int uas;
	float final;
	};
	
	struct data_mahasiswa
	{
	struct data_nama nama;
	struct data_nilai nilai;
	long nim;
	string grade;
	};

int main()
{
int i;
int x;
data_mahasiswa mahasiswa ['x'];\

	cout << "Masukkan jumlah mahasiswa: ";
	cin >> x;	
	cout << endl;
	
	for (i = 1; i <= x; i++)
	{
	cout << "Masukkan nama depan mahasiswa \t : ";
	cin >> mahasiswa[i].nama.nama_depan;
		if (mahasiswa[i].nama.nama_tengah == "Tidak ada" || mahasiswa[i].nama.nama_tengah == "tidak ada")
		{
			mahasiswa[i].nama.nama_tengah = " ";
		}
	cout << "Masukkan nama tengah mahasiswa \t : ";
	cin >> mahasiswa[i].nama.nama_tengah;
		if (mahasiswa[i].nama.nama_belakang == "Tidak ada" || mahasiswa[i].nama.nama_belakang == "tidak ada")
		{
			mahasiswa[i].nama.nama_belakang = " ";
		}
	cout << "Masukkan nama belakang mahasiswa : ";
	cin >> mahasiswa[i].nama.nama_belakang;
	
	cout << endl;
	
	cout << "Masukkan NIM: ";
	cin >> mahasiswa[i].nim;
	
	cout << endl;
	
	cout << "Nilai Tugas \t: ";
	cin >> mahasiswa[i].nilai.tm;
	cout << "Nilai UTS \t: ";
	cin >> mahasiswa[i].nilai.uts;
	cout << "Nilai UAS \t: ";
	cin >> mahasiswa[i].nilai.uas;
	
	cout << endl;
		
	mahasiswa[i].nilai.final = (mahasiswa[i].nilai.uts + mahasiswa[i].nilai.uas + mahasiswa[i].nilai.tm) / 3;
	cout << "Nilai akhir: " << mahasiswa[i].nilai.final << endl;
	
		if (mahasiswa[i].nilai.final >= 70 && mahasiswa[i].nilai.final <= 100)
		{
			mahasiswa[i].grade = "A";	
		}
			else if (mahasiswa[i].nilai.final >= 40 && mahasiswa[i].nilai.final <= 69)
			{
				mahasiswa[i].grade = "B";
			}
				else
				{
					mahasiswa[i].grade = "C";
				}
	cout << endl << endl;
	}
	
	system ("cls");
	
	for (i = 1; i <= x; i++)
	{
		cout << "Nama depan \t: " << mahasiswa[i].nama.nama_depan << endl;
		cout << "Nama tengah \t: " << mahasiswa[i].nama.nama_tengah << endl;
		cout << "Nama belakang \t: " << mahasiswa[i].nama.nama_belakang << endl;
		cout << "Nilai TM \t\t: " << mahasiswa[i].nilai.tm << endl;
		cout << "Nilai UTS \t\t: " << mahasiswa[i].nilai.uts << endl;
		cout << "Nilai UAS \t\t: " << mahasiswa[i].nilai.uas << endl;
		cout << "Nilai akhir \t\t: " << mahasiswa[i].nilai.final << endl;
		cout << "Grade \t\t\t: " << mahasiswa[i].grade;
		cout << endl << endl;
	}
	
getch();
return 0;
}
