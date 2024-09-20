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

    // Menyamakan lebar tumpukan berdasarkan tumpukan terbesar
    int lebarTumpukanTerbesar = *max_element(lebarTumpukan.begin(), lebarTumpukan.end());

    for (int i = 0; i < jumlahTumpukan; i++) {
        lebarTumpukan[i] = lebarTumpukanTerbesar;
    }

    cout << "\nTumpukan dengan tabel" << endl;
    // Cetak tumpukan yang memiliki tinggi dan lebar yang sama
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << " (Lebar: " << lebarTumpukan[i] << "):" << endl;
        // cout<<"+"<<setfill('=')<<setw(lebarTumpukan[i])<<"="<<"+\n";
        // int l=lebarTumpukan[i];
        // cout << "|L="  << lebarTumpukan[i] << setfill(' ') << setw(l-2) << " |" << endl;
        cout<<"+"<< setfill('=') << setw(lebarTumpukan[i])<<"="<<"+\n";
        int count = 0;
        StackNode* current = tumpukanBuku[i];
        while (current) {
            count++;
            current = current->next;
        }
        //cout << count << endl;



        int idx = 1;
        current = tumpukanBuku[i];
        std::string Atinggi =std::to_string(current->tinggi);
        int t = Atinggi.length();

        while (current) {
            cout << "|" <<  current->tinggi<<" "<<setfill(' ')<<setw(lebarTumpukan[i]-t)<<"|" << endl;
            idx++;
            current = current->next;
        }
        cout<<"+"<<setfill('=')<<setw(lebarTumpukan[i])<<"="<<"+\n";
        cout << "Tinggi tumpukan " << namaTumpukan[i] << " = " << totalTinggi[i] << endl;
        cout << "Lebar tumpukan " << namaTumpukan[i] << " = " << lebarTumpukan[i] << endl;
        cout << endl;
    }
    cout << "\nTumpukan setelah di filter dengan ketebalan yang sama" << endl;
    // Cetak tumpukan yang memiliki tinggi dan lebar yang sama
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << " (Lebar: " << lebarTumpukan[i] << "):" << endl;
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
            cout << "nilai item ke " << idx << " (Tinggi: " << current->tinggi << ", Lebar: " << lebarTumpukan[i] << ")" << endl;
            idx++;
            current = current->next;
        }
        cout << "Tinggi tumpukan " << namaTumpukan[i] << " = " << totalTinggi[i] << endl;
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