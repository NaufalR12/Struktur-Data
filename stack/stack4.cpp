#include <iostream>
#include <cctype>
#include <cstdlib>

#define True 1
#define False 0

using namespace std;

typedef int typeinfo;
typedef struct typestack *typeptr;

typedef struct typestack {
    typeinfo info;
    typeptr next;
};

typeptr stack;
typeptr stackawal;

void buatstack();
int stackkosong();
void push(typeinfo IB);
void pop();
void cetakstack();

int main() {
    buatstack();
    int menu;
    char ulang = 'y';

    while (toupper(ulang) == 'Y') {
        cout << "1. input" << endl;
        cout << "2. pop" << endl;
        cout << "3. cetak" << endl;
        cout << "pilih menu : ";
        cin >> menu;

        switch (menu) {
            case 1:
                int angka, a;
                cout << "Jumlah data yang ingin diinput : ";
                cin >> a;

                for (int i = 0; i < a; i++) {
                    cout << "Masukan Angka : ";
                    cin >> angka;
                    push(angka);
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                cetakstack();
                break;
            default:
                cout << "salah";
        }

        cout << "\n\nKembali ke menu awal? y/t: ";
        cin >> ulang;
    }

    cout << " \n\n";
}

void buatstack() {
    stack = NULL;
    stackawal = NULL;
}

int stackkosong() {
    if (stackawal == NULL)
        return True;
    else
        return False;
}

void push(typeinfo IB) {
    typeptr NS;
    NS = new typestack;
    NS->info = IB;
    NS->next = stackawal;
    stackawal = NS;
}

void pop() {
    if (stackkosong()) {
        cout << "Stack kosong!" << endl;
    } else {
        typeptr hapus;
        hapus = stackawal;
        stackawal = stackawal->next;
        delete hapus;
    }
}

void cetakstack() {
    typeptr bantu;
    bantu = stackawal;

    if (stackkosong()) {
        cout << "Stack kosong!" << endl;
        return;
    }

    while (bantu != NULL) {
        cout << " " << bantu->info << '\n';
        bantu = bantu->next;
    }
}
