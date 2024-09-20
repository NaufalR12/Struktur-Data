//Tugas Strukdur Data
//Tema: Sistem Manajemen Rumah Sakit
//kelas: IF-B
//Anggota kelompok: 
//          1. Almer Farand Rafael / 123220040
//          2. Azhar Fikri H./ 123220042
//          3. Febrian Chrisna A /12220051
//          4. Naufal Rafid Muhammad Faddila /123220052

//Deskripsi Proyek:
//Sistem ini akan memanfaatkan struktur data PTB untuk menyimpan 
//informasi pasien rumah sakit, seperti nama pasien, id pasien, 
//Golongan pasien, lama rawat inap, dan total harga rawat inap. 
//Selain itu, pohon telusur biner akan digunakan untuk menyimpan 
//data pasien berdasarkan urutan ID pasien.

//Program ini menggunakan konsep Pemrograman Berorientasi Objek 
//(PBO) dalam bahasa C++ dengan tujuan untuk menyusun kode secara 
//terstruktur dan modular. PBO memungkinkan pengelompokan fungsi-fungsi 
//terkait ke dalam kelas-kelas yang memiliki tanggung jawab spesifik. 
//Dengan menggunakan class, program dapat mengintegrasikan data dan 
//fungsionalitas terkait ke dalam objek, memudahkan pemeliharaan dan pengembangan. 

//Kode Program
#include <iostream>
#include <unordered_map>
#include <list> 
#include <limits>

using namespace std;

// Struktur untuk menyimpan informasi harga rawat inap berdasarkan golongan pasien
struct HargaRawatInap {
    char golongan;
    int harga;
};

// Struktur untuk menyimpan informasi pasien
struct Pasien {
    string nama;
    int id;
    char golongan;
    int lamaRawat;
    int totalHarga;
};

// Struktur untuk menyimpan node dalam pohon biner pencarian
struct TreeNode {
    Pasien data;
    TreeNode* left;
    TreeNode* right;
};

// Kelas untuk sistem manajemen rumah sakit
class SistemManajemenRumahSakit {
private:
    // Struktur data untuk menyimpan pasien berdasarkan ID
    unordered_map<int, Pasien> dataPasien;
    // Daftar pasien yang dihapus
    list<Pasien> dataPasienDihapus;  
    // Pohon biner pencarian untuk melacak data pasien
    TreeNode* pohonTelusurBiner;

public:
    SistemManajemenRumahSakit() : pohonTelusurBiner(nullptr) {}

    // Fungsi untuk menambahkan data pasien
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

        // Menghitung total harga berdasarkan golongan dan lama rawat
        pasien.totalHarga = hitungTotalHarga(pasien.golongan, pasien.lamaRawat);

        // Memeriksa apakah ID pasien sudah digunakan
        if (dataPasien.find(pasien.id) == dataPasien.end()) {
            // Menambahkan data pasien ke map dataPasien
            dataPasien[pasien.id] = pasien;

            // Menambahkan node ke dalam pohon pencarian biner
            if (pohonTelusurBiner == nullptr) {
                pohonTelusurBiner = tambahNode(pohonTelusurBiner, pasien);
            } else {
                tambahNode(pohonTelusurBiner, pasien);
            }

            cout << "==================================================\n";
            cout << "|       Data Pasien berhasil ditambahkan!        |\n";
            cout << "==================================================\n";
        } else {
            cout << "==================================================\n";
            cout << "|     Gagal menambahkan, id sudah digunakan!     |\n";
            cout << "==================================================\n";
        }
        system("pause");
    }

    // Fungsi untuk menampilkan data pasien
    void tampilkanDataPasien() {
        system("cls");
        // Memanggil fungsi tampilkanDataPasien dari pohonTelusurBiner
        tampilkanDataPasien(dataPasien);
        system("pause");
    }

    // Fungsi untuk mencari data pasien berdasarkan nama
    void cariDataPasien(string nama) {
        // Variabel untuk menentukan apakah data ditemukan
        bool dataDitemukan = false;
        
        // Menampilkan data pasien berdasarkan nama
        cout << "\nData Pasien dengan Nama '" << nama << "':\n";
        cariNode(pohonTelusurBiner, nama, dataDitemukan);

        if (!dataDitemukan) {
            cout << "==================================================\n";
            cout << "|         Data Pasien tidak ditemukan!           |\n";
            cout << "==================================================\n";
        }
    }

    // Fungsi untuk mencari data pasien berdasarkan rentang huruf awal dan huruf akhir
    void cariDataPasienByHurufAwal(char hurufAwal, char hurufAkhir = 'Z') {
        // Menampilkan data pasien dalam rentang huruf awal dan akhir
        cout << "\nData Pasien dalam Rentang (" << hurufAwal << " - " << hurufAkhir << "):\n";
        cariNodeByHurufAwal(pohonTelusurBiner, hurufAwal, hurufAkhir);
    }

    // Fungsi untuk menghapus data pasien berdasarkan ID
    void hapusDataPasien(int id) {
        // Mencari data pasien berdasarkan ID
        auto it = dataPasien.find(id);

        // Memeriksa apakah data ditemukan
        if (it != dataPasien.end()) {
            // Menampilkan pesan bahwa data dihapus dan memindahkan data ke dalam vector dataPasienDihapus
            cout << "==================================================\n";
            cout << "Data Pasien Nama: " << it->second.nama << " & ID " << it->second.id <<" dihapus! "<< endl;
            dataPasienDihapus.push_back(it->second); 
            dataPasien.erase(it);
            // Rebuild pohon pencarian biner setelah penghapusan data
            rebuildTree(dataPasien);
        } else {
            cout << "Data Pasien dengan ID " << id << " tidak ditemukan." << endl;
        }
    }


    // Fungsi untuk menampilkan history pasien menggunakan tiga jenis traversal
    void tampilkanHistoryPasien() {
        // Memeriksa apakah pohon pencarian biner kosong
        if (pohonTelusurBiner == nullptr) {
            cout << "PTB Kosong!\n";
            return;
        }

        // Menampilkan history pasien menggunakan in-order
        cout << "\nHistory Pasien (In-Order):\n";
        cout << "==================================================\n";
        inOrderTraversal(pohonTelusurBiner);
        
        // Menampilkan history pasien menggunakan pre-order
        cout << "\nHistory Pasien (pre-Order):\n";
        cout << "==================================================\n";
        preOrderTraversal(pohonTelusurBiner);
        
        // Menampilkan history pasien menggunakan post-order
        cout << "\nHistory Pasien (post-Order):\n";
        cout << "==================================================\n";
        postOrderTraversal(pohonTelusurBiner);
        
        // Menampilkan history pasien dalam bentuk list menggunakan tiga jenis traversal
        cout << "\n";
        inOrderTraversalList();
        cout << "\n";
        preOrderTraversalList();
        cout << "\n";
        postOrderTraversalList();
        cout << "\n";
    }

    // Fungsi untuk mencari data pasien berdasarkan huruf awal nama
    void cariDataPasienByHuruf(char huruf) {
        // Variabel untuk menentukan apakah data ditemukan
        bool dataDitemukan = false;

        // Menampilkan data pasien berdasarkan huruf awal nama
        cout << "\nData Pasien dengan Nama Dimulai dari Huruf '" << huruf << "':\n";
        cariNodeByHuruf(pohonTelusurBiner, huruf, dataDitemukan);

        if (!dataDitemukan) {
            cout << "==================================================\n";
            cout << "|         Data Pasien tidak ditemukan!           |\n";
            cout << "==================================================\n";
        }
    }

private:
    // Fungsi untuk menghitung total harga berdasarkan golongan dan lama rawat
    int hitungTotalHarga(char golongan, int lamaRawat) {
        // Inisialisasi map hargaRawatInap dengan golongan pasien dan harga per hari
        unordered_map<char, HargaRawatInap> hargaMap = {
            {'A', {'A', 150000}},
            {'B', {'B', 200000}},
            {'C', {'C', 250000}},
            {'D', {'D', 300000}},
            {'E', {'E', 350000}}
        };

        // Menghitung total harga dengan mengalikan harga per hari dengan lama rawat
        return hargaMap[golongan].harga * lamaRawat;
    }

    // Fungsi untuk menampilkan data pasien dari map dataPasien
    void tampilkanDataPasien(const unordered_map<int, Pasien>& dataPasien) {
        cout << "==================================================\n";
        cout << "|                  Data Pasien                   |\n";
        cout << "==================================================\n";
        // Iterasi melalui map dan menampilkan informasi pasien
        for (auto const& entry : dataPasien) {
            Pasien pasien = entry.second;
            cout << "Nama: " << pasien.nama << endl;
            cout << "ID: " << pasien.id << endl;
            cout << "Golongan: " << pasien.golongan << endl;
            cout << "Total Harga: " << pasien.totalHarga << endl;
            cout << "==================================================\n";
        }
    }

    // Fungsi rekursif untuk menambahkan node ke dalam pohon pencarian
    TreeNode* tambahNode(TreeNode* root, Pasien data) {
        // Jika root kosong, buat node baru
        if (root == nullptr) {
            TreeNode* newNode = new TreeNode;
            newNode->data = data;
            newNode->left = newNode->right = nullptr;
            return newNode;
        }

        // Menentukan apakah node baru akan berada di kiri atau kanan
        if (data.id < root->data.id) {
            root->left = tambahNode(root->left, data);
        } else {
            root->right = tambahNode(root->right, data);
        }

        return root;
    }

    // Fungsi rekursif untuk mencari node berdasarkan nama dalam pohon
    void cariNode(TreeNode* root, string nama, bool& dataDitemukan) {
        if (root == nullptr) {
            return; 
        }

        // Jika nama ditemukan, set dataDitemukan menjadi true dan tampilkan informasi pasien
        if (root->data.nama.find(nama) != string::npos) {
            dataDitemukan = true;
            cout << "==================================================\n";
            cout << "Nama: " << root->data.nama << endl;
            cout << "ID: " << root->data.id << endl;
            cout << "Golongan: " << root->data.golongan << endl;
            cout << "Total Harga: " << root->data.totalHarga << endl;
        }

        // Rekursif ke anak kiri dan kanan
        cariNode(root->left, nama, dataDitemukan);
        cariNode(root->right, nama, dataDitemukan);
    }


    // Fungsi rekursif untuk mencari node berdasarkan rentang huruf awal dalam pohon pencarian biner
    void cariNodeByHurufAwal(TreeNode* root, char hurufAwal, char hurufAkhir) {
        if (root == nullptr) {
            return;
        }

        // Jika huruf awal dan huruf akhir berada dalam rentang nama pasien, tampilkan informasi pasien
        if (root->data.nama[0] >= hurufAwal && root->data.nama[0] <= hurufAkhir) {
            cout << "==================================================\n";
            cout << "Nama: " << root->data.nama << endl;
            cout << "ID: " << root->data.id << endl;
            cout << "Golongan: " << root->data.golongan << endl;
            cout << "Total Harga: " << root->data.totalHarga << endl;
        }

        // Rekursif ke anak kiri jika huruf awal sesuai
        if (root->data.nama[0] >= hurufAwal) {
            cariNodeByHurufAwal(root->left, hurufAwal, hurufAkhir);
        }

        // Rekursif ke anak kanan jika huruf akhir sesuai
        if (root->data.nama[0] <= hurufAkhir) {
            cariNodeByHurufAwal(root->right, hurufAwal, hurufAkhir);
        }
    }

    // Fungsi rekursif untuk mencari node berdasarkan huruf awal dalam pohon pencarian biner
    void cariNodeByHuruf(TreeNode* root, char huruf, bool& dataDitemukan) {
        if (root == nullptr) {
            return;
        }

        // Jika huruf awal sesuai dengan nama pasien, tampilkan informasi pasien
        if (root->data.nama[0] == huruf) {
            dataDitemukan = true;
            cout << "==================================================\n";
            cout << "Nama: " << root->data.nama << endl;
            cout << "ID: " << root->data.id << endl;
            cout << "Golongan: " << root->data.golongan << endl;
            cout << "Total Harga: " << root->data.totalHarga << endl;
            cout << "==================================================\n";
        }

        // Rekursif ke anak kiri dan kanan
        cariNodeByHuruf(root->left, huruf, dataDitemukan);
        cariNodeByHuruf(root->right, huruf, dataDitemukan);
    }

    // Fungsi rekursif untuk melakukan in-order 
    void inOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            // Rekursif ke anak kiri
            inOrderTraversal(root->left);
            // Tampilkan informasi pasien
            cout << "Nama: " << root->data.nama << endl;
            cout << "ID: " << root->data.id << endl;
            cout << "Golongan: " << root->data.golongan << endl;
            cout << "Total Harga: " << root->data.totalHarga << endl;
            cout << "==================================================\n";
            inOrderTraversal(root->right);
        }
    }

    // Fungsi rekursif untuk melakukan pre-order 
    void preOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            cout << "Nama: " << root->data.nama << endl;
            cout << "ID: " << root->data.id << endl;
            cout << "Golongan: " << root->data.golongan << endl;
            cout << "Total Harga: " << root->data.totalHarga << endl;
            cout << "==================================================\n";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    // Fungsi rekursif untuk melakukan post-order 
    void postOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << "Nama: " << root->data.nama << endl;
            cout << "ID: " << root->data.id << endl;
            cout << "Golongan: " << root->data.golongan << endl;
            cout << "Total Harga: " << root->data.totalHarga << endl;
            cout << "==================================================\n";
        }
    }

    // Fungsi untuk membangun kembali pohon pencarian biner setelah menghapus data
    void rebuildTree(const unordered_map<int, Pasien>& dataPasien) {
        // Hapus pohon lama dan alokasi memori untuk pohon baru
        deleteTree(pohonTelusurBiner);
        pohonTelusurBiner = nullptr;

        // Bangun pohon baru dengan data pasien yang tersisa
        for (auto const& entry : dataPasien) {
            pohonTelusurBiner = tambahNode(pohonTelusurBiner, entry.second);
        }
    }

    // Fungsi rekursif untuk menghapus pohon dan membebaskan memori
    void deleteTree(TreeNode* root) {
        if (root != nullptr) {
            deleteTree(root->left);
            deleteTree(root->right);
            // Hapus node saat ini dan bebaskan memori
            delete root;
        }
    }

    // Fungsi untuk menampilkan daftar pasien yang dihapus menggunakan in-order
    void inOrderTraversalList() {
        cout << "In-Order Traversal Data Pasien yang Dihapus:\n";
        cout << "==================================================\n";
        for (const auto& pasien : dataPasienDihapus) {
            cout << "Nama: " << pasien.nama << endl;
            cout << "ID: " << pasien.id << endl;
            cout << "Golongan: " << pasien.golongan << endl;
            cout << "Total Harga: " << pasien.totalHarga << "\n";
            cout << "==================================================\n";
        }
        
    }

    // Fungsi untuk menampilkan daftar pasien yang dihapus menggunakan pre-order 
    void preOrderTraversalList() {
        cout << "Pre-Order Traversal Data Pasien yang Dihapus:\n";
        cout << "==================================================\n";
        for (const auto& pasien : dataPasienDihapus) {
            cout << "Nama: " << pasien.nama << endl;
            cout << "ID: " << pasien.id << endl;
            cout << "Golongan: " << pasien.golongan << endl;
            cout << "Total Harga: " << pasien.totalHarga << "\n";
            cout << "==================================================\n";
        }
        
    }

    // Fungsi untuk menampilkan daftar pasien yang dihapus menggunakan post-order
    void postOrderTraversalList() {
        cout << "Post-Order Traversal Data Pasien yang Dihapus:\n";
        cout << "==================================================\n";
        for (const auto& pasien : dataPasienDihapus) {
            cout << "Nama: " << pasien.nama << endl;
            cout << "ID: " << pasien.id << endl;
            cout << "Golongan: " << pasien.golongan << endl;
            cout << "Total Harga: " << pasien.totalHarga << "\n";
            cout << "==================================================\n";
        }
        
    }
};

int main() {
    // Membuat objek dari kelas SistemManajemenRumahSakit
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
            cout << "| H/h untuk rentang huruf                        |\n";
            cout << "==================================================\n";
            cout << "Pilih: ";
            cin >> jenisPencarian;
            // Membersihkan buffer input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            if (jenisPencarian == 'N' || jenisPencarian == 'n') {
                string nama;
                cin.ignore();
                cout << "==================================================\n";
                cout << "Input Nama: ";
                getline(cin, nama);
                cout << "==================================================\n";
                sistem.cariDataPasien(nama);
            } else if (jenisPencarian == 'H' || jenisPencarian == 'h') {
                char hurufAwal;
                cout << "==================================================\n";
                cout << "Input Huruf Awal: ";
                cin >> hurufAwal;
                cout << "==================================================\n";

                char pilihanHurufAkhir;
                cout << "Apakah Anda ingin menginput Huruf Akhir? (y/n): ";
                cin >> pilihanHurufAkhir;

                if (pilihanHurufAkhir == 'y' || pilihanHurufAkhir == 'Y') {
                    char hurufAkhir;
                    cout << "==================================================\n";
                    cout << "Input Huruf Akhir: ";
                    cin >> hurufAkhir;
                    cout << "==================================================\n";
                    sistem.cariDataPasienByHurufAwal(hurufAwal, hurufAkhir);
                } else {
                    sistem.cariDataPasienByHuruf(hurufAwal);
                }
            } else {
                cout << "==================================================\n";
                cout << "|          Jenis pencarian tidak valid!          |";
                cout << "==================================================\n";
            }
            cout << "==================================================\n";
            system("pause");
            break;
        }
        case 4: {
            system("cls");
            cout << "==================================================\n";
            cout << "                Hapus Data Pasien                 \n";
            cout << "==================================================\n";
            int id;
            cout << "Input ID Pasien yang akan dihapus: ";
            cin >> id;
            sistem.hapusDataPasien(id);
            cout << "==================================================\n";
            system("pause");
            break;
        }
        case 5:
            system("cls");
            cout << "==================================================\n";
            cout << "               History Data Pasien                \n";
            cout << "==================================================\n";
            sistem.tampilkanHistoryPasien();
            cout << "==================================================\n";
            system("pause");
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
