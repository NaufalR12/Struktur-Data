#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

// Definisi tipe data untuk node stack
struct StackNode {
    int tinggi;
    StackNode* next;
};

// Fungsi untuk membuat node stack baru
StackNode* buatNode(int tinggi) {
    StackNode* newNode = new StackNode;
    newNode->tinggi = tinggi;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan node ke stack (push)
void push(StackNode*& top, int tinggi) {
    StackNode* newNode = buatNode(tinggi);
    newNode->next = top;
    top = newNode;
}

// Fungsi untuk menghapus node dari stack (pop)
void pop(StackNode*& top) {
    if (top != nullptr) {
        StackNode* nodeToDelete = top;
        top = top->next;
        delete nodeToDelete;
    }
}

// Fungsi untuk mencetak stack
void cetakStack(StackNode* top, string namaTumpukan) {
    cout << "Tumpukan " << namaTumpukan << ":" << endl;
    int jumlahBuku = 0;
    int totalTinggi = 0;

    while (top != nullptr) {
        cout << "nilai item ke " << jumlahBuku + 1 << " = " << top->tinggi << endl;
        totalTinggi += top->tinggi;
        top = top->next;
        jumlahBuku++;
    }

    cout << "Tinggi tumpukan " << namaTumpukan << " = " << totalTinggi << endl;
    cout << "Berapa banyak item = " << jumlahBuku << endl;
    cout << endl;
}

int main() {
    int jumlahTumpukan;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    StackNode** tumpukanArray = new StackNode*[jumlahTumpukan];
    string* namaTumpukan = new string[jumlahTumpukan];

    for (int i = 0; i < jumlahTumpukan; i++) {
        cin.ignore();
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, namaTumpukan[i]);

        tumpukanArray[i] = nullptr;  // Inisialisasi tumpukan menjadi kosong

        int panjangTumpukan;
        cout << "Berapa banyak item dalam tumpukan " << namaTumpukan[i] << ": ";
        cin >> panjangTumpukan;

        for (int j = 0; j < panjangTumpukan; j++) {
            int tinggi;
            cout << "Tinggi item ke " << j + 1 << " = ";
            cin >> tinggi;
            push(tumpukanArray[i], tinggi);
        }
    }

    // Mencetak tumpukan buku
    for (int i = 0; i < jumlahTumpukan; i++) {
        cetakStack(tumpukanArray[i], namaTumpukan[i]);
    }

    // Hapus alokasi memori
    for (int i = 0; i < jumlahTumpukan; i++) {
        while (tumpukanArray[i] != nullptr) {
            pop(tumpukanArray[i]);
        }
    }
    delete[] tumpukanArray;
    delete[] namaTumpukan;

    return 0;
}
