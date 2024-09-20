#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int jumlahTumpukan;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    vector<stack<int>> tumpukanBuku(jumlahTumpukan);
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
            cout << "tinggi item ke " << j + 1 << " = ";
            cin >> tinggi;
            tumpukanBuku[i].push(tinggi);
        }
    }

    // Menghitung total tinggi masing-masing tumpukan
    vector<int> totalTinggi(jumlahTumpukan, 0);

    for (int i = 0; i < jumlahTumpukan; i++) {
        stack<int> tempStack = tumpukanBuku[i];
        while (!tempStack.empty()) {
            totalTinggi[i] += tempStack.top();
            tempStack.pop();
        }
    }

    // Menyamakan tinggi tumpukan
    int rataRataTinggi = 0;
    for (int i = 0; i < jumlahTumpukan; i++) {
        rataRataTinggi += totalTinggi[i];
    }
    rataRataTinggi /= jumlahTumpukan;

    for (int i = 0; i < jumlahTumpukan; i++) {
        while (totalTinggi[i] > rataRataTinggi) {
            if (!tumpukanBuku[i].empty()) {
                totalTinggi[i] -= tumpukanBuku[i].top();
                tumpukanBuku[i].pop();
            }
            else {
                break;
            }
        }
    }
    cout << "tes   " << endl;

    // Cetak tumpukan yang memiliki tinggi yang sama
    for (int i = 0; i < jumlahTumpukan; i++) {
        if (totalTinggi[i] == rataRataTinggi) {
            cout << "Tumpukan " << namaTumpukan[i] << ":" << endl;
            cout << "Berapa banyak item = " << tumpukanBuku[i].size() << endl;
            int idx = 1;
            while (!tumpukanBuku[i].empty()) {
                cout << "nilai item ke " << idx << " = " << tumpukanBuku[i].top() << endl;
                tumpukanBuku[i].pop();
                idx++;
            }
            cout << "tinggi tumpukan " << namaTumpukan[i] << " = " << rataRataTinggi << endl;
            cout << endl;
        }
    }

    return 0;
}
