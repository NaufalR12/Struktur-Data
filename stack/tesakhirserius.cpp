#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

// Struktur node tumpukan
struct StackNode {
    int tinggi;
    int lebar;
    StackNode* next;
};

// Fungsi untuk membuat node stack baru
StackNode* buatNode(int tinggi, int lebar) {
    StackNode* newNode = new StackNode;
    newNode->tinggi = tinggi;
    newNode->lebar = lebar;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk push node ke stack
void push(StackNode*& stack, int tinggi, int lebar) {
    StackNode* newNode = buatNode(tinggi, lebar);
    newNode->next = stack;
    stack = newNode;
}

// Fungsi untuk pop node dari stack
void pop(StackNode*& stack) {
    if (stack) {
        StackNode* temp = stack;
        stack = stack->next;
        delete temp;
    }
}

// Fungsi untuk mencetak tumpukan dengan tinggi tabel yang sesuai
void cetakTumpukan(StackNode* tumpukan, int lebarTumpukan) {
    StackNode* current = tumpukan;
    int idx = 1;

    while (current) {
        cout << "+" << setfill('=') << setw(lebarTumpukan) << "+" << endl;
        cout << "|" << setfill(' ') << setw(lebarTumpukan) << "|" << endl;
        cout << "| Nilai item ke " << idx << ": " << current->tinggi << " |" << endl;
        cout << "|" << setfill(' ') << setw(lebarTumpukan) << "|" << endl;
        idx++;
        current = current->next;
    }

    cout << "+" << setfill('=') << setw(lebarTumpukan) << "+" << endl;
}

int main() {
    int jumlahTumpukan;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    vector<StackNode*> tumpukanBuku(jumlahTumpukan, nullptr);
    vector<string> namaTumpukan(jumlahTumpukan);
    vector<int> lebarTumpukan(jumlahTumpukan);

    // Memasukkan nama tumpukan, tinggi, dan lebar buku ke dalam vektor
    for (int i = 0; i < jumlahTumpukan; i++) {
        cin.ignore();
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, namaTumpukan[i]);

        int panjangTumpukan;
        cout << "Berapa banyak item dalam tumpukan " << namaTumpukan[i] << ": ";
        cin >> panjangTumpukan;

        cout << "Lebar tumpukan " << namaTumpukan[i] << ": ";
        cin >> lebarTumpukan[i];

        for (int j = 0; j < panjangTumpukan; j++) {
            int tinggi;
            cout << "Tinggi item ke " << j + 1 << " = ";
            cin >> tinggi;
            push(tumpukanBuku[i], tinggi, lebarTumpukan[i]);
        }
    }

    // Cetak tumpukan dengan tinggi tabel yang sesuai
    cout << "\nTumpukan dengan tabel" << endl;
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << " (Lebar: " << lebarTumpukan[i] << "):" << endl;
        cetakTumpukan(tumpukanBuku[i], lebarTumpukan[i]);
        cout << "Tinggi tumpukan " << namaTumpukan[i] << " = " << lebarTumpukan[i] << endl;
        cout << "Lebar tumpukan " << namaTumpukan[i] << " = " << lebarTumpukan[i] << endl;
        cout << endl;
    }

    // Hapus memori yang dialokasikan
    for (int i = 0; i < jumlahTumpukan; i++) {
        StackNode* current = tumpukanBuku[i];
        while (current) {
            StackNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
