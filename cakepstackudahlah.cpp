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

    for (int i = 0; i < jumlahTumpukan; i++) {
        cin.ignore();
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, namaTumpukan[i]);

        int panjangTumpukan;
        cout << "Berapa banyak item dalam tumpukan " << namaTumpukan[i] << ": ";
        cin >> panjangTumpukan;

        for (int j = 0; j < panjangTumpukan; j++) {
            int nilai;
            cout << "nilai item ke " << j + 1 << " = ";
            cin >> nilai;
            tumpukanBuku[i].push(nilai);
        }
    }

    // Menghitung total ketebalan tumpukan
    vector<int> totalKetebalan(jumlahTumpukan);
    for (int i = 0; i < jumlahTumpukan; i++) {
        int total = 0;
        stack<int> tumpukanSementara;

        while (!tumpukanBuku[i].empty()) {
            total += tumpukanBuku[i].top();
            tumpukanSementara.push(tumpukanBuku[i].top());
            tumpukanBuku[i].pop();
        }

        totalKetebalan[i] = total;

        // Mengembalikan nilai-nilai ke tumpukan aslinya
        while (!tumpukanSementara.empty()) {
            tumpukanBuku[i].push(tumpukanSementara.top());
            tumpukanSementara.pop();
        }
    }

    // Menghitung rata-rata total ketebalan
    int rataRata = 0;
    for (int i = 0; i < jumlahTumpukan; i++) {
        rataRata += totalKetebalan[i];
    }
    rataRata /= jumlahTumpukan;

    // Menghapus nilai-nilai yang lebih besar dari rata-rata
    for (int i = 0; i < jumlahTumpukan; i++) {
        stack<int> tumpukanSementara;

        while (!tumpukanBuku[i].empty()) {
            if (tumpukanBuku[i].top() <= rataRata) {
                tumpukanSementara.push(tumpukanBuku[i].top());
            }
            tumpukanBuku[i].pop();
        }

        // Mengembalikan nilai-nilai ke tumpukan aslinya
        while (!tumpukanSementara.empty()) {
            tumpukanBuku[i].push(tumpukanSementara.top());
            tumpukanSementara.pop();
        }
    }

    // Cetak tumpukan setelah menghapus nilai-nilai yang lebih besar dari rata-rata
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << "Tumpukan " << namaTumpukan[i] << ":" << endl;
        cout << "Berapa banyak item = " << tumpukanBuku[i].size() << endl;

        stack<int> tumpukanSementara;

        while (!tumpukanBuku[i].empty()) {
            tumpukanSementara.push(tumpukanBuku[i].top());
            tumpukanBuku[i].pop();
        }

        int idx = 1;
        while (!tumpukanSementara.empty()) {
            cout << "nilai item ke " << idx << " = " << tumpukanSementara.top() << endl;
            tumpukanBuku[i].push(tumpukanSementara.top());
            tumpukanSementara.pop();
            idx++;
        }
        cout << endl;
    }

    return 0;
}
