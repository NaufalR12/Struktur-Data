#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
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

    // Menghitung total ketebalan masing-masing tumpukan
    vector<int> totalKetebalan(jumlahTumpukan, 0);

    for (int i = 0; i < jumlahTumpukan; i++) {
        stack<int> tempStack = tumpukanBuku[i];
        while (!tempStack.empty()) {
            totalKetebalan[i] += tempStack.top();
            tempStack.pop();
        }
    }

    // Menyamakan ketebalan tumpukan
    int rataRataKetebalan = 0;
    for (int i = 0; i < jumlahTumpukan; i++) {
        rataRataKetebalan += totalKetebalan[i];
    }
    rataRataKetebalan /= jumlahTumpukan;

    for (int i = 0; i < jumlahTumpukan; i++) {
        while (totalKetebalan[i] > rataRataKetebalan) {
            if (!tumpukanBuku[i].empty()) {
                totalKetebalan[i] -= tumpukanBuku[i].top();
                tumpukanBuku[i].pop();
            }
            else {
                break;
            }
        }
    }

    // Cetak tumpukan yang memiliki ketebalan yang sama
    for (int i = 0; i < jumlahTumpukan; i++) {
        if (totalKetebalan[i] == rataRataKetebalan) {
            cout << "Tumpukan " << namaTumpukan[i] << ":" << endl;
            cout << "Berapa banyak item = " << tumpukanBuku[i].size() << endl;
            int idx = 1;
            vector<int> items;
            while (!tumpukanBuku[i].empty()) {
                items.push_back(tumpukanBuku[i].top());
                tumpukanBuku[i].pop();
            }
            reverse(items.begin(), items.end());
            for (int item : items) {
                cout << "nilai item ke " << idx << " = " << item << endl;
                idx++;
            }
            cout << endl;
        }
    }

    return 0;
}
