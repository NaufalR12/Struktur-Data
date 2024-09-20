#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

typedef int typeinfoI;
typedef string typeinfoS;
typedef struct typenode *typeptr;
typedef struct typenode{typeinfoI infoI;
						typeinfoS infoS;
						typeptr next;
						};
typeptr awal,akhir;

void buatlistbaru();
void sisipnode();
bool listkosong();
void bacamaju();
void hapusnode();

int main(){
	int pilih;
	buatlistbaru();
	while(true){
		system("cls");
	cout << "1. Input Node " << endl;
	cout << "2. Baca Maju " << endl;
	cout << "3. Hapus Node" << endl;
	cout << "4. Keluar" << endl;
	cout << "-----" << endl;
	cout << "Pilih : ";
	cin >> pilih;
	
	switch (pilih) {
		case 1 :
		sisipnode();
		system("pause");
		break;
		case 2 :
		bacamaju();
		system("pause");
		break;
		case 3 :
		hapusnode();
		system("pause");
		break;
		case 4 :
		exit(0);
		break;
		default :
		break;
	}
}
	return 0;
};

void buatlistbaru(){
	awal = NULL;
	akhir = NULL;
}

bool listkosong(){
	if(awal == NULL)
	return true;
	else
	return false;
}
	
void sisipnode(){
	typenode* NB = new typenode;
		
	string IBs;
	int IBi;
	
	cout << "Masukkan string : ";
	cin >> IBs;
	cout << "Masukkan angka : ";
	cin >> IBi;
	
	NB->infoS=IBs;
	NB->infoI=IBi;
	
	if(listkosong()){
		NB -> infoS = IBs;
		NB -> infoI = IBi;
		NB -> next = NULL;
		awal = NB;
		akhir = NB;
	}
	else if(awal -> next == NULL && akhir == NULL){
		NB -> infoS = IBs;
		NB -> infoI = IBi;
		NB -> next = awal;
		awal -> next = NB;
	}
	else{
		NB -> infoS = IBs;
		NB -> infoI = IBi;
		NB -> next = awal;
		akhir -> next = NB;
		akhir = NB; 
	}
}

void bacamaju()
{
  typeptr bantu;
  bantu=awal;
  do
  {
	 cout << " " << bantu->infoS;
	 cout << " " << bantu->infoI;
	 bantu=bantu->next;
	 cout << endl;
  }while (bantu!=awal); 
}

void hapusnode()
{ typeptr hapus, bantu;
	
	string IHs;
	int IHi;
	
	cout << "Masukkan string : ";
	cin >> IHs;
	cout << "Masukkan angka : ";
	cin >> IHi;
  if (listkosong())
	 cout << "List masih kosong\n";
  else if (awal->infoS==IHs)
  { hapus=awal;
    awal=hapus->next;
    free(hapus);
  }

  else
  { bantu=awal;
    while (bantu->next->next!=NULL && IHs!=bantu->next->infoS)
 	 bantu=bantu->next;
    if (IHs==bantu->next->infoS)
	 { hapus=bantu->next;
		if (hapus==akhir)
		  { akhir=bantu;
                 akhir->next=NULL; }
		else
		  bantu->next=hapus->next;
		  free(hapus);
	 }
    else
	cout << "Node tidak ditemukan!\n";
  }
}
