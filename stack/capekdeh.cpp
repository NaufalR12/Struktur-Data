#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
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

    while (true) {
        bool semuaTumpukanSama = true;

        // Menghitung tinggi masing-masing tumpukan
        vector<int> tinggiTumpukan(jumlahTumpukan);
        for (int i = 0; i < jumlahTumpukan; i++) {
            if (!tumpukanBuku[i].empty()) {
                tinggiTumpukan[i] = tumpukanBuku[i].top();
            }
        }

        // Mencari tumpukan terpendek
        int tumpukanTerpendek = min_element(tinggiTumpukan.begin(), tinggiTumpukan.end()) - tinggiTumpukan.begin();

        int tinggiTumpukanTerpendek = tinggiTumpukan[tumpukanTerpendek];

        for (int i = 0; i < jumlahTumpukan; i++) {
            if (i != tumpukanTerpendek) {
                if (!tumpukanBuku[i].empty() && tinggiTumpukan[i] > tinggiTumpukanTerpendek) {
                    tumpukanBuku[i].pop();
                    semuaTumpukanSama = false;
                }
            }
        }

        if (semuaTumpukanSama) {
            // Semua tumpukan memiliki tinggi yang sama
            cout << "Tumpukan yang telah memiliki tinggi yang sama:" << endl;

            for (int i = 0; i < jumlahTumpukan; i++) {
                cout << "Tumpukan " << namaTumpukan[i] << ": " << endl;
                cout << "Berapa banyak item = " << tumpukanBuku[i].size() << endl;
                int idx = 1;

                while (!tumpukanBuku[i].empty()) {
                    cout << "nilai item ke " << idx << " = " << tumpukanBuku[i].top() << endl;
                    tumpukanBuku[i].pop();
                    idx++;
                }

                cout << "tinggi tumpukan " << namaTumpukan[i] << " = " << tinggiTumpukanTerpendek << endl;
                cout << endl;
            }

            break;
        }
    }

    return 0;
}

