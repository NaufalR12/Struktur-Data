#include <iostream>
#include <malloc.h>

using namespace std;

struct buku {
	int noBuku;
	string judul;
	string penulis;
	string penerbit;
	int tahunTerbit;
	string jenisBuku;
	buku* next;
	};


struct peminjaman {
	int noPeminjaman;
	string namaPeminjam;
	buku infoBuku;
	string tanggalPinjam;
	string tanggalKembali;
	};

struct Node{
	int info;
	Node* next;
};

Node *awal, *akhir;

void buatListBaru();
void sisipDepan(int infoBaru);
void cetakList();

int main(){
	buatListBaru();
	sisipDepan(3);
	sisipDepan(2);
	sisipDepan(1);
	sisipDepan(3);
	cetakList();
}

void buatListBaru(){
	awal = NULL;
	akhir = NULL;
}

void sisipDepan(int infoBaru){
	Node* listBaru;
	listBaru = (Node*) malloc(sizeof(Node));
	listBaru->info = infoBaru;
	listBaru->next = NULL;

	if(awal == NULL){
		awal = listBaru;
		akhir = listBaru;
	}
	else{
		listBaru->next = awal;
		awal = listBaru;
	}
}

void cetakList(){
	Node* bantu;
	bantu = awal;
	while(bantu != NULL){
		cout<<bantu->info<<" ";
		bantu = bantu->next;
	}
}
