#include <iostream>
using namespace std;

struct typequeue {
    int info; // Mengganti typeinfo ke int untuk menyimpan angka
    typequeue* next;
};

typequeue* qdepan = nullptr;
typequeue* qbelakang = nullptr;

void buatqueue() {
    // Tidak perlu alokasi memori di sini
    qdepan = nullptr;
    qbelakang = qdepan;
}

bool queuekosong() {
    return (qdepan == nullptr);
}

void enqueue(int IB) {
    typequeue* NB = new typequeue; // Menggunakan 'new' untuk alokasi memori
    NB->info = IB;
    NB->next = nullptr;
    if (qdepan == nullptr) {
        qdepan = NB;
    } else {
        qbelakang->next = NB;
    }
    qbelakang = NB;
}

void cetak() {
    typequeue* bantu = qdepan;
    while (bantu != nullptr) {
        cout << bantu->info << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

void dequeue(){
    typequeue* dequeue;
      if (queuekosong())
      {
         cout << "Queue masih kosong !";
      }
      else
      { dequeue=qdepan;
         qdepan=dequeue->next;
         free(dequeue); }

}

int main() {
    buatqueue();
    int a;
    int angka; // Mengganti tipe data 'angka' menjadi int
    int menu;
    char ulang = 'y';

    while (toupper(ulang) == 'Y') {
        cout << "1. input" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. cetak" << endl;
        cout << "pilih menu : ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Jumlah data yang ingin diinput : ";
                cin >> a;
                for (int i = 0; i < a; i++) {
                    cout << "Masukkan Angka : ";
                    cin >> angka;
                    enqueue(angka);
                }
                cetak();
                break;
            case 2:
                dequeue();
                cetak();
                break;
            case 3:
                cetak();
                break;
            default:
                cout << "salah";
        }

        cout << "\n\nKembali ke menu awal? y/t: ";
        cin >> ulang;
    }


    return 0;
}