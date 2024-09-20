#include <iostream>
#include <malloc.h>

using std::cout;

typedef int typeinfo;
typedef struct typestack *typeptr;

typedef struct typestack {
    typeinfo info;
    typeptr next;
};

typeptr stack, stackawal;

void buatstack();
int stackkosong();
void push(typeinfo IB);
void pop();
void cetakstack();

int main() {
    buatstack();
    push(25);
    push(15);
    push(20);
    push(100);
    cetakstack();
    cout << " \n\n";
    pop();
    cetakstack();
}

void buatstack() {
    stackawal = NULL; // Inisialisasi stackawal dengan NULL
    stack = NULL; // Inisialisasi stack dengan NULL
}

int stackkosong() {
    if (stackawal == NULL)
        return 1; // Ganti True dengan 1
    else
        return 0; // Ganti False dengan 0
}

void push(typeinfo IB) {
    typeptr NS;
    NS = (typestack *)malloc(sizeof(typestack));
    NS->info = IB;
    NS->next = stack; // Perbaiki penambahan elemen ke stack
    stack = NS;
}

void pop() {
    typeptr hapus;
    if (stackkosong()) {
        cout << "Stack kosong !" << std::endl;
    } else {
        hapus = stack;
        stack = stack->next;
        free(hapus);
    }
}

void cetakstack() {
    typeptr bantu;
    bantu = stackawal;
    while (bantu != NULL) {
        cout << " " << bantu->info << std::endl;
        bantu = bantu->next;
    }
}
