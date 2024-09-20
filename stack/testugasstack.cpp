#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Definisi record untuk buku
struct Buku {
    int tinggi;
    Buku* next;
};

// Definisi record untuk tumpukan buku
struct Tumpukan {
    Buku* top;
    string nama;
};

// Fungsi untuk membuat tumpukan buku kosong
void buatTumpukan(Tumpukan& s) {
    s.top = nullptr;
    s.nama = "";
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
    cout << "tes tumpukan pantek" << endl;
    cout << "Tumpukan " << s.nama << ":" << endl;

    // Membuat array untuk menyimpan tinggi buku dalam tumpukan
    int* tinggiArray = new int[100]; // Anda dapat menyesuaikan ukurannya

    int jumlahBuku = 0;

    while (current != nullptr) {
        tinggiArray[jumlahBuku] = current->tinggi;
        cout<<current;
        //current->tinggi<<"-"<<current->next;
        current = current->next;
        jumlahBuku++;
    }

    for (int i = jumlahBuku - 1; i >= 0; i--) {
        cout << setw(5) << "|" << setw(5) << tinggiArray[i] << setw(5) << "|" << endl;
    }

    cout << setw(17) << setfill('-') << '-' << setfill(' ') << endl;
    cout << setw(17) << "Tinggi" << endl;
    cout << endl;

    delete[] tinggiArray; // Hapus array setelah digunakan
}




int main() {
    int jumlahTumpukan;
    int tinggiBuku;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    Tumpukan* tumpukanArray = new Tumpukan[jumlahTumpukan];

    for (int i = 0; i < jumlahTumpukan; ++i) {
        cin.ignore();
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, tumpukanArray[i].nama);

        int panjangTumpukan;
        cout << "Masukkan jumlah buku dalam tumpukan " << tumpukanArray[i].nama << ": ";
        cin >> panjangTumpukan;

        for (int j = 0; j < panjangTumpukan; ++j) {
            cout << "Tinggi buku " << j + 1 << ": ";
            cin >> tinggiBuku;
            push(tumpukanArray[i], tinggiBuku);
        }
    }
    cout<<"tumpukan";

    int tinggiMaks = tinggiBuku;


    for (int i = 0; i < jumlahTumpukan; i++) {
        Buku* current = tumpukanArray[i].top;
        while (current != nullptr) {
            if (current->tinggi < tinggiMaks) {
                tinggiMaks = current->tinggi;
                cetakTumpukan(tumpukanArray[i]);
                cout<<"disini"<<current->tinggi;
            }
            current = current->next;
        }
    }


    for (int i = 0; i < jumlahTumpukan; ++i) {
        Buku* current = tumpukanArray[i].top;
        cout << "Buku yang dihapus dari tumpukan " << tumpukanArray[i].nama << ": ";
        while (current != nullptr && current->tinggi >= tinggiMaks) {
            cout << current->tinggi << " ";
            pop(tumpukanArray[i]);
            current = tumpukanArray[i].top;
        }
        cout << endl;
    }

    //Hapus buku yang mungkin tersisa di tumpukan
    // for (int i = 0; i < jumlahTumpukan; ++i) {
    //     Buku* current = tumpukanArray[i].top;
    //     while (current != nullptr) {
    //         pop(tumpukanArray[i]);
    //         current = tumpukanArray[i].top;
    //     }
    // }

    //Mencetak tumpukan buku dalam bentuk tabel
    for (int i = 0; i < jumlahTumpukan; ++i) {
        cetakTumpukan(tumpukanArray[i]);
    }

    // // Hapus alokasi memori
    // delete[] tumpukanArray;

    return 0;
}
