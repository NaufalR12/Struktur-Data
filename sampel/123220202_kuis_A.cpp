#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;

struct data {
	char namabuku[30];
	char penulis[30];
	int stok;
	float harga;
	int info;
	data* next;
};

data* awal=NULL;
data* akhir=NULL;

void buatlistbaru(){
	awal=(data*) malloc(sizeof(data));
	awal->harga=-1;
	akhir=(data*)malloc(sizeof(data));
	akhir->harga=1001;
	akhir->next=NULL;
	awal->next=akhir;
}
bool ceklistkosong(){
	return (awal==NULL);
}

void sisipheadtail(char namabukubaru[30], char penulisbaru[30], int stokbaru, float hargabaru){
	data* bantu=awal;
	data* nodebaru=(data*)malloc(sizeof(data));
	strcpy(nodebaru->namabuku,namabukubaru);
	strcpy(nodebaru->penulis,penulisbaru);
	nodebaru->stok=stokbaru;
	nodebaru->harga=hargabaru;
	nodebaru->next=NULL;
	while(bantu->next != akhir && hargabaru>bantu->next->harga){
	bantu=bantu->next;
	}
	nodebaru->next=bantu->next;
	bantu->next=nodebaru;
}

void cetaklist(){
	if(awal->next==akhir){
		cout<<"List ini masih kosong"<<endl;
	}else{
		data* bantu=awal->next;
		while(bantu!=akhir){
			cout<<"Nama Buku	: "<<bantu->namabuku<<endl;
			cout<<"Penulis		: "<<bantu->penulis<<endl;
			cout<<"Stok		: "<<bantu->stok<<endl;
			cout<<"Harga	: "<<bantu->harga<<endl;
			bantu=bantu->next;
		}
	}
}

void hapus(const char hapusnama[30]){
	data* bantu=awal;
	while(bantu->next!=awal){
		if(strcmp(bantu->next->namabuku,hapusnama)==0){
			data* hapus=bantu->next;
			bantu->next=hapus->next;
			free(hapus);
			cout<<"telah dihapus"<<endl;
		}
		bantu=bantu->next;
	}
	cout<<"data tidak ditemukan"<<endl;
}	
void caribuku(){
		string namaCari;
        cout << "Masukkan nama buku yang ingin dicari: ";
        cin.ignore(); 
        getline(cin, namaCari);

        data* bantu = awal;
        while (bantu != NULL) {
            if (bantu->namabuku == namaCari) {
                cout << "Nama Buku: "<<bantu->namabuku<< endl;
                cout << "Penulis: "<<bantu->penulis<<endl;
                cout << "Harga: "<<bantu->harga<<endl;
                cout << "Stok: "<<bantu->stok<<endl;
                return;
            }
            bantu = bantu->next;
        }cout << "Buku dengan Nama "<< namaCari << " tidak ditemukan." << endl;
    }

	int main(){
	
		char namabuku[30];
		char penulis[30];
		int stok;
		float harga;
		int menu;
		int i;
		int banyak;
		char hapusnama[30];
	buatlistbaru();
	do{
	cout<<"PENDATAAN TOKO BUKU GRAMEDONO"<<endl;
	cout<<"============================="<<endl<<endl;
	cout<<"1.	Input Stok Buku Baru"<<endl;
	cout<<"2.	Cari Buku"<<endl;
	cout<<"3.	Lihat Data Buku"<<endl;
	cout<<"4.	Hapus Data Buku"<<endl;
	cout<<"menu	: ";
	cin>>menu;
	system("cls");
	switch(menu){
		case 1 :
		cout<<"INPUT DATA BUKU"<<endl;
		i=0;
		cout<<"Jumlah data Yang Ingin Dinputkan : ";
		cin>>banyak;
		cin.ignore();
		do{
			cout<<"Nama Buku	: ";
			cin.getline(namabuku,30);
			cout<<"Penulis		: ";
			cin.getline(penulis,30);
			cout<<"Stok		: ";
			cin>>stok;
			cout<<"Harga	: ";
			cin>>harga;
			cin.ignore();
			cout<<endl;
			sisipheadtail(namabuku,penulis,stok,harga);
			i++;
		}while(i<banyak);
		cout<<"Data telah diinputkan"<<endl;
		system("pause");
		system("cls");
		break;
		
		case 2 :
		cout<<"Cari data buku"<<endl;
		caribuku();
		system("pause");
		system("cls");
		break;
		
		case 3 :
		cout<<"List Data Buku"<<endl;
		cetaklist();
		system("pause");
		system("cls");
		break;
		
		case 4 :
			cout<<"Hapus Data Buku"<<endl;
			cin.ignore();
			cout<<"Input Nama Buku Yang ingin Dihapus : ";
			cin.getline(hapusnama,30);
			hapus(hapusnama);
			cout<<"geko";
			system("cls");
			break;
		}
	}while(menu !=5);
}

