#include <iostream>
#include <conio.h>
#include <windows.h>
 
using namespace std;
 
struct Node{
    struct Node *father;
    int info;
    struct Node *left, *right;
};
 
typedef struct Node simpul;
simpul *root, *p, *q, *r, *bantu;
int x;
 
void Inisialisasi(){
    root = NULL;
    bantu = NULL;
    p = NULL;
}
 
void BuatSimpul(){
    p=(simpul*) malloc(sizeof(simpul));
    if(p!=NULL){
        p->info = x;
        p->left = NULL;
        p->right = NULL;
        p->father = NULL;
    }else{
        cout<<"Memory Heap Full"<<endl;
        exit(1);
    }
}
 
void BuatSimpulAkar(){
    if(root==NULL){
        if(p!=NULL){
            root=p;
        }else{
            cout<<"Simpul belom dibuat"<<endl;
        }
    }else{
        cout<<"Pohon sudah ada"<<endl;
    }
}
 
void pilihan(){
    int menu=0;
    cout<<"1. Insert root"<<endl;
    cout<<"2. Insert kiri"<<endl;
    cout<<"3. Insert kanan"<<endl;
    cout<<"4. keluar"<<endl;
    cout<<"Pilihan: "; cin>>menu;
    if(menu==1||menu==2||menu==3){
        system("CLS");
        cout<<"Menu terpilih: "<<menu<<endl;
        cout<<"Masukkan angka: "; cin>>x;
        switch(menu){
        case 1:
        BuatSimpul();
        BuatSimpulAkar();
        break;
 
        case 2:
        if(root==NULL){
            cout<<"Belum ada root"<<endl;
        }else{
            if(root->left==NULL){
                BuatSimpul();
                root->left = p;
                p->father = root;
            }else{
                bantu=root->left;
                while(bantu->left!=NULL && bantu->right!=NULL){
                    int pilih;
                    A:
                    cout<<"Pilih arah: "<<endl;
                    cout<<"1. Ke kiri"<<endl;
                    cout<<"2. Ke kanan"<<endl;
                    cout<<"Pilihan: "; cin>>pilih;
                    if(pilih==1){
                        bantu=bantu->left;
                    }else if(pilih==2){
                        bantu=bantu->right;
                    }else{
                        goto A;
                    }
                }
                int pilih;
                C:
                cout<<"Pilih posisi node baru: "<<endl;
                cout<<"1. Sebelah kiri"<<endl;
                cout<<"2. Sebelah kanan"<<endl;
                cout<<"Pilihan: "; cin>>pilih;
                BuatSimpul();
                if(pilih==1){
                    bantu->left = p;
                }else if(pilih==2){
                    bantu->right = p;
                }else{
                    goto C;
                }
                p->father = bantu;
            }          
        }
        break;
 
        case 3:
        if(root==NULL){
            cout<<"Belum ada root"<<endl;
        }else{
            if(root->right==NULL){
                BuatSimpul();
                root->right = p;
                p->father = root;
            }else{
                bantu=root->right;
                while(bantu->left!=NULL && bantu->right!=NULL){
                    int pilih;
                    B:
                    cout<<"Pilih arah: "<<endl;
                    cout<<"1. Ke kiri"<<endl;
                    cout<<"2. Ke kanan"<<endl;
                    cout<<"Pilihan: "; cin>>pilih;
                    if(pilih==1){
                        bantu=bantu->left;
                    }else if(pilih==2){
                        bantu=bantu->right;
                    }else{
                        goto B;
                    }
                }
                int pilih;
                D:
                cout<<"Pilih posisi node baru: "<<endl;
                cout<<"1. Sebelah kiri"<<endl;
                cout<<"2. Sebelah kanan"<<endl;
                cout<<"Pilihan: "; cin>>pilih;
                BuatSimpul();
                if(pilih==1){
                    bantu->left = p;
                }else if(pilih==2){
                    bantu->right = p;
                }else{
                    goto D;
                }
                p->father = bantu;
            }
        }
        break;
        }
    }else if(menu==4){
        exit(1);
    }else{
        cout<<"Menu salah!"<<endl;
        pilihan();
    }
}
 
int main(){
    Inisialisasi();
    while(true){
        pilihan();
    }
    return 0;
}
