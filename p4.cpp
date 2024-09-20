/* Linked List Berkepala dan Berekor */
#include <iostream>
#include <malloc.h>
using std::cout;
#define true 1
#define false 0
typedef int typeinfo;
typedef struct typenode *typeptr;
typedef struct typenode{typeinfo info;
	                    typeptr next;
	                    };
typeptr kepala,ekor;
void buatlist();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);

void bacamaju();
void bacamundur();
void bacaback();
int listkosong();
int main()
{
  buatlist();
  sisipnode(50);
  sisipnode(20);
  sisipnode(5);
  sisipnode(100);
  sisipnode(70);
  sisipnode(25);
  sisipnode(40);
  bacamaju();
  cout << "\n\nHapus node 20\n";
  cout << "\nList setelah dihapus, dibaca dari belakang :\n\n";
  hapusnode(20);
  bacamundur();
}
void buatlist()
{
  kepala=(typenode *)malloc(sizeof(typenode));
  ekor=(typenode *)malloc(sizeof(typenode));
  kepala->info=-9999;
  kepala->next=ekor;
  ekor->info=9999;
  ekor->next=NULL;
}
int listkosong()
{ if(kepala->next==ekor)
	 return(true);
  else
	 return(false); }
void sisipnode(typeinfo IB)
{
  typeptr NB, bantu;
  NB=(typenode *) malloc(sizeof(typenode));
  NB->info=IB;
  bantu=kepala;
  while (IB > bantu->next->info)
  bantu=bantu->next;
  NB->next=bantu->next;
  bantu->next=NB;
}
void hapusnode(typeinfo IH)
{ typeptr hapus, bantu;
  if (listkosong())
	 cout << "List masih kosong";
else
  { bantu=kepala;
	while (bantu->next!=ekor && IH!=bantu->next->info)
	bantu=bantu->next;
	 if (IH==bantu->next->info)
	 { hapus=bantu->next;
	   bantu->next=hapus->next;
	   free(hapus); }
else
	cout << "Node tidak ditemukan!\n";
  }
}

void bacamaju()
{
  typeptr bantu;
  bantu=kepala->next;
  while (bantu!=ekor)
  {
	 cout << " " << bantu->info;
	 bantu=bantu->next;
  }
}
void bacamundur()
{
  typeptr depan,bantu;
  depan=kepala;
  kepala=ekor;
  do { bantu=depan;
	 while (bantu->next!=ekor)
	  bantu=bantu->next;
	 ekor->next=bantu;
	 ekor=bantu;
	 } while (ekor!=depan);
  ekor->next=NULL;
  bantu=kepala->next;
  while (bantu!=ekor)
  { cout << " " << bantu->info;
	 bantu=bantu->next;  }
}
