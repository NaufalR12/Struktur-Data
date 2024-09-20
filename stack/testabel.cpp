#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Struktur node tumpukan
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

// Fungsi untuk push node ke stack
void push(StackNode*& stack, int tinggi) {
    StackNode* newNode = buatNode(tinggi);
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

// Fungsi untuk mendapatkan nilai atas stack
int topTinggi(const StackNode* stack) {
    if (stack) {
        return stack->tinggi;
    }
    return -1; // Menandakan tumpukan kosong
}

int main() {
    int jumlahTumpukan;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    vector<StackNode*> tumpukanBuku(jumlahTumpukan, nullptr);
    vector<string> namaTumpukan(jumlahTumpukan);

    // Memasukkan nama tumpukan dan tinggi buku ke dalam vektor
    for (int i = 0; i < jumlahTumpukan; i++) {
        cin.ignore();
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, namaTumpukan[i]);

        int panjangTumpukan;
        cout << "Berapa banyak item dalam tumpukan " << namaTumpukan[i] << ": ";
        cin >> panjangTumpukan;

        for (int j = 0; j < panjangTumpukan; j++) {
            int tinggi;
            cout << "Tinggi item ke " << j + 1 << " = ";
            cin >> tinggi;
            push(tumpukanBuku[i], tinggi);
        }
    }

    // Menghitung total tinggi masing-masing tumpukan
    vector<int> totalTinggi(jumlahTumpukan, 0);

    for (int i = 0; i < jumlahTumpukan; i++) {
        StackNode* current = tumpukanBuku[i];
        while (current) {
            totalTinggi[i] += current->tinggi;
            current = current->next;
        }
    }

    // Temukan tinggi maksimum dari tumpukan
    int tinggiMaksimum = *max_element(totalTinggi.begin(), totalTinggi.end());

    // Cetak tumpukan dengan tabel
    cout << "\nTumpukan dengan tabel" << endl;
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << ":\n";
        StackNode* current = tumpukanBuku[i];
        while (current) {
            int tinggiBaris = current->tinggi;
            cout << "+";
            for (int j = 0; j < tinggiMaksimum; j++) {
                if (j < tinggiBaris) {
                    cout << "-";
                } else {
                    cout << " ";
                }
            }
            cout << "+\n";
            current = current->next;
        }
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
