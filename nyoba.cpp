
#include <iostream>
using namespace std;

// Definisi record untuk buku
struct Buku {
    int tinggi;
    Buku* next;
};

// Definisi record untuk tumpukan buku
struct Tumpukan {
    Buku* top;
};

// Fungsi untuk membuat tumpukan buku kosong
void buatTumpukan(Tumpukan& s) {
    s.top = nullptr;
}

// Fungsi untuk menambahkan buku ke tumpukan
void push(Tumpukan& s, int tinggi) {
    Buku* bukuBaru = new Buku;
    bukuBaru->tinggi = tinggi;
    bukuBaru->next = s.top;
    s.top = bukuBaru;
}

// Fungsi untuk menghapus buku dari tumpukan
void pop(Tumpukan& s) {
    if (s.top != nullptr) {
        Buku* bukuDihapus = s.top;
        s.top = s.top->next;
        delete bukuDihapus;
    }
}

// Fungsi untuk mencetak tumpukan buku
void cetakTumpukan(Tumpukan& s) {
    Buku* current = s.top;
    while (current != nullptr) {
        cout << current->tinggi << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int jumlahTumpukan;
    int panjangTumpukan;
    int tinggiBuku;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    Tumpukan* tumpukanArray = new Tumpukan[jumlahTumpukan];

    for (int i = 0; i < jumlahTumpukan; ++i) {
        
        cout << "Masukkan jumlah buku dalam tumpukan " << i + 1 << ": ";
        cin >> panjangTumpukan;

        for (int j = 0; j < panjangTumpukan; ++j) {
            
            cout << "Tinggi buku " << j + 1 << ": ";
            cin >> tinggiBuku;
            push(tumpukanArray[i], tinggiBuku);
        }
    }

    int tinggiMaks = tinggiBuku;

    for (int i = 0; i < jumlahTumpukan; ++i) {
        Buku* current = tumpukanArray[i].top;
        while (current != nullptr) {
            if (current->tinggi < tinggiMaks) {
                tinggiMaks = current->tinggi;
            }
            current = current->next;
        }
    }

    for (int i = 0; i < jumlahTumpukan; ++i) {
        cout << "Tumpukan " << char('A' + i) << ": ";
        Buku* current = tumpukanArray[i].top;

        while (current != nullptr && current->tinggi >= tinggiMaks) {
            cout << current->tinggi << " ";
            pop(tumpukanArray[i]);
            current = tumpukanArray[i].top;
        }

        cout << endl;
    }

    // Hapus buku yang mungkin tersisa di tumpukan
    for (int i = 0; i < jumlahTumpukan; ++i) {
        Buku* current = tumpukanArray[i].top;
        while (current != nullptr) {
            pop(tumpukanArray[i]);
            current = tumpukanArray[i].top;
        }
    }

    // Hapus alokasi memori
    delete[] tumpukanArray;

    return 0;
}