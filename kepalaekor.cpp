#include <iostream>
using std::cout;

typedef int typeinfo;

struct typenode {
    typeinfo info;
    typenode* next;
};

typenode *kepala, *ekor;

void buatlist();
void sisipnode(typeinfo IB);
void hapusnode(typeinfo IH);

void bacamaju();
void bacamundur();

int listkosong();

int main() {
    buatlist();
    sisipnode(50);
    sisipnode(20);
    sisipnode(5);
    sisipnode(100);
    sisipnode(70);
    sisipnode(25);
    sisipnode(40);

    cout << "List dari depan:\n";
    bacamaju();

    cout << "\n\nHapus node 20\n";
    hapusnode(20);

    cout << "\nList dari belakang:\n";
    bacamundur();
}

void buatlist() {
    kepala = new typenode;
    ekor = new typenode;
    kepala->info = -9999;
    kepala->next = ekor;
    ekor->info = 9999;
    ekor->next = nullptr;
}

int listkosong() {
    return (kepala->next == ekor);
}

void sisipnode(typeinfo IB) {
    typeptr NB, bantu;
    NB = new typenode;
    NB->info = IB;
    bantu = kepala;
    
    while (IB > bantu->next->info) {
        bantu = bantu->next;
    }
    
    NB->next = bantu->next;
    bantu->next = NB;
}

void hapusnode(typeinfo IH) {
    typeptr hapus, bantu;
    
    if (listkosong()) {
        cout << "List masih kosong";
    } else {
        bantu = kepala;
        
        while (bantu->next != ekor && IH != bantu->next->info) {
            bantu = bantu->next;
        }
        
        if (IH == bantu->next->info) {
            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        } else {
            cout << "Node tidak ditemukan!\n";
        }
    }
}

void bacamaju() {
    typeptr bantu;
    bantu = kepala->next;
    
    while (bantu != ekor) {
        cout << " " << bantu->info;
        bantu = bantu->next;
    }
}

void bacamundur() {
    typeptr depan, bantu;
    depan = kepala;
    kepala = ekor;
    
    do {
        bantu = depan;
        
        while (bantu->next != ekor) {
            bantu = bantu->next;
        }
        
        ekor->next = bantu;
        ekor = bantu;
    } while (ekor != depan);
    
    ekor->next = nullptr;
    bantu = kepala->next;
    
    while (bantu != ekor) {
        cout << " " << bantu->info;
        bantu = bantu->next;
    }
}
