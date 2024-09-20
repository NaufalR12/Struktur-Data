#include <iostream>
using std::cout;

typedef int typeinfo;

struct typenode {
    typeinfo info;
    typenode* next;
};

typenode* kepala;
typenode* ekor;

void buatlistbaru();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);

void bacamaju();
void bacamundur();
int listkosong();

int main() {
    cout << "List Mula-mula :\n";
    buatlistbaru();
    sisipnode(50);
    sisipnode(20);
    sisipnode(5);
    sisipnode(100);
    sisipnode(70);
    sisipnode(25);
    bacamaju();

    cout << "\n\nHapus node 50\n";
    cout << "\nList terakhir :\n";
    hapusnode(50);
    bacamaju();

    return 0;
}

void buatlistbaru() {
    kepala = nullptr;
    ekor = nullptr;
}

int listkosong() {
    return (kepala == nullptr);
}

void sisipnode(typeinfo IB) {
    typenode* NB = new typenode;
    NB->info = IB;
    NB->next = nullptr;

    if (listkosong()) {
        kepala = NB;
        ekor = NB;
    } else if (IB <= kepala->info) {
        NB->next = kepala;
        kepala = NB;
    } else {
        typenode* bantu = kepala;
        while (bantu->next != nullptr && IB > bantu->next->info)
            bantu = bantu->next;
        NB->next = bantu->next;
        bantu->next = NB;
        if (IB > ekor->info)
            ekor = NB;
    }
}

void hapusnode(typeinfo IH) {
    typenode* hapus;
    typenode* bantu;

    if (listkosong()) {
        cout << "List masih kosong\n";
    } else if (kepala->info == IH) {
        hapus = kepala;
        kepala = hapus->next;
        delete hapus;
    } else {
        bantu = kepala;
        while (bantu->next->next != nullptr && IH != bantu->next->info)
            bantu = bantu->next;
        if (IH == bantu->next->info) {
            hapus = bantu->next;
            if (hapus == ekor) {
                ekor = bantu;
                ekor->next = nullptr;
            } else {
                bantu->next = hapus->next;
            }
            delete hapus;
        } else {
            cout << "Node tidak ditemukan!\n";
        }
    }
}

void bacamaju() {
    typenode* bantu = kepala;
    while (bantu != nullptr) {
        cout << " " << bantu->info;
        cout << " ";
        bantu = bantu->next;
    }
}

void bacamundur() {
    typenode* depan;
    typenode* bantu;

    depan = kepala;
    kepala = ekor;

    do {
        bantu = depan;
        while (bantu->next != ekor)
            bantu = bantu->next;

        ekor->next = bantu;
        ekor = bantu;
    } while (ekor != depan);

    ekor->next = nullptr;
    bantu = kepala;
    
    while (bantu != nullptr) {
        cout << " " << bantu->info;
        cout << " ";
        bantu = bantu->next;
    }
}
