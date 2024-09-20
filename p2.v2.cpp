#include <iostream>
#include <malloc.h>

using namespace std;

struct Node {
    int info;
    Node* next;
};

Node *awal, *akhir;

void buatList();
void sisipDepan(int infoBaru);
void cetakList();
void hapusList(int hapus);

int main() {
    buatList();
    sisipDepan(50);
    sisipDepan(45);
    sisipDepan(30);
    sisipDepan(15);
    sisipDepan(100);
    cout << "List Lama : " << endl;
    cetakList();
    cout << "\n============================" << endl;
    cout << "List Baru : " << endl;
    hapusList(45);
    hapusList(50);
    cetakList();
}

void buatList() {
    awal = NULL; 
    akhir = NULL; 
}

void sisipDepan(int infoBaru) {
    Node* listBaru = (Node*)malloc(sizeof(Node));
    listBaru->info = infoBaru;
    listBaru->next = NULL;

    if (awal == NULL) {
        awal = listBaru;
        akhir = listBaru;
    } else {
        listBaru -> next = awal;
        awal = listBaru;
    }
}

void hapusList(int hapus){
	Node* bantu;
	bantu = awal;
	if(bantu->info == hapus){
		awal = bantu->next;
		free(bantu);
	}

	else{
		while(bantu->next->info != hapus && bantu->next->next != NULL){
			bantu = bantu->next;
		}
		if(bantu -> next -> info == hapus){
			Node* bantuHapus = bantu->next;
			bantu->next = bantuHapus->next;
			free(bantuHapus);
		}else{
			cout<<"\nData Tidak Ditemukan!";
		}
	}
}


void cetakList(){
	Node* bantu;
	bantu = awal;
	while(bantu != NULL){
		cout << bantu -> info << " ";
		bantu = bantu -> next;
	}
}
