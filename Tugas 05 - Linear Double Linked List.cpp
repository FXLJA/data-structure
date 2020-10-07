//http:kubusumatra.blogspot.com/2014/10/contoh-program-double-linked-list-c.html

#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

// variabel dan method global
int pil;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();
void tambah_tengah();
void hapus_tengah();

//deklarasi struct dan variabel dengan tipe data struct ybs
struct node
{
char nama [20];
int umur;
float tinggi;
node *prev;
node *next;	
};
node *baru, *head = NULL, *tail = NULL, *hapus, *bantu, *bantu2;

//prosedur untuk memproses pilihan user dari menu utama
void pilih()
{
	if (pil == 1)
	{
		tambah_depan();		
	}
		else if (pil == 2)
		{
			tambah_belakang();		
		}
	
		else if (pil == 3)
		{
			hapus_depan();		
		}
		
		else if (pil == 4)
		{
			hapus_belakang();		
		}
		
		else if (pil == 5)
		{
			tampil();		
		}
	
		else if (pil == 6)
		{
			tambah_tengah();		
		}
	
		else if (pil == 7)
		{
			hapus_tengah();	
		}
			else
			{
				cout<<"Selesai";
			}
}

//method membuat node baru
void buat_baru()
{
	baru = new(node);			//membuat node baru dengan keyword 'new'
	cout << "Input nama : ";
	cin >> baru -> nama;
	cout << "Input umur : ";
	cin >> baru -> umur;
	cout << "Input tinggi : ";
	cin >> baru -> tinggi;

	baru -> prev = NULL;		//karena node ini baru dibuat dan belum diketahui akan diposisikan dimana
	baru -> next = NULL;		//maka pointer kiri dan kanannya ditunjuk ke nilai NULL
}

void tambah_belakang()				//menambahkan node di sebelah kanan
{
	buat_baru(); 					//memanggil prosedur buat simpul baru
	
	if (head == NULL)				//jika node pertama = NULL artinya list belum ada atau sudah dihapus
	{
		head = baru;				//maka node baru diposisikan sebagai kepala dan ekor (node pertama dan terakhir dalam list)
		tail = baru;			
	}
		else						//jika ternyata node pertama tidak NULL (ada yang menempati slot head)
		{
			tail -> next = baru;	//pointer next pada tail akan menunjuk pada node baru yang dibuat
			baru -> prev = tail;	//pointer prev pada node baru yang dibuat akan menunjuk pada tail, membentuk link dua arah
			tail = baru;			//node baru di-assign sebagai node tail (node terakhir dalam list)
		}
		
	cout << endl << endl;
	
	tampil();						// Memanggil prosedur tampil
}

void tambah_depan()					//menambahkan node di sebelah kiri 
{	
	buat_baru(); 					//memanggil prosedur buat simpul baru
	
	if(head == NULL)				//jika node pertama = NULL artinya list belum ada atau sudah dihapus
	{
		head = baru;				//maka node baru diposisikan sebagai kepala dan ekor (node pertama dan terakhir dalam list)
		tail = baru;			
	}
		else						
		{
			baru -> next = head;	//pointer next pada node yang baru dibuat menunjuk pada head (node pertama saat ini)
			head -> prev = baru;	//pointer previous pada head menunjuk pada node yang baru dibuat, membentuk link dua arah
			head = baru;			//node baru di-assign sebagai head (node pertama dalam list)
		}
		
	cout << endl << endl;
	
	tampil();						// Memanggil prosedur tampil
}

void hapus_depan()						//menghapus node paling kiri
{
	if (head == NULL)					//jika node head bernilai NULL artinya tidak ada node dalam list (list kosong)
	{
		cout << "Kosong";		
	}
		else if (head -> next == NULL)	//jika pointer next pada head menunjuk ke NULL artinya baru ada satu node yang dibuat
		{
			hapus = head;				//node head di-assign ke variabel hapus
			head = NULL;				//nilai head di NULL kan
			tail = NULL;				//nilai tail di NULL kan
			delete hapus;				//variabel hapus di-delete (berbeda dengan free(hapus), free hanya mengembalikan memori
											//yang dialokasikan kepada variabel hapus sedangkan delete menghapus variabel tersebut dari operasi
		}
			else						//jika ada >1 node
			{
				hapus = head;			//head di-assign kepada variabel hapus
				head = hapus -> next;	//pointer next pada variabel hapus (yang tadinya adalah head) di-assign sebagai head yang baru 
				head -> prev = NULL;	//pointer prev pada head ditunjuk ke nilai NULL untuk menghentikan list
				delete hapus;			//variabel hapus di-delete
			}
	
	cout << endl << endl;
	
	tampil();							// Memanggil prosedur tampil
}
 
void hapus_belakang()					//method menghapus node paling kanan
{
	if (head == NULL)
	{
		cout << "Kosong";
	}	
		else if (head -> next == NULL)
		{
			hapus = head;
			head = NULL;
			tail = NULL;
			delete hapus;
		}
			else						//jika ada >1 node
			{
				hapus = tail;			//nilai tail di-assign ke variabel hapus
				tail = hapus -> prev;	//nilai yang ditunjuk pointer hapus (yang tadinya tail) di-assign sebagai tail yang baru
				tail -> next = NULL;	//pointer next dari node tail ditunjuk ke nilai NULL untuk menghentikan list
				delete hapus;			//variabel hapus di-delete
			}
	
	cout << endl << endl;
	
	tampil();
}

void tampil()													//method menampilkan daftar list
{
	if (head == NULL)
	{						
		cout<<"Kosong";											//jika head bernilai NULL artinya tidak ada node untuk ditampilkan
	}
		else													//jika ada >1 node
		{
			bantu = head;										//nilai head di-assign kepada variabel bantu (kadang disebut variabel penunjuk posisi
			while (bantu != NULL)								//selama variabel ini tidak menunjuk nilai NULL, lakukan:
			{
				cout << " Nama   : " << bantu -> nama;			
				cout << " Umur   : " << bantu -> umur;
				cout << " Tinggi : " << bantu -> tinggi << endl;
				bantu = bantu -> next;							//pointer next dari variabel bantu di-assign untuk menggeser posisi node yang ditunjuk 
																	//sampai akhirnya variabel menunjuk nilai NULL dan keluar dari loop
			}
		}
		
	getch();
}
 
void tambah_tengah() 							//menyisipkan node di posisi tertentu di tengah list
{
    int sisip;									// deklarasi variabel lokal "sisip"

    cout << "Masukan posisi sisip anda : ";
    cin >> sisip;								

    bantu = head;								//pertama variabel penunjuk posisi harus disetel untuk menunjuk node head
    for (int i = 1; i < sisip - 1; i++ )			//perulangan akan dilakukan untuk menggeser posisi node yang ditunjuk 
													//sampai dimana kita mau menyisipkan node baru
    {
    	bantu = bantu -> next;					//pointer next dari node penunjuk posisi akan terus bergeser sampai ketentuan for = false
    }											

    buat_baru();								// memanggil prosedur membuat simpul baru

    bantu2 = bantu -> next;						//1. Variabel bantu2 akaan diisi oleh yang ditunjuk oleh var bantu setelah loop tadi (Simpul setelh simpul baru)
    bantu -> next = baru;						//2. Var bantu menunjuk next dimana, next berisi simpu; baru tsb (proses menghubungkan var baru dengan var sebelumnya)
    baru -> prev = bantu;						//3. Simpul baru menunjuk var bantu di kirinya (sekarang simpu; baru dan bantu tadi sudah saling terhubung)
    baru -> next = bantu2;						//4. Simpul baru menunjuk var bantu2 disebelah kanan 
    bantu2 -> prev = baru;						//5. Var bantu2 menunjuk simpul baru disebelah kirinya (sekarang simpul baru dan simpul setelahnya juga sudah terhubung)
}

void hapus_tengah()
{
	int sisip;
    
    cout << "Masukan posisi sisip anda : ";
    cin >> sisip;
    
    bantu = head;								//pertama variabel penunjuk posisi harus disetel untuk menunjuk node head
    for (int i = 1; i < sisip - 1; i++ )			//perulangan akan dilakukan untuk menggeser posisi node yang ditunjuk 
													//sampai dimana kita mau menyisipkan node baru
    {
    	bantu = bantu -> next;					//pointer next dari node penunjuk posisi akan terus bergeser sampai ketentuan for = false
    }

   	hapus = bantu -> next;						//1. Hapus diisi oleh apa yang ditunjuk oleh var bantu / simpul bantu
   	bantu2 = hapus -> next;						//2. var bantu2 diisi oleh apa yang ditunjuk hapus 
   	bantu -> next = hapus -> next;				//3. Menghubungkan apa yang ditunjuk bantu di kanan dengan yang ditunjuk hapus dikanan
   													//(Melepas simpul yang ingin didelet)
   	bantu2 -> prev = bantu;						//4. Var bantu2 menunjuk prev(kiri), dimana prev berisi var bantu 
   													//((sekarang simpul sebelum simpul hapus dan simpul sesudah simpul hapus saling terhubung))
   	delete hapus;								//5. Delet hapus
}

// Main program
int main()
{
	do
	{
		system("CLS");
		cout << "MENU DOUBLE LINKEDLIST" << endl;
		cout << "1. Tambah Depan" << endl;
		cout << "2. Tambah Belakang" << endl;
		cout << "3. Hapus Depan" << endl;
		cout << "4. Hapus Belakang" << endl;
		cout << "5. Tampilkan" << endl;
		cout << "6. Tambah Tengah" << endl;
		cout << "7. Hapus Tengah" << endl;
		cout << "8. Selesai" << endl;
		cout << "Pilihan Anda : ";
		cin >> pil;
		
		pilih();
	} 
	while (pil != 8);
}
