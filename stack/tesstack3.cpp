/*Program Stack menggunakan pointer*/
#include <iostream>
#include <malloc.h>
#define True 1
#define False 0
using std::cout;
typedef int typeinfo;
typedef struct typestack *typeptr;
typedef struct typestack{typeinfo info;
		typeptr next;
		 };
typeptr stack, stackawal;
void buatstack();
int stackkosong();
void push(typeinfo IB);
void pop();
void cetakstack();

int main()
{ buatstack();
  push(25);
  push(15);
  push(20);
  push(100);
  cetakstack();
  cout << " \n\n";
  pop();
  cetakstack();
}

void buatstack()
{ typeptr NS;
  NS=(typestack *) malloc(sizeof(typestack));
  NS=NULL;
  stackawal=NS;
}

int stackkosong()
{ if(stackawal==NULL)
	 return(True);
  else
	 return(False);
}

void push(typeinfo IB)
{ typeptr NS;
  NS=(typestack *) malloc(sizeof(typestack));
  NS->info=IB;
  if (stackawal==NULL)
	  stackawal=NS;
  else
	  stack->next=NS;
  stack=NS;
  stack->next=NULL;
}

void pop()
{ typeptr hapus, bantu;
  if (stackkosong())
  {	 cout <<"Stack kosong !\n"; }
  else
  {	 bantu=stackawal;
	 hapus=stack;
	 if (hapus==stackawal)
	{   stackawal=NULL;}
	 else
	 { while(bantu->next->next!=NULL)
 	     bantu=bantu->next;
	     stack=bantu;
	     stack->next=NULL;
	 };
  free(hapus);
  }
}
void cetakstack()
{
  typeptr bantu;
  bantu=stackawal;
  while(bantu!=NULL)
  {	 cout << " " << bantu->info << '\n';
	 bantu=bantu->next;
  }
}
