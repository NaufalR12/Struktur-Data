#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// Struktur data untuk stok DVD
struct DVD {
    int id;
    string nama;
    double harga;
    DVD* kiri;
    DVD* kanan;
};

// Struktur data untuk peminjaman DVD
struct Peminjaman {
    int id;
    string nama;
    Peminjaman* next;
};

// Fungsi untuk membuat node DVD baru
DVD* buatDVD(int id, const string& nama, double harga) {
    DVD* baru = new DVD;
    baru->id = id;
    baru->nama = nama;
    baru->harga = harga;
    baru->kiri = nullptr;
    baru->kanan = nullptr;
    return baru;
}

// Fungsi untuk menambahkan DVD ke dalam Pohon Biner Terurut (BST)
DVD* tambahDVD(DVD* root, int id, const string& nama, double harga) {
    if (root == nullptr) {
        return buatDVD(id, nama, harga);
    }

    if (id < root->id) {
        root->kiri = tambahDVD(root->kiri, id, nama, harga);
    } else if (id > root->id) {
        root->kanan = tambahDVD(root->kanan, id, nama, harga);
    } else {
        cout << "DVD dengan ID tersebut sudah ada." << endl;
    }
    return root;
}

// Fungsi untuk menampilkan stok DVD secara terurut
void tampilStokDVD(DVD* root) {
    if (root != nullptr) {
        tampilStokDVD(root->kiri);
        cout << setw(4) << root->id << setw(20) << root->nama << setw(10) << root->harga << endl;
        tampilStokDVD(root->kanan);
    }
}

// Fungsi untuk menambahkan peminjaman ke dalam stack
void pinjamDVD(Peminjaman*& top, int id, const string& nama) {
    Peminjaman* baru = new Peminjaman;
    baru->id = id;
    baru->nama = nama;
    baru->next = top;
    top = baru;
}

// Fungsi untuk menampilkan list peminjaman secara terurut
void tampilListPeminjaman(Peminjaman* top) {
    cout << setw(4) << "ID" << setw(20) << "Nama Peminjam" << endl;
    cout << "---------------------------" << endl;

    Peminjaman* bantu = top;
    while (bantu != nullptr) {
        cout << setw(4) << bantu->id << setw(20) << bantu->nama << endl;
        bantu = bantu->next;
    }
}

// Fungsi untuk mengembalikan DVD dari stack
void kembalikanDVD(Peminjaman*& top) {
    if (top == nullptr) {
        cout << "Tidak ada DVD yang dipinjam." << endl;
        return;
    }

    Peminjaman* hapus = top;
    top = top->next;
    delete hapus;
}

/* Fungsi untuk menghapus semua node pada BST
void hapusStokDVD(DVD*& root) {
    if (root != nullptr) {
        hapusStokDVD(root->kiri);
        hapusStokDVD(root->kanan);
        delete root;
    }
}
*/
int main() {
    DVD* stokDVD = nullptr;
    Peminjaman* listPeminjaman = nullptr;
    int idCounter = 1;
    char ulang = 'y';

    while (toupper(ulang) == 'Y') {
        system("cls");
        cout << "+=============================+\n";
        cout << "|      -+- Menu Utama -+-     |\n";
        cout << "+=============================+\n";
        cout << "| 1. Input Stok DVD          |\n";
        cout << "| 2. Lihat Stok DVD          |\n";
        cout << "| 3. Peminjaman DVD          |\n";
        cout << "| 4. Lihat List Peminjaman   |\n";
        cout << "| 5. Pengembalian DVD        |\n";
        cout << "| 6. Exit                    |\n";
        cout << "+=============================+\n";
        cout << "Pilih menu: ";
        int menu;
        cin >> menu;

        switch (menu) {
            case 1: // Input Stok DVD
                {
                    string namaDVD;
                    double hargaDVD;
                    cout << "Masukkan nama DVD: ";
                    cin.ignore();
                    getline(cin, namaDVD);
                    cout << "Masukkan harga DVD: ";
                    cin >> hargaDVD;
                    stokDVD = tambahDVD(stokDVD, idCounter++, namaDVD, hargaDVD);
                    cout << "DVD berhasil ditambahkan ke stok." << endl;
                }
                break;

            case 2: // Lihat Stok DVD
                {
                    cout << "+=============================+\n";
                    cout << "|      -+- Stok DVD -+-       |\n";
                    cout << "+=============================+\n";
                    cout << setw(4) << "ID" << setw(20) << "Nama DVD" << setw(10) << "Harga" << endl;
                    cout << "---------------------------" << endl;
                    tampilStokDVD(stokDVD);
                }
                break;

           case 3: // Peminjaman DVD
                {
                    int idPeminjam;
                    string namaPeminjam;

                    cout << "Masukkan ID DVD yang akan dipinjam: ";
                    cin >> idPeminjam;

                    // Membuat dummy node pada BST
                    stokDVD = tambahDVD(stokDVD, idPeminjam, "", 0);

                    // Meminta input nama peminjam
                    cin.ignore();
                    cout << "Masukkan nama peminjam: ";
                    getline(cin, namaPeminjam);

                    // Menambah peminjaman ke stack
                    pinjamDVD(listPeminjaman, idPeminjam, namaPeminjam);

                    cout << "DVD berhasil dipinjam." << endl;
                }
                break;


            case 4: // Lihat List Peminjaman
                {
                    cout << "+=============================+\n";
                    cout << "| -+- List Peminjaman -+-    |\n";
                    cout << "+=============================+\n";
                    tampilListPeminjaman(listPeminjaman);
                }
                break;

            case 5: // Pengembalian DVD
                {
                    kembalikanDVD(listPeminjaman); // Mengembalikan DVD dari stack
                    cout << "DVD berhasil dikembalikan." << endl;
                }
                break;

            case 6: // Exit
                ulang = 't';
                break;

            default:
                cout << "Menu tidak valid." << endl;
        }

        cout << "\nKembali ke menu utama? (y/t): ";
        cin >> ulang;
    }

    /* Membersihkan memori
    hapusStokDVD(stokDVD);

    return 0;*/
}


