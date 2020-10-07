#include <iostream>
#include <conio.h>
#include <cstdlib> 			//function malloc(), free()
#include <cstring>

using namespace std;

//variabel dan function global
int pilih;
int menu_admin();
int isi_data();
int tambah_depan();
int tambah_tengah();
int tambah_belakang();
int hapus_depan();
int hapus_tengah();
int hapus_belakang();
int display();

//struktur dari node
struct node
{
char nim [15];
char nama [20];
int umur;
struct node *link;
} *newNode, *first = NULL, *last = NULL, *hapus, *posisi; 		//variabel dengan atribut struct, untuk menentukan posisi node newNode dalam list

int menu_admin()
{
    if (pilih == 1)
    
    {
    	system("CLS");
    	tambah_depan();										//menambah node di paling kiri
	}
		else if (pilih == 2)
		{
			system("CLS");
			tambah_tengah();
		}
		
    	else if (pilih == 3)
    	{
    		system("CLS");
    		tambah_belakang();								//menambah node di paling kanan
		}
		
		else if (pilih == 4)
		{
			system("CLS");
			hapus_depan();									//menghapus node di paling kiri
		}
		
		else if (pilih == 5)
		{
			system("CLS");
			hapus_tengah();
		}
		
     	else if (pilih == 6)
        {
        	system("CLS");
        	hapus_belakang();								//menghapus node di paling kanan
		}
		
      	else if (pilih == 7)
        {
        	system("CLS");
        	display();										//menampilkan daftar node
		}
    		else
        	{
        		return 0;
			}
}

int isi_data()											//function u/ mengisi data node yang ingin dibuat
{
    //newNode = (node*) malloc(sizeof(struct node)); 	//memesan memori sebesar ukuran struct dengan function malloc()
	newNode = new (node);								//lalu mengisi nilai tsb ke pointer node*
														//dan memasukkan seluruh nilai dalam variabel pointer tsb ke dalam node "newNode"
    
    cout << "NIM   : ";
	cin >> newNode -> nim;
    cout << "Nama  : ";
	cin >> newNode -> nama;
    cout << "Umur  : ";
	cin >> newNode -> umur;
	
    newNode -> link = NULL;								//pointer dari node "newNode" ditunjuk ke nilai NULL untuk menghentikan list
}

int tambah_depan()										//menambah link sebanyak satu node di sebelah kiri
{
    isi_data();											//mengisi data untuk node newNode
    
    if (first == NULL)									//apabila tidak ada node mula-mula maka node yang dibuat adalah node terakhir
    													//sekaligus node pertama dan node terlast
    {
        first = newNode;
        last = newNode;
        last -> link = NULL;							//karena newNode dibuat 1 buah node maka pointer node tsb tidak punya node lain untuk ditunjuk
        												//sehingga nilai pointer link dari node tsb di-assign sebagai NULL
    }
    	else											//apabila sudah ada node lain, maka node newNode di-assign sebagai node paling first,
    													//menggeser posisi node sebelumnya
    	{
        	newNode -> link = first;
        	first = newNode;
    	}
    	
    cout << endl << endl;
    
    display();
}

int tambah_tengah()
{
int x;														//Variabel lokal n

	isi_data();												//membuat node baru
	
	if (first == NULL)										//apabila tidak ada node awal maka node baru akan menjadi node paling awal dan paling akhir
	{
		first = newNode;
		last = newNode;
		last -> link = NULL;
	}
		else												//apabila ada node lain maka node baru akan diletakkan setelah node tertentu
		{
		   	cout << "Letakkan input sebagai link ke: "; 
			cin >> x;
			
			posisi = first;
			
			for (int i = 1; i <= x - 2; i++)					//menentukan posisi node baru
			{
				posisi = posisi -> link;
			}
			
			newNode -> link = posisi -> link;
			posisi -> link = newNode;
		}
		
		cout << endl << endl;
		
		display();
}

int tambah_belakang()										//menambah link sebanyak satu node di sebelah kanan
{
    isi_data();												//mengisi data untuk node newNode
    
    if (first == NULL)										//apabila tidak ada node sebelumnya, maka node yang dibuat akan di-assign sebagai node first
    {
        first = newNode;
    }
    
    	else
    	{
    	    last -> link = newNode;							//apabila sudah ada node sebelumnya maka pointer node yang paling kanan
															//akan menunjuk pada node newNode yang dibuat
    	}
    	
    last = newNode;											//node newNode yang dibuat di-assign sebagai node terlast
    last -> link = NULL;									//pointer dari node newNode yang dibuat di-assign ke nilai NULL untuk menghentikan list
    cout << endl << endl;
    
    display();												//menampilkan seluruh node
}

int hapus_depan()
{
    if (first == NULL)										//apabila tidak ada node first maka tidak ada node yang bisa dihapus
    {
    	cout << "Kosong";	
	}
    	else												
    	{
    	    hapus = first;									//apabila ada node, maka node paling kiri (node first) di-assign kepada variabel "hapus"
    	    first = first -> link;							//nilai node first ditukar menjadi nilai pointer yang tidak menunjuk apapun
    	    delete (hapus);									//isi variabel "hapus" dikosongkan
    	}
    	
	cout << endl << endl;

	display();												//menampilkan seluruh node
}

int hapus_tengah()
{
int x;																	//variabel lokal
int jumlah_link;														//variabel lokal
int deleted_link;														//variabel lokal

	if (first != NULL)													//apabila ada node untuk dihapus
	{
		cout << "Link yang dihapus urutan ke: ";						//tentukan urutan node dari indeks
		cin >> x;  
    
		jumlah_link = 1;
		posisi = first;  								
		                          
		while (posisi -> link != NULL)
		{
			posisi = posisi -> link;                    
			jumlah_link++;                         
		}
		
		if ((x < 1) || (x > jumlah_link))               				//apabila x < 1 artinya jumlah node 0 (belum membuat list)
																		//apabila x > jumlah link artinya urutan input user salah
		{
			cout << "Urutan link salah / belum ada link terbuat";
		}
			else                                    
			{                                       
				posisi = first;                           
				deleted_link = 1;                           
				
				while (deleted_link < (x-1))
				{
					posisi = posisi -> link;                  
					deleted_link++;                         
				}
				
				hapus = posisi -> link;                    
				posisi -> link = hapus -> link;              
				delete (hapus);                        
			}
	}
		else
		{
			cout << "Kosong";			
		}	
			
	cout << endl << endl;
	display();
	
getch();
}

int hapus_belakang()
{
    if (first == NULL)										//apabila tidak ada node first maka tidak ada node yang bisa dihapus
    {
        cout << "Kosong";    	
	}
	    else if (first == last)
	    {
    	    hapus = first;									//apabila ada hanya 1 node, maka node di-assign kepada variabel "hapus"
    	    first = first -> link;							//nilai node first ditukar menjadi nilai pointer yang tidak menunjuk apapun
    	    delete (hapus);									//isi variabel "hapus" dikosongkan
	    }
		    else
		    {
		        hapus = first;								//apabila ada lebih dari 1 node maka
		        
		        while (hapus -> link != last)				//selama pointer dari node "hapus" tidak sama dengan nilai node terlast
		        {
		            hapus = hapus -> link;					//nilai pointer node "hapus" akan menunjuk pada node di sebelahnya
		        }

		        last = hapus;								//nilai node "hapus di-assign kepada node terlast
		        hapus = last -> link;						//pointer dari node terlast di-assign kepada node "hapus"
		        last -> link = NULL;						//setelah alamatnya digeser maka pointer node terlast yang newNode ditunjuk kepada nilai NULL untuk menghentikan list
		        delete (hapus);								//nilai pada node "hapus" dikosongkan
		    }
		    
    cout<<endl<<endl;
    
    display();														//menampilkan daftar node
}

int display()														//function untuk menampilkan seluruh node
{
     if (first == NULL)												//jika tidak ada node first maka tidak ada yang bisa ditampilkan
    {
    	cout<<"Kosong";
	}
		else														//jika ada node untuk ditampilkan maka
		{
			posisi = first;											//nilai node pertama di-assign kepada node "posisi"
			while (posisi != NULL)
			{
				cout << "NIM  : " << posisi -> nim << endl;
				cout << "Nama : " << posisi -> nama << endl;
				cout << "Umur : " << posisi -> umur << endl;
				cout << endl;
				posisi = posisi -> link;							//selama pointer posisi tidak menunjuk pada nilai NULL maka posisi node-nya akan terus bergeser
			}
		}
getch();
}

//Main Program
int main()
{
    do
    {
        system("CLS");
        cout << "MENU SINGLE LINKED LIST " << endl
        	 << "1. Tambah Depan" << endl
        	 << "2. Tambah Tengah" << endl
        	 << "3. Tambah Belakang" << endl
        	 << "4. Hapus Depan" << endl
        	 << "5. Hapus Tengah" << endl
			 << "6. Hapus Belakang" << endl
        	 << "7. Tampilkan" << endl
        	 << "8. Selesai" << endl
        	 <<"Pilihan Anda: ";
        cin >> pilih;
        
        menu_admin();									//menampilkan daftar node
    } 
	while(pilih != 8);

getch();
return 0;
}
