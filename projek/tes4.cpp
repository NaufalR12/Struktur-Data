#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

// Struktur data untuk harga rawat inap
struct HargaRawatInap {
    char golongan;
    int harga;
};

// Struktur data pasien
struct Pasien {
    string nama;
    int id;
    char golongan;
    int lamaRawat;
    int totalHarga;
};

// Node untuk pohon telusur biner
struct TreeNode {
    Pasien data;
    TreeNode* left;
    TreeNode* right;
};

// Kelas untuk sistem manajemen rumah sakit
class SistemManajemenRumahSakit {
private:
    unordered_map<int, Pasien> dataPasien;
    TreeNode* pohonTelusurBiner;

public:
    SistemManajemenRumahSakit() : pohonTelusurBiner(nullptr) {}

    void tambahDataPasien() {
        Pasien pasien;
        cout << "==================================================\n";
        cout << "|              Input Data Pasien                 |\n";
        cout << "==================================================\n";
        cin.ignore();
        cout << "Input Nama Pasien: ";
        getline(cin, pasien.nama);
        cout << "Input ID Pasien: ";
        cin >> pasien.id;
        cout << "Input Golongan Pasien (A, B, C, D, E): ";
        cin >> pasien.golongan;
        cout << "Input Lama Rawat Inap: ";
        cin >> pasien.lamaRawat;

        pasien.totalHarga = hitungTotalHarga(pasien.golongan, pasien.lamaRawat);

        dataPasien[pasien.id] = pasien;

        pohonTelusurBiner = tambahNode(pohonTelusurBiner, pasien);
    }

    void tampilkanDataPasien() {
        cout << "\nData Pasien:\n";
        tampilkanDataPasien(dataPasien);
    }

    void cariDataPasien(string nama) {
        cout << "\nData Pasien dengan Nama '" << nama << "':\n";
        cariNode(pohonTelusurBiner, nama);
    }

    void cariDataPasienByHurufAwal(char hurufAwal, char hurufAkhir = 'Z') {
        cout << "\nData Pasien dalam Rentang (" << hurufAwal << " & " << hurufAkhir << "):\n";
        cariNodeByHurufAwal(pohonTelusurBiner, hurufAwal, hurufAkhir);
    }

    void hapusDataPasien(int id) {
        auto it = dataPasien.find(id);
        if (it != dataPasien.end()) {
            cout << "Data Pasien yang dihapus: Nama " << it->second.nama << ", ID " << it->second.id << endl;
            dataPasien.erase(it);
            rebuildTree(dataPasien);
        } else {
            cout << "Data Pasien dengan ID " << id << " tidak ditemukan." << endl;
        }
    }

    void tampilkanHistoryPasien() {
        if (pohonTelusurBiner == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        cout << "\nHistory Pasien (In-Order Traversal):\n";
        inOrderTraversal(pohonTelusurBiner); cout << "\n";
        cout << "\nHistory Pasien (pre-Order Traversal):\n";
        preOrderTraversal(pohonTelusurBiner); cout << "\n";
        cout << "\nHistory Pasien (post-Order Traversal):\n";
        postOrderTraversal(pohonTelusurBiner); cout << "\n";
    }

    void cariDataPasienByHuruf(char huruf) {
        cout << "\nData Pasien dengan Nama Dimulai dari Huruf '" << huruf << "':\n";
        cariNodeByHuruf(pohonTelusurBiner, huruf);
    }

    void cariNodeByHuruf(TreeNode* root, char huruf) {
        if (root == nullptr) {
            return;
        }

        if (root->data.nama[0] == huruf) {
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
        }

        if (root->data.nama[0] > huruf) {
            cariNodeByHuruf(root->left, huruf);
        }

        if (root->data.nama[0] < huruf) {
            cariNodeByHuruf(root->right, huruf);
        }
    }


private:
    int hitungTotalHarga(char golongan, int lamaRawat) {
        unordered_map<char, HargaRawatInap> hargaMap = {
            {'A', {'A', 150000}},
            {'B', {'B', 200000}},
            {'C', {'C', 250000}},
            {'D', {'D', 300000}},
            {'E', {'E', 350000}}
        };

        return hargaMap[golongan].harga * lamaRawat;
    }

    void tampilkanDataPasien(const unordered_map<int, Pasien>& dataPasien) {
        cout << "\nData Pasien:\n";
        for (auto const& entry : dataPasien) {
            Pasien pasien = entry.second;
            cout << "Nama: " << pasien.nama << ", ID: " << pasien.id << ", Total Harga: " << pasien.totalHarga << endl;
        }
    }

    TreeNode* tambahNode(TreeNode* root, Pasien data) {
        if (root == nullptr) {
            TreeNode* newNode = new TreeNode;
            newNode->data = data;
            newNode->left = newNode->right = nullptr;
            return newNode;
        }

        if (data.id < root->data.id) {
            root->left = tambahNode(root->left, data);
        } else {
            root->right = tambahNode(root->right, data);
        }

        return root;
    }

    void cariNode(TreeNode* root, string nama) {
        if (root == nullptr) {
            cout << "Data Pasien tidak ditemukan.\n";
            return;
        }

        if (root->data.nama == nama) {
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
        } else if (nama < root->data.nama) {
            cariNode(root->left, nama);
        } else {
            cariNode(root->right, nama);
        }
    }

    void cariNodeByHurufAwal(TreeNode* root, char hurufAwal, char hurufAkhir) {
        if (root == nullptr) {
            return;
        }

        if (root->data.nama[0] >= hurufAwal && root->data.nama[0] <= hurufAkhir) {
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
        }

        if (root->data.nama[0] >= hurufAwal) {
            cariNodeByHurufAwal(root->left, hurufAwal, hurufAkhir);
        }

        if (root->data.nama[0] <= hurufAkhir) {
            cariNodeByHurufAwal(root->right, hurufAwal, hurufAkhir);
        }
    }

    void inOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
            inOrderTraversal(root->right);
        }
    }

    void preOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void postOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
        }
    }

    void rebuildTree(const unordered_map<int, Pasien>& dataPasien) {
        // Free the memory of the old tree
        deleteTree(pohonTelusurBiner);
        // Create a new tree
        pohonTelusurBiner = nullptr;
        for (auto const& entry : dataPasien) {
            pohonTelusurBiner = tambahNode(pohonTelusurBiner, entry.second);
        }
    }

    // Function to delete the tree and free memory
    void deleteTree(TreeNode* root) {
        if (root != nullptr) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
};

int main() {
    SistemManajemenRumahSakit sistem;
    int pilihan;
    do {
        system("cls");
        cout << "==================================================\n";
        cout << "|          Sistem Manajemen Rumah Sakit          |\n";
        cout << "==================================================\n";
        cout << "| 1. Input Data Pasien                           |\n";
        cout << "| 2. Tampilkan Data Pasien                       |\n";
        cout << "| 3. Cari Data Pasien                            |\n";
        cout << "| 4. Hapus Data Pasien                           |\n";
        cout << "| 5. Tampilkan History Pasien                    |\n";
        cout << "| 6. Keluar                                      |\n";
        cout << "==================================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            sistem.tambahDataPasien();
            break;
        case 2:
            sistem.tampilkanDataPasien();
            break;
        case 3: {
            char jenisPencarian;
            cout << "Pilih Jenis Pencarian (N/n untuk Nama, H/h untuk Huruf Awal): ";
            cin >> jenisPencarian;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            if (jenisPencarian == 'N' || jenisPencarian == 'n') {
                string nama;
                cout << "Input Nama: ";
                cin >> nama;
                sistem.cariDataPasien(nama);
            } else if (jenisPencarian == 'H' || jenisPencarian == 'h') {
                char hurufAwal;
                cout << "Input Huruf Awal: ";
                cin >> hurufAwal;

                char pilihanHurufAkhir;
                cout << "Apakah Anda ingin menginput Huruf Akhir? (y/n): ";
                cin >> pilihanHurufAkhir;

                if (pilihanHurufAkhir == 'y' || pilihanHurufAkhir == 'Y') {
                    char hurufAkhir;
                    cout << "Input Huruf Akhir: ";
                    cin >> hurufAkhir;
                    sistem.cariDataPasienByHurufAwal(hurufAwal, hurufAkhir);
                } else {
                    sistem.cariDataPasienByHuruf(hurufAwal);
                }
            } else {
                cout << "Jenis pencarian tidak valid.\n";
            }
            system("pause");
            break;
        }
        case 4: {
            int id;
            cout << "Input ID Pasien yang akan dihapus: ";
            cin >> id;
            sistem.hapusDataPasien(id);
            break;
        }
        case 5:
            sistem.tampilkanHistoryPasien();
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 6);

    return 0;
}