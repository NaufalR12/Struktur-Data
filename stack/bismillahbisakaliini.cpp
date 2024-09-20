#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <climits> // Sertakan header ini untuk INT_MAX
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
            cout << "Tinggi item ke " << j + 1 << " = ";
            cin >> tinggi;
            tumpukanBuku[i].push(tinggi);
        }
    }

    // Menyamakan tinggi tumpukan
    int tinggiMin = INT_MAX; // Menyimpan tinggi minimum dari tumpukan
    int idxTumpukanMin = -1; // Menyimpan indeks tumpukan dengan tinggi minimum

    for (int i = 0; i < jumlahTumpukan; i++) {
        if (!tumpukanBuku[i].empty() && tumpukanBuku[i].top() < tinggiMin) {
            tinggiMin = tumpukanBuku[i].top();
            idxTumpukanMin = i;
        }
    }

    while (idxTumpukanMin != -1) {
        for (int i = 0; i < jumlahTumpukan; i++) {
            if (i != idxTumpukanMin) {
                if (!tumpukanBuku[i].empty() && tumpukanBuku[i].top() > tinggiMin) {
                    tumpukanBuku[i].pop();
                }
            }
        }

        // Cetak tumpukan yang sudah disamakan
        cout << "Tumpukan " << namaTumpukan[idxTumpukanMin] << ":" << endl;
        cout << "Berapa banyak item = " << tumpukanBuku[idxTumpukanMin].size() << endl;
        int idx = 1;
        while (!tumpukanBuku[idxTumpukanMin].empty()) {
            cout << "nilai item ke " << idx << " = " << tumpukanBuku[idxTumpukanMin].top() << endl;
            tumpukanBuku[idxTumpukanMin].pop();
            idx++;
        }
        cout << "tinggi tumpukan " << namaTumpukan[idxTumpukanMin] << " = " << tinggiMin << endl;
        cout << endl;

        // Cari tumpukan dengan tinggi minimum berikutnya
        tinggiMin = INT_MAX;
        idxTumpukanMin = -1;

        for (int i = 0; i < jumlahTumpukan; i++) {
            if (!tumpukanBuku[i].empty() && tumpukanBuku[i].top() < tinggiMin) {
                tinggiMin = tumpukanBuku[i].top();
                idxTumpukanMin = i;
            }
        }
    }

    return 0;
}
