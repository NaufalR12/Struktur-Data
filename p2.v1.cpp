#include <iostream>
#include <malloc.h>

using namespace std;

struct Node{
	int info;
	Node* next;
};

Node *list *awal, *akhir;

void buatListBaru();
void sisipDepan(int infoBaru);
void cetakList();

int main(){
	buatListBaru();
	sisipDepan(50);
	cout<<endl;
	cetakList();
}

void buatListBaru(){
	list = NULL;
	awal = list;
	akhir = list;
}

void sisipDepan(int infoBaru){
	Node* listBaru = (Node*) malloc(sizeof(Node));
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
	Node* bantu = awal;
	while(bantu != NULL){
		cout<<bantu->info<<" ";
		bantu = bantu->next;
	}
}
