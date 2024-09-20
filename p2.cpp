/* Implementasi Linked List dengan pointer */
#include <iostream>
#include <malloc.h>
#define true 1
#define false 0
using std::cout;

typedef int typeinfo;
typedef struct typenode *typeptr;
typedef struct typenode{typeinfo info;
typeptr next;};
typeptr awal,akhir;
void buatlistbaru();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);
void bacamaju();
void bacamundur();
int listkosong();
int main()
{
  cout << "List Mula-mula :\n";
  buatlistbaru();
  sisipnode(50);
  sisipnode(20);
  sisipnode(5);
  sisipnode(100);
  sisipnode(70);
  sisipnode(25);
  bacamundur();
  //bacamaju();
  
  //cout << "\n\nHapus node 50\n";
  cout << "\nDibaca dari belakang :\n";
  //hapusnode(50);
  bacamundur();
  return 0;
}

void buatlistbaru()
{
  typeptr list;
  list=NULL;
  awal=list;
  akhir=list;
}

int listkosong()
{ if(awal==NULL)
	 return(true);
  else
	 return(false); }

void sisipnode(typeinfo IB)
{ typeptr NB, bantu;
  NB=(typenode *) malloc(sizeof(typenode));
  NB->info=IB;
  NB->next=NULL;
  if (listkosong())
  { awal=NB;
	 akhir=NB; }
  else if (IB <= awal->info)       // Sisip di depan
	 { NB->next=awal;
		awal=NB; }
  else
	 { bantu=awal;
		while (bantu->next!=NULL && IB > bantu->next->info)
			  bantu=bantu->next;
		NB->next=bantu->next;  // Sisip di tengah atau di belakang
		bantu->next=NB;
		if (IB>akhir->info)
			akhir=NB;
	 }
}

void hapusnode(typeinfo IH)
{ typeptr hapus, bantu;
  if (listkosong())
	 cout << "List masih kosong";
  else if (awal->info==IH)
  { hapus=awal;                      // Hapus di awal
	 awal=hapus->next;
	 free(hapus); }
  else
  { bantu=awal;
	 while (bantu->next->next!=NULL && IH!=bantu->next->info)
		 bantu=bantu->next;
	 if (IH==bantu->next->info)
		 { hapus=bantu->next;
			if (hapus==akhir)             // Hapus di akhir
			  { akhir=bantu;
				 akhir->next=NULL; }
			else
				 bantu->next=hapus->next;   // Hapus di tengah
			free(hapus);
		  }
	 else
		cout << "Node tidak ditemukan!\n";  }
}

void bacamaju()
{
  typeptr bantu;
  bantu=awal;
  while (bantu!=NULL)
  {
	 cout << " " << bantu->info;
	 cout << "  ";
	 bantu=bantu->next;
  }
}
void bacamundur()
{ typeptr depan,bantu;
  depan=awal;
  awal=akhir;
  do { bantu=depan;
	 while (bantu->next!=akhir)
		  bantu=bantu->next;
	 akhir->next=bantu;
	 akhir=bantu;
	 } while (akhir!=depan);
  akhir->next=NULL;
  bantu=awal;
  while (bantu!=NULL)
  { cout << " " << bantu->info;
	 cout << "  ";
	 bantu=bantu->next;  }
}
