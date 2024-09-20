#include <iostream>
#include <string>
#include <vector>
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

    // Memasukkan nama tumpukan dan tinggi serta lebar buku ke dalam vektor
    for (int i = 0; i < jumlahTumpukan; i++) {
        cin.ignore();
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, namaTumpukan[i]);

        int panjangTumpukan;
        cout << "Berapa banyak item dalam tumpukan " << namaTumpukan[i] << ": ";
        cin >> panjangTumpukan;

        for (int j = 0; j < panjangTumpukan; j++) {
            int tinggi, lebar;
            cout << "Tinggi item ke " << j + 1 << " = ";
            cin >> tinggi;
            cout << "Lebar item ke " << j + 1 << " = ";
            cin >> lebar;
            push(tumpukanBuku[i], tinggi, lebar);
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

    bool tumpukanPendek = false;

    while (!tumpukanPendek) {
        int tumpukanTerpendek = min_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();
        int tumpukanTerpanjang = max_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();

        if (totalTinggi[tumpukanTerpendek] == totalTinggi[tumpukanTerpanjang]) {
            tumpukanPendek = true;
        } else {
            int nilaiAtas = topTinggi(tumpukanBuku[tumpukanTerpanjang]);
            if (nilaiAtas != -1) {
                pop(tumpukanBuku[tumpukanTerpanjang]);
                totalTinggi[tumpukanTerpanjang] -= nilaiAtas;
            }
        }
    }

    // Menyamakan lebar tumpukan berdasarkan tumpukan terpendek
    int lebarTumpukanTerpendek = tumpukanBuku[min_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin()]->lebar;

    for (int i = 0; i < jumlahTumpukan; i++) {
        StackNode* current = tumpukanBuku[i];
        while (current) {
            current->lebar = lebarTumpukanTerpendek;
            current = current->next;
        }
    }

    cout << "Tumpukan setelah di filter dengan ketebalan yang sama" << endl;
    // Cetak tumpukan yang memiliki tinggi dan lebar yang sama
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << ":" << endl;
        cout << "Berapa banyak item = ";
        int count = 0;
        StackNode* current = tumpukanBuku[i];
        while (current) {
            count++;
            current = current->next;
        }
        cout << count << endl;

        int idx = 1;
        current = tumpukanBuku[i];
        while (current) {
            cout << "nilai item ke " << idx << " (Tinggi: " << current->tinggi << ", Lebar: " << current->lebar << ")" << endl;
            idx++;
            current = current->next;
        }
        cout << "Tinggi tumpukan " << namaTumpukan[i] << " = " << totalTinggi[i] << endl;
        cout << "Lebar tumpukan " << namaTumpukan[i] << " = " << lebarTumpukanTerpendek << endl;
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
