#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;

typedef int typeinfo;

typedef struct typestack {
    typeinfo info;
    struct typestack* next;
};

typedef typestack* typeptr;

typeptr stack, stackawal;

void buatstack();
int stackkosong();
void push(typeinfo IB);
void pop();
void cetakstack(typeptr bantu); // Menggunakan rekursi

int main()
{
    buatstack();
    int angka, a;
    cout << "Jumlah data yang ingin diinput : ";
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cout << "Masukan Angka : ";
        cin >> angka;
        push(angka);
    }
    cetakstack(stackawal); // Memanggil cetakstack dengan elemen awal
    cout << " \n\n";
    pop();
    cetakstack(stackawal); // Memanggil cetakstack dengan elemen awal
}

void buatstack()
{
    stackawal = NULL;
}

int stackkosong()
{
    return (stackawal == NULL) ? 1 : 0;
}

void push(typeinfo IB)
{
    typeptr NS = (typestack*)malloc(sizeof(typestack));
    NS->info = IB;
    NS->next = stackawal;
    stackawal = NS;
}

void pop()
{
    if (stackkosong())
    {
        cout << "Stack kosong !\n";
    }
    else
    {
        typeptr hapus = stackawal;
        stackawal = stackawal->next;
        free(hapus);
    }
}

void cetakstack(typeptr bantu)
{
    if (bantu == NULL)
        return;
    cetakstack(bantu->next); 
    cout << " " << bantu->info << '\n';
}



