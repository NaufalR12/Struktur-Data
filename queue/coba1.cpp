/* Implementasi queue menggunakan Array */
#include <iostream>
#include <malloc.h>
#define max 50
#define True 1
#define False 0
using std::cout;
typedef struct typequeue{int belakang;
				 int elemen[max]; };
struct typequeue queue;
void buatqueue();
void cetakqueue();
void enqueue(int IB);
void dequeue();
int queuekosong();
int queuepenuh();
int main()
{ buatqueue();
  enqueue(12);
  enqueue(78);
  enqueue(5);
  enqueue(34);
  cetakqueue();
  cout << "\n\n";
  dequeue();
  cetakqueue();
  cout << "\n\n";
  dequeue();
  cetakqueue();
  cout << "\n\n";
  enqueue(89);
  cetakqueue();
}

void buatqueue()
{ 
   queue.belakang=0; 
}

int queuekosong()
{ 
  if(queue.belakang==0)
	 return(True);
  else
	 return(False); 
}

int queuepenuh()
{ if(queue.belakang==max)
	 return(True);
  else
	 return(False); }

void enqueue(int IB)
{ if(queuepenuh())
	 cout << "queue overflow\n";
  else
	 {queue.belakang++;
	  queue.elemen[queue.belakang]=IB; }
}

void dequeue()
{ int ID, i;
  if(queuekosong())
	 cout << "queue underflow\n";
  else

	 {ID=queue.elemen[1];
	  for (i=1; i<queue.belakang; i++)
		  queue.elemen[i]=queue.elemen[i+1];
	  queue.belakang--; }
}
void cetakqueue()
{ int i=1;
  while(i<=queue.belakang)
		  { cout << " " << queue.elemen[i];
			 i++; }
}
