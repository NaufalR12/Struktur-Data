/*Stack Menggunakan Record*/
#include <iostream>
#include <malloc.h>
#define max 50
#define True 1
#define False 0
using namespace std;

typedef struct typestack{
    int top;
	int elemen[max];
};

struct typestack stack;
void buatstack();
void cetakstack();
void push(int IB);
void pop();
int stackkosong();
int stackpenuh();

int main()
{
  buatstack();
  push(10);
  push(76);
  push(12);
  push(1);
  cetakstack();
  cout << " \n\n";
  pop();
  pop();
  pop();
  cetakstack();
}

void buatstack(){   
    stack.top=-1;  
}

int stackkosong(){  
    if (stack.top==-1)
	    return(True);
    else
        return(False);  
}

int stackpenuh(){  
    if (stack.top==max)
		 return(True);
    else
		 return(False);  
}

void push(int IB)
{  if(stackpenuh())
	 cout << "stack overflow\n";
  else
	 {stack.top++;
	  stack.elemen[stack.top]=IB;};
}

void pop()
{  int IP;
  if(stackkosong())
	 cout << "stack underflow\n";
  else
	 {IP=stack.elemen[stack.top];
	  stack.top--;};  }

void cetakstack()
{
  int i=0;
  while (i<=stack.top)
  {  cout << " " << stack.elemen[i] << endl;
      i++;
  }
}
