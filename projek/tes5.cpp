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
        system("cls");
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

        // Check if ID already exists
        if (dataPasien.find(pasien.id) == dataPasien.end()) {
            dataPasien[pasien.id] = pasien;

            // Check if the tree node addition is successful
            if (tambahNode(pohonTelusurBiner, pasien) != nullptr) {
                cout << "==================================================\n";
                cout << "|       Data Pasien berhasil ditambahkan!        |\n";
                cout << "==================================================\n";
            } else {
                cout << "==================================================\n";
                cout << "|  Gagal menambahkan data Pasien ke dalam tree!  |\n";
                cout << "==================================================\n";
                dataPasien.erase(pasien.id); // Rollback data
            }
        } else {
            cout << "==================================================\n";
            cout << "|     Gagal menambahkan, id sudah digunakan!     |\n";
            cout << "==================================================\n";
        }
        system("pause");
    }

    void tampilkanDataPasien() {
        system("cls");
        tampilkanDataPasien(dataPasien);
        system("pause");
    }

    void cariDataPasien() {
        string nama;
        cout << "Input Nama Pasien yang akan dicari: ";
        cin.ignore();
        getline(cin, nama);
        cariNode(pohonTelusurBiner, nama);
        system("pause");
    }

    void cariDataPasienByHuruf() {
        char huruf;
        cout << "Input Huruf untuk Pencarian: ";
        cin >> huruf;
        cariNodeByHuruf(pohonTelusurBiner, huruf);
        system("pause");
    }

    void cariDataPasienByHurufAwal() {
        char hurufAwal;
        cout << "Input Huruf Awal untuk Pencarian: ";
        cin >> hurufAwal;
        cariNodeByHurufAwal(pohonTelusurBiner, hurufAwal);
        system("pause");
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
        cout << "==================================================\n";
        cout << "|                  Data Pasien                   |\n";
        cout << "==================================================\n";
        for (auto const& entry : dataPasien) {
            Pasien pasien = entry.second;
            cout << "Nama: " << pasien.nama << endl;
            cout << "ID: " << pasien.id << endl;
            cout << "Golongan: " << pasien.golongan << endl;
            cout << "Total Harga: " << pasien.totalHarga << endl;
            cout << "==================================================\n";
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
        }

        cariNode(root->left, nama);
        cariNode(root->right, nama);
    }

    void cariNodeByHuruf(TreeNode* root, char huruf) {
        if (root == nullptr) {
            return;
        }

        if (root->data.nama.find(huruf) != string::npos) {
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
        }

        cariNodeByHuruf(root->left, huruf);
        cariNodeByHuruf(root->right, huruf);
    }

    void cariNodeByHurufAwal(TreeNode* root, char hurufAwal) {
        if (root == nullptr) {
            return;
        }

        if (root->data.nama[0] == hurufAwal) {
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
        }

        if (root->data.nama[0] > hurufAwal) {
            cariNodeByHurufAwal(root->left, hurufAwal);
        }

        if (root->data.nama[0] < hurufAwal) {
            cariNodeByHurufAwal(root->right, hurufAwal);
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
            system("cls");
            char jenisPencarian;
            cout << "==================================================\n";
            cout << "|              Pilih Jenis Pencarian             |\n";
            cout << "==================================================\n";
            cout << "| N/n untuk pencarian berdasarkan nama           |\n";
            cout << "| H/h untuk pencarian berdasarkan huruf          |\n";
            cout << "| A/a untuk pencarian berdasarkan huruf awal     |\n";
            cout << "==================================================\n";
            cout << "Pilih: ";
            cin >> jenisPencarian;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

            switch (jenisPencarian) {
            case 'N':
            case 'n':
                sistem.cariDataPasien();
                break;
            case 'H':
            case 'h':
                sistem.cariDataPasienByHuruf();
                break;
            case 'A':
            case 'a':
                sistem.cariDataPasienByHurufAwal();
                break;
            default:
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
