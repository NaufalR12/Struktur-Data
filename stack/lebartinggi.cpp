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
void push(StackNode*& stack, int value) {
    StackNode* newNode = buatNode(value);
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
int top(const StackNode* stack) {
    if (stack) {
        return stack->tinggi;
    }
    return -1; // Menandakan tumpukan kosong
}

// Fungsi untuk mencetak tumpukan dalam format yang diinginkan
void printStack(StackNode* stack, int width) {
    vector<string> lines;
    StackNode* current = stack;
    while (current) {
        string line = "|";
        line += string(width - 2, ' ');
        line += "|";
        lines.push_back(line);

        line = "|";
        string value = to_string(current->tinggi);
        int padding = (width - 2 - value.length()) / 2;
        line += string(padding, ' ');
        line += value;
        line += string(width - 2 - padding - value.length(), ' ');
        line += "|";
        lines.push_back(line);

        line = "|";
        line += string(width - 2, ' ');
        line += "|";
        lines.push_back(line);

        current = current->next;
    }

    for (int i = lines.size() - 1; i >= 0; i--) {
        cout << lines[i] << endl;
    }
}

int main() {
    int jumlahTumpukan;
    int lebarTumpukan; // Menyimpan lebar tumpukan
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    // Input lebar tumpukan
    cout << "Masukkan lebar tumpukan: ";
    cin >> lebarTumpukan;

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

    bool tumpukanPendek = false;

    while (!tumpukanPendek) {
        int tumpukanTerpendek = min_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();
        int tumpukanTerpanjang = max_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();

        if (totalTinggi[tumpukanTerpendek] == totalTinggi[tumpukanTerpanjang]) {
            tumpukanPendek = true;
        } else {
            int nilaiAtas = top(tumpukanBuku[tumpukanTerpanjang]);
            if (nilaiAtas != -1) {
                pop(tumpukanBuku[tumpukanTerpanjang]);
                totalTinggi[tumpukanTerpanjang] -= nilaiAtas;
            }
        }
    }

    // Cetak tumpukan dalam format yang diinginkan
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << ":" << endl;
        printStack(tumpukanBuku[i], lebarTumpukan); // Menggunakan lebar tumpukan yang disamakan
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
