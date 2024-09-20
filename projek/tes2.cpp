#include <iostream>
#include <unordered_map>
#include <cstdlib>

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
    // Fungsi untuk menambah data pasien ke dalam struktur hash
    void tambahDataPasien() {
        Pasien pasien;
        cout << "Input Nama Pasien: ";
        cin >> pasien.nama;
        cout << "Input ID Pasien: ";
        cin >> pasien.id;
        cout << "Input Golongan Pasien (A, B, C, D, E): ";
        cin >> pasien.golongan;
        cout << "Input Lama Rawat Inap: ";
        cin >> pasien.lamaRawat;

        // Menghitung total harga rawat inap berdasarkan golongan
        pasien.totalHarga = hitungTotalHarga(pasien.golongan, pasien.lamaRawat);

        // Menambah data pasien ke dalam struktur hash
        dataPasien[pasien.id] = pasien;

        // Menambah data pasien ke dalam pohon telusur biner
        pohonTelusurBiner = tambahNode(pohonTelusurBiner, pasien);
    }

    // Fungsi untuk menampilkan data pasien dengan total harga rawat inap menggunakan struktur hash
    void tampilkanDataPasien() {
        cout << "\nData Pasien:\n";
        tampilkanDataPasien(dataPasien);
    }

    // Fungsi untuk mencari data pasien berdasarkan rentang nama pasien menggunakan pohon telusur biner
    void cariDataPasien(string namaAwal, string namaAkhir) {
        cout << "\nData Pasien dalam Rentang (" << namaAwal << " & " << namaAkhir << "):\n";
        cariNode(pohonTelusurBiner, namaAwal, namaAkhir);
    }

    // Fungsi untuk menghapus data pasien menggunakan struktur hash
    void hapusDataPasien(int id) {
        auto it = dataPasien.find(id);
        if (it != dataPasien.end()) {
            // Menyimpan data yang dihapus ke dalam history pasien
            cout << "Data Pasien yang dihapus: Nama " << it->second.nama << ", ID " << it->second.id << endl;
            // Hapus data pasien dari struktur hash
            dataPasien.erase(it);
            // Rebuild pohon telusur biner setelah penghapusan
            pohonTelusurBiner = rebuildTree(dataPasien);
        } else {
            cout << "Data Pasien dengan ID " << id << " tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk menampilkan history pasien (in-order traversal)
    void tampilkanHistoryPasien() {
        cout << "\nHistory Pasien (In-Order Traversal):\n";
        inOrderTraversal(pohonTelusurBiner);
    }

private:
    // Fungsi untuk menghitung total harga rawat inap berdasarkan golongan
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

    // Fungsi untuk menampilkan data pasien menggunakan struktur hash
    void tampilkanDataPasien(const unordered_map<int, Pasien>& dataPasien) {
        cout << "\nData Pasien:\n";
        for (auto const& entry : dataPasien) {
            Pasien pasien = entry.second;
            cout << "Nama: " << pasien.nama << ", ID: " << pasien.id << ", Total Harga: " << pasien.totalHarga << endl;
        }
    }

    // Fungsi untuk menambah node ke dalam pohon telusur biner
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

    // Fungsi untuk mencari dan menampilkan data pasien dalam rentang nama pasien
    void cariNode(TreeNode* root, string namaAwal, string namaAkhir) {
        if (root == nullptr) {
            return;
        }

        if (root->data.nama >= namaAwal && root->data.nama <= namaAkhir) {
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
        }

        if (root->data.nama >= namaAwal) {
            cariNode(root->left, namaAwal, namaAkhir);
        }

        if (root->data.nama <= namaAkhir) {
            cariNode(root->right, namaAwal, namaAkhir);
        }
    }

    // Fungsi untuk melakukan in-order traversal pada pohon telusur biner
    void inOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            cout << "Nama: " << root->data.nama << ", ID: " << root->data.id << ", Total Harga: " << root->data.totalHarga << endl;
            inOrderTraversal(root->right);
        }
    }

    // Fungsi untuk me-rebuild pohon telusur biner dari data pasien
    TreeNode* rebuildTree(const unordered_map<int, Pasien>& dataPasien) {
        TreeNode* newTree = nullptr;
        for (auto const& entry : dataPasien) {
            newTree = tambahNode(newTree, entry.second);
        }
        return newTree;
    }
};

int main() {
    SistemManajemenRumahSakit sistem;
    int pilihan;
    do {
        cout << "\n=== Sistem Manajemen Rumah Sakit ===\n";
        cout << "1. Tambah Data Pasien\n";
        cout << "2. Tampilkan Data Pasien\n";
        cout << "3. Cari Data Pasien dalam Rentang Nama\n";
        cout << "4. Hapus Data Pasien\n";
        cout << "5. Tampilkan History Pasien\n";
        cout << "0. Keluar\n";
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
            string namaAwal, namaAkhir;
            cout << "Input Nama Awal: ";
            cin >> namaAwal;
            cout << "Input Nama Akhir: ";
            cin >> namaAkhir;
            sistem.cariDataPasien(namaAwal, namaAkhir);
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
        case 0:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 0);

    return 0;
}
