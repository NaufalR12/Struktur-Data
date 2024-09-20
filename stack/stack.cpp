/Program Stack menggunakan pointer/
#include <iostream>
#include <malloc.h>
#define True 1
#define False 0
using std::cout;
using std::cin;
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
{ 
buatstack();
  int angka, a;
    cout << "Jumlah data yang ingin diinput : ";
    cin >> a;
    buatstack();
    for (int i = 0; i < a; i++)
    {
        cout << "Masukan Angka : ";
        cin >> angka;
        push(angka);
    }

  cetakstack();
  cout << " \n\n";
  //pop();
  //cetakstack();
}
void buatstack()
{
  stack = NULL;
  stackawal = NULL;
}


int stackkosong()
{ if(stackawal==NULL)
	 return(True);
  else
	 return(False);
}
void push(typeinfo IB)
{
  typeptr NS;
  NS = (typestack *)malloc(sizeof(typestack));
  NS->info = IB;
  NS->next = NULL;

  if (stackawal == NULL) {
    stackawal = NS;
    stack = NS;
  } else {
    stack->next = NS;
    stack = NS;
  }
}


void pop()
{
  if (stackkosong())
  {
    cout << "Stack kosong!\n";
  }
  else
  {
    typeptr hapus, bantu;
    bantu = stackawal;
    hapus = stack;

    if (hapus == stackawal)
    {
      stackawal = NULL;
      stack = NULL;
    }
    else
    {
      while (bantu->next != stack)
      {
        bantu = bantu->next;
      }
      stack = bantu;
      stack->next = NULL;
    }
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