/* Implementasi PTB (BST) */
#include <iostream>
#include <malloc.h>
#define true 1
#define false 0
using std::cout;
using std::cin;
typedef int typeinfo;
typedef struct typenode *typeptr;
typedef struct typenode{typeinfo info;
				typeptr kiri, kanan;
							  };
typeptr akar,p,b;
int  NH;
void buat_ptb();
int ptb_kosong();
void sisipnode(typeinfo IB);
void cetak();
void preorder(typeptr akar);
void inorder(typeptr akar);
void postorder(typeptr akar);
void hapusnode(typeinfo IH);
void hapus();
int main()
{
  buat_ptb();
  sisipnode(40);
  sisipnode(10);
  sisipnode(5);
  sisipnode(20);
  sisipnode(15);
  sisipnode(25);
  sisipnode(35);
  sisipnode(45);
  sisipnode(30);
  
sisipnode(70);
  sisipnode(50);
  sisipnode(10);
  cetak();
  cout << "\n\nNode yg dihapus harus terdapat pada PTB!";
  cout << "\n\nMasukkan node yg dihapus : ";
  cin >> NH;
  hapusnode(NH);
  cetak();
  return 0;
}

void buat_ptb()
{ typeptr ptb;
  ptb=NULL;
  akar=ptb; }

int ptb_kosong()
{ if(akar==NULL)
	 return(true);
  else
	 return(false); }
void sisipnode(typeinfo IB)
{ typeptr NB;
  NB=(typenode *) malloc(sizeof(typenode));
  NB->info=IB;
  NB->kiri=NULL;
  NB->kanan=NULL;
  if (ptb_kosong())
	 akar=NB;
  else
	 { b=akar;
		p=akar;
		// mencari tempat untuk menyisipkan node
		while(p!=NULL && IB!=p->info)
		  { b=p;
			 if (IB<p->info)
				p=b->kiri;
			 else
				p=b->kanan; }
		if (IB==b->info)
		  cout << "\n\nNode " << IB << " sudah ada !\n\n";
		else
		  { if (IB<b->info)
				b->kiri=NB;
			 else
				b->kanan=NB; }
	 }
}
void cetak()
{
  cout << "\nPre-order :  ";
  preorder(akar);
  cout << "\nIn-order  :  ";
  inorder(akar);
  cout << "\nPost-order:  ";
  postorder(akar);
  return;
}

/*void preorder(typeptr akar)
{ if (akar!=NULL)
	 { cout << " " << akar->info;
		preorder(akar->kiri);
		preorder(akar->kanan); }
}
void inorder(typeptr akar)
{ if (akar!=NULL)
	 { inorder(akar->kiri);
		cout << " " << akar->info;
		inorder(akar->kanan); }
}
void postorder(typeptr akar)
{ if (akar!=NULL)
	 { postorder(akar->kiri);
		postorder(akar->kanan);
		cout << " " << akar->info; }
}
void hapusnode(typeinfo IH)
{
  if (ptb_kosong())
	  cout << "PTB Kosong !\n\n";
  else
	 { b=akar;
		p=akar;
}}*/

void preorder(typeptr akar)
{ if (akar!=NULL)
	 { cout << " " << akar->info;
		preorder(akar->kiri);
		preorder(akar->kanan); }
}
void inorder(typeptr akar)
{ if (akar!=NULL)
	 { inorder(akar->kiri);
		cout << " " << akar->info;
		inorder(akar->kanan); }
}

void postorder(typeptr akar)
{ if (akar!=NULL)
	 { postorder(akar->kiri);
		postorder(akar->kanan);
		cout << " " << akar->info; }
}
void hapusnode(typeinfo IH)
{
  if (ptb_kosong())
	  cout << "PTB Kosong !\n\n";
  else
	 { b=akar;
		p=akar;

		// mencari tempat hapus node
		while(p!=NULL && IH!=p->info)
		  { b=p;
			 if (IH<p->info)
				p=b->kiri;
			 else
				p=b->kanan; }
	 }
  hapus();
}

void hapus()
{ typeptr temp;
// Bila PTB terdiri dari akar saja atau akar dengan 1 anak kiri/kanan
  if (p->kiri==NULL && p->kanan==NULL)
	  {
		 if (b==akar && p==akar)
			 akar=NULL;
		 else
			 {
				if (p==b->kiri)
					b->kiri=NULL;
				else
					b->kanan=NULL;
			 }
		free(p);
	  }


// Bila PTB memiliki anak kiri dan anak kanan dgn banyak anak cabang
  else if (p->kiri!=NULL && p->kanan!=NULL)
	  {
		 temp=p->kiri;
		 b=p;
		 while (temp->kanan != NULL)
			{ b=temp;
			  temp=temp->kanan; }
		 p->info=temp->info;
		 if (b==p)
			 b->kiri = temp->kiri;
		 else
			 b->kanan = temp->kiri;
		 free(temp);
	  }
// Bila PTB memiliki anak kiri saja dgn banyak anak cabang
  else if (p->kiri!=NULL && p->kanan==NULL)
	  {
		 if (b==p)
			 akar=p->kiri;
		 else
			{ if (p==b->kiri)
				  b->kiri=p->kiri;
			  else
				  b->kanan=p->kiri;
			}
		 free(p);
	  }

// Bila PTB memiliki anak kanan saja dgn banyak anak cabang
  else if (p->kiri==NULL && p->kanan!=NULL)
	  {
		 if (b==p)
			 akar=p->kanan;
		 else
			{ if (p==b->kanan)
				  b->kanan=p->kanan;
			  else
				  b->kiri=p->kanan;
			}
		 free(p);
	  }
}
