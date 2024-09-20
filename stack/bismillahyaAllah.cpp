#include <iostream>
#include <string>
#include <vector>
#include <stack>
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

    // Mencari tumpukan terpendek
    int tumpukanTerpendek = 0;
    for (int i = 1; i < jumlahTumpukan; i++) {
        if (tumpukanBuku[i].size() < tumpukanBuku[tumpukanTerpendek].size()) {
            tumpukanTerpendek = i;
        }
    }

    while (true) {
        bool semuaTumpukanSama = true;

        // Mengambil tinggi tumpukan terpendek
        int tinggiTumpukanTerpendek = 0;
        if (!tumpukanBuku[tumpukanTerpendek].empty()) {
            tinggiTumpukanTerpendek = tumpukanBuku[tumpukanTerpendek].top();
        }

        for (int i = 0; i < jumlahTumpukan; i++) {
            if (i != tumpukanTerpendek) {
                if (!tumpukanBuku[i].empty() && tumpukanBuku[i].top() > tinggiTumpukanTerpendek) {
                    tumpukanBuku[i].pop();
                } else if (!tumpukanBuku[i].empty() && tumpukanBuku[i].top() < tinggiTumpukanTerpendek) {
                    int nilai = tumpukanBuku[i].top();
                    tumpukanBuku[i].pop();
                    tumpukanBuku[tumpukanTerpendek].push(nilai);
                    semuaTumpukanSama = false;
                } else if (tumpukanBuku[i].empty()) {
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
