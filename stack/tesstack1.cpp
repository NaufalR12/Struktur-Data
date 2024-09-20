/*Stack menggunakan array*/
#include <iostream>
#define max 50
#define True 1
#define False 0
using std::cout;
using std::endl;
int top=0, stack[max];
void buatstack();
int stackkosong();
int stackpenuh();
void push(int IB);
void pop();
void cetakstack();
void cetakstack()
{ int i=1;
  while (i<=top)
  { cout << stack[i] << endl;
	 i++; }
}
int main()
{
  buatstack();
  push(10);
  push(76);
  push(12);
  push(21);
  cetakstack();
  cout << "\n\n";
  pop();
  pop();
  pop();
  cetakstack();
}
void buatstack()
{ stack[top]=0; }

int stackkosong()
{ if(top==0)
	 return(True);
  else
	 return(False); }

int stackpenuh()
{ if(top==max)
	 return(True);
  else
	 return(False); }

void push(int IB)
{ if (stackpenuh())
	 cout << "stack overflow\n";
  else
	 {top++;
	  stack[top]=IB;
	  stack[0]=top; } }


void pop()
{ int IP;
  if (stackkosong())
	 cout << "stack underflow\n";
  else
	 {IP=stack[top];
	  top--;
	  stack[0]=top;
    //cara lain 
    //stack[top]=0;
    //top--;
    //stack[0]=top;
    
     } }
