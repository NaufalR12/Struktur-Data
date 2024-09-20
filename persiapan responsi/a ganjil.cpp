#include <iostream>
#include <iomanip>

using namespace std;

// Struktur data untuk DVD
struct DVD {
    int id;
    string nama;
    double harga;
    DVD* kiri;
    DVD* kanan;
};

// Struktur data untuk Node Peminjaman
struct Peminjaman {
    int id;
    string nama;
    Peminjaman* next;
};

// Variabel global untuk ID DVD dan Peminjaman
int idDVD = 1;
int idPeminjaman = 1;

// Fungsi-fungsi untuk Pendataan Stok DVD
DVD* buatNodeDVD(string nama, double harga) {
    DVD* newNode = new DVD;
    newNode->id = idDVD++;
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->kiri = newNode->kanan = nullptr;
    return newNode;
}

DVD* sisipNodeDVD(DVD* akar, string nama, double harga) {
    if (akar == nullptr) {
        return buatNodeDVD(nama, harga);
    }

    if (nama < akar->nama) {
        akar->kiri = sisipNodeDVD(akar->kiri, nama, harga);
    } else if (nama > akar->nama) {
        akar->kanan = sisipNodeDVD(akar->kanan, nama, harga);
    } else {
        cout << "DVD dengan nama tersebut sudah ada." << endl;
    }
    return akar;
}

void inOrderTraversal(DVD* akar) {
    if (akar != nullptr) {
        inOrderTraversal(akar->kiri);
        cout << setw(4) << akar->id << setw(20) << akar->nama << setw(10) << akar->harga << endl;
        inOrderTraversal(akar->kanan);
    }
}

DVD* cariDVD(DVD* akar, int id) {
    if (akar == nullptr || akar->id == id) {
        return akar;
    }

    if (id < akar->id) {
        return cariDVD(akar->kiri, id);
    }

    return cariDVD(akar->kanan, id);
}

// Fungsi-fungsi untuk Pendataan Peminjaman DVD
Peminjaman* enqueuePeminjaman(Peminjaman* belakang, int id, string nama) {
    Peminjaman* newNode = new Peminjaman;
    newNode->id = id;
    newNode->nama = nama;
    newNode->next = nullptr;

    if (belakang == nullptr) {
        return newNode;
    }

    belakang->next = newNode;
    return newNode;
}

Peminjaman* dequeuePeminjaman(Peminjaman* depan) {
    if (depan == nullptr) {
        cout << "Antrian peminjaman kosong." << endl;
        return nullptr;
    }

    Peminjaman* temp = depan;
    depan = depan->next;
    delete temp;
    return depan;
}

void displayPeminjaman(Peminjaman* depan) {
    if (depan == nullptr) {
        cout << "Antrian peminjaman kosong." << endl;
        return;
    }

    Peminjaman* bantu = depan;
    cout << "List Peminjaman DVD:\n";
    while (bantu != nullptr) {
        cout << "ID: " << bantu->id << " Nama: " << bantu->nama << endl;
        bantu = bantu->next;
    }
}

int main() {
    DVD* akarDVD = nullptr;
    Peminjaman* depanPeminjaman = nullptr;
    Peminjaman* belakangPeminjaman = nullptr;

    int pilih;

    do {
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Input Stok DVD\n";
        cout << "2. Lihat Stok DVD\n";
        cout << "3. Peminjaman DVD\n";
        cout << "4. Lihat List Peminjaman DVD\n";
        cout << "5. Pengembalian DVD\n";
        cout << "6. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                string nama;
                double harga;

                cout << "Input Stok DVD\n";
                cout << "Nama DVD: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Harga DVD: ";
                cin >> harga;

                akarDVD = sisipNodeDVD(akarDVD, nama, harga);
                cout << "DVD berhasil ditambahkan ke stok.\n";
                break;
            }
            case 2: {
                cout << "Lihat Stok DVD\n";
                cout << setw(4) << "ID" << setw(20) << "Nama DVD" << setw(10) << "Harga" << endl;
                inOrderTraversal(akarDVD);
                break;
            }
            case 3: {
                int id;
                string nama;

                cout << "Peminjaman DVD\n";
                cout << "Masukkan ID DVD yang ingin dipinjam: ";
                cin >> id;

                DVD* dvdToBorrow = cariDVD(akarDVD, id);

                if (dvdToBorrow != nullptr) {
                    cout << "Nama Peminjam: ";
                    cin.ignore();
                    getline(cin, nama);

                    belakangPeminjaman = enqueuePeminjaman(belakangPeminjaman, id, nama);
                    if (depanPeminjaman == nullptr) {
                        depanPeminjaman = belakangPeminjaman;
                    }

                    cout << "DVD berhasil dipinjam.\n";
                } else {
                    cout << "DVD dengan ID " << id << " tidak ditemukan.\n";
                }

                break;
            }
            case 4: {
                cout << "Lihat List Peminjaman DVD\n";
                displayPeminjaman(depanPeminjaman);
                break;
            }
            case 5: {
                cout << "Pengembalian DVD\n";
                if (depanPeminjaman == nullptr) {
                    cout << "Belum ada DVD yang dipinjam.\n";
                } else {
                    cout << "DVD dengan ID " << depanPeminjaman->id << " (" << depanPeminjaman->nama << ") berhasil dikembalikan.\n";
                    depanPeminjaman = dequeuePeminjaman(depanPeminjaman);
                }
                break;
            }
            case 6: {
                cout << "Program selesai.\n";
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

    } while (pilih != 6);

    return 0;
}
