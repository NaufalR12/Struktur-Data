#include <iostream>
#include <malloc.h>

using namespace std;

struct Node{
	int info;
	Node* next;
};

Node *awal, *akhir;

void buatListBaru();
void sisipDepan(int infoBaru);
void sisipTengah(int infoBaru);
void sisipBelakang(int infoBaru);
void sisipKondisional(int infoBaru); //bisa sisip depan, tengah atau belakang tergantung situasi;
void hapusList(int target);
void cetakList();

int main(){
	buatListBaru();
	sisipDepan(3);
	sisipDepan(1);
	cetakList();
	cout<<endl;
	sisipTengah(2);
	cetakList();
	sisipBelakang(5);
	hapusList(7);
	cout<<endl;
	cetakList();
}

void buatListBaru(){
	awal = NULL;
	akhir = NULL;
}

void sisipDepan(int infoBaru){
	//buat listBaru dengan data baru
	Node* listBaru = (Node*) malloc(sizeof(Node));
	listBaru->info = infoBaru;
	listBaru->next = NULL;
	
	//sisip awal
	if(awal == NULL){
		awal = listBaru;
		akhir = listBaru;
	}
	else{
		listBaru->next = awal;
		awal = listBaru;
	}
}

void sisipTengah(int infoBaru){
	//buat listBaru dengan data baru
	Node* listBaru = (Node*) malloc(sizeof(Node));
	listBaru->info = infoBaru;
	listBaru->next = NULL;
	
	Node* bantu = awal;
	//cari tahu dimana pointer bantu akan berhenti
	while(bantu->next->info < infoBaru){
		bantu = bantu->next;
	}
	
	//sisip tengah
	listBaru->next = bantu->next;
	bantu->next = listBaru;
}

void sisipBelakang(int infoBaru){
	//buat listBaru dengan data baru
	Node* listBaru = (Node*) malloc(sizeof(Node));
	listBaru->info = infoBaru;
	listBaru->next = NULL;
	
	//sisip belakang
	if(akhir == NULL){
		awal = listBaru;
		akhir = listBaru;
	}
	else{
		akhir->next = listBaru;
		akhir = listBaru;
	}
}

void hapusList(int target){
	Node* bantu = awal;
	//hapus list jika data di awal
	if(bantu->info == target){
		awal = bantu->next;
		free(bantu);
	}
	//hapus list jika data diakhir atau diawal
	else{
		while(bantu->next->info != target && bantu->next->next != NULL){
			bantu = bantu->next;
		}
		if(bantu -> next -> info == target){
			Node* bantuHapus = bantu->next;
			bantu->next = bantuHapus->next;
			free(bantuHapus);
		}else{
			cout<<"\nData Tidak Ada";
		}
	}
}

void cetakList(){
	Node* bantu = awal;
	while(bantu != NULL){
		cout<<bantu->info<<" ";
		bantu = bantu->next;
	}
}
