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

    cin.ignore(); // Membersihkan newline karakter

    for (int i = 0; i < jumlahTumpukan; ++i) {
		cin.ignore();
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, namaTumpukan[i]);

        int panjangTumpukan;
        cout << "Berapa banyak item untuk tumpukan " << namaTumpukan[i] << " = ";
        cin >> panjangTumpukan;

        for (int j = 0; j < panjangTumpukan; ++j) {
            int tinggiBuku;
            cout << "Nilai item ke " << j + 1 << " = ";
            cin >> tinggiBuku;
            tumpukanBuku[i].push(tinggiBuku);
        }
    }

    int totalKetebalan = 0;
    for (int i = 0; i < jumlahTumpukan; i++) {
        while (!tumpukanBuku[i].empty()) {
            totalKetebalan += tumpukanBuku[i].top();
            tumpukanBuku[i].pop();
        }
    }

    int ketebalanPerTumpukan = totalKetebalan / jumlahTumpukan;

    for (int i = 0; i < jumlahTumpukan; i++) {
        while (!tumpukanBuku[i].empty()) {
            int tinggi = tumpukanBuku[i].top();
            tumpukanBuku[i].pop();

            while (tinggi < ketebalanPerTumpukan) {
                bool seimbang = false;
                for (int j = 0; j < jumlahTumpukan; j++) {
                    if (j != i && tumpukanBuku[j].size() > ketebalanPerTumpukan) {
                        int selisih = tumpukanBuku[j].size() - ketebalanPerTumpukan;
                        for (int k = 0; k < selisih; k++) {
                            int nilaiPindah = tumpukanBuku[j].top();
                            tumpukanBuku[j].pop();
                            tumpukanBuku[i].push(nilaiPindah);
                            tinggi += nilaiPindah;
                            if (tinggi >= ketebalanPerTumpukan) {
                                seimbang = true;
                                break;
                            }
                        }
                    }
                    if (seimbang) {
                        break;
                    }
                }
            }
            tumpukanBuku[i].push(tinggi);
        }
    }

    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << " :" << endl;
        cout << "berapa banyak item = " << tumpukanBuku[i].size() << endl;
        int itemKe = 1;
        while (!tumpukanBuku[i].empty()) {
            int nilai = tumpukanBuku[i].top();
            cout << "nilai item ke " << itemKe << " = " << nilai << endl;
            tumpukanBuku[i].pop();
            itemKe++;
        }
        cout << endl;
    }

    return 0;
}
