#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int jumlahTumpukan;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    vector<vector<int>> tumpukanBuku(jumlahTumpukan);
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
            tumpukanBuku[i].push_back(tinggi);
        }
    }

    // Menghitung total tinggi masing-masing tumpukan
    vector<int> totalTinggi(jumlahTumpukan, 0);

    for (int i = 0; i < jumlahTumpukan; i++) {
        for (int tinggi : tumpukanBuku[i]) {
            totalTinggi[i] += tinggi;
        }
    }

    bool tumpukanPendek = false;

    while (!tumpukanPendek) {
        int tumpukanTerpendek = min_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();
        int tumpukanTerpanjang = max_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();

        if (totalTinggi[tumpukanTerpendek] == totalTinggi[tumpukanTerpanjang]) {
            tumpukanPendek = true;
        } else {
            int nilaiAtas = tumpukanBuku[tumpukanTerpanjang].back();
            tumpukanBuku[tumpukanTerpanjang].pop_back();
            totalTinggi[tumpukanTerpanjang] -= nilaiAtas;
        }
    }

    cout << "Tumpukan setelah di filter dengan ketebalan yang sama" << endl;
    // Cetak tumpukan yang memiliki tinggi yang sama
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << ":" << endl;
        cout << "Berapa banyak item = " << tumpukanBuku[i].size() << endl;
        int idx = 1;
        for (int tinggi : tumpukanBuku[i]) {
            cout << "nilai item ke " << idx << " = " << tinggi << endl;
            idx++;
        }
        cout << "Tinggi tumpukan " << namaTumpukan[i] << " = " << totalTinggi[i] << endl;
        cout << endl;
    }

    return 0;
}
