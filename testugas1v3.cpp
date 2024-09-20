#include <iostream>
#include <string>
#include <cstdlib> // Untuk menggunakan malloc

using namespace std;

struct buku {
    int noBuku;
    string judul;
    string penulis;
    string penerbit;
    int tahunTerbit;
    string jenisBuku;
    buku* next;
};

buku *awal;
buku *akhir;

void buatListBaru();
void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void sisipTengah(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void sisipBelakang(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void hapusList(int target);
void cetakList();

int main() {
    buatListBaru();
    int jumlahBuku;
    cout << "Masukkan jumlah buku yang ingin Anda tambahkan: ";
    cin >> jumlahBuku;
    cin.ignore();

    for (int i = 0; i < jumlahBuku; i++) {
        int no;
        string judul, penulis, penerbit, jenis;
        int tahun;

        cout << "Masukkan data buku ke-" << i + 1 << endl;
        cout << "Nomor Buku: ";    cin >> no;
        cin.ignore();
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Penulis: ";
        getline(cin, penulis);
        cout << "Penerbit: ";
        getline(cin, penerbit);
        cout << "Tahun Terbit: ";
        cin >> tahun;
        cin.ignore();
        cout << "Jenis Buku: ";
        getline(cin, jenis);
        cout << endl;

        sisipDepan(no, judul, penulis, penerbit, tahun, jenis);
    }

    cetakList();

    buku* bantu = awal;
    while (bantu != NULL) {
        buku* hapus = bantu;
        bantu = bantu->next;
        free(hapus); // Gunakan free() untuk menghapus memori yang dialokasikan oleh malloc
    }

    return 0;
}

void buatListBaru() {
    awal = NULL;
    akhir = NULL;
}

void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = (buku*)malloc(sizeof(buku)); // Menggunakan malloc
    bukuBaru->noBuku = no;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->penerbit = penerbit;
    bukuBaru->tahunTerbit = tahun;
    bukuBaru->jenisBuku = jenis;
    bukuBaru->next = NULL;

    if (awal == NULL) {
        awal = bukuBaru;
        akhir = bukuBaru;
    } else {
        bukuBaru->next = awal;
        awal = bukuBaru;
    }
}

void sisipTengah(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = (buku*)malloc(sizeof(buku)); // Menggunakan malloc
    bukuBaru->noBuku = no;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->penerbit = penerbit;
    bukuBaru->tahunTerbit = tahun;
    bukuBaru->jenisBuku = jenis;
    bukuBaru->next = NULL;

    buku* bantu = awal;
    // Cari posisi di mana pointer bantu akan berhenti
    while (bantu->next->noBuku < no) {
        bantu = bantu->next;
    }

    // Sisip tengah
    bukuBaru->next = bantu->next;
    bantu->next = bukuBaru;
}

void sisipBelakang(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = (buku*)malloc(sizeof(buku)); // Menggunakan malloc
    bukuBaru->noBuku = no;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->penerbit = penerbit;
    bukuBaru->tahunTerbit = tahun;
    bukuBaru->jenisBuku = jenis;
    bukuBaru->next = NULL;

    // Kasus khusus: sisip di awal linked list
    if (awal == NULL || awal->noBuku > no) {
        bukuBaru->next = awal;
        awal = bukuBaru;
        return;
    }

    buku* bantu = awal;

    // Cari posisi di mana buku harus disisipkan
    while (bantu->next != NULL && bantu->next->noBuku < no) {
        bantu = bantu->next;
    }

    // Sisipkan buku di tengah
    bukuBaru->next = bantu->next;
    bantu->next = bukuBaru;
}

void hapusList(int target) {
    buku* bantu = awal;
    buku* sebelumBantu = NULL;

    if (bantu != NULL && bantu->noBuku == target) {
        awal = bantu->next;
        free(bantu); // Menggunakan free() untuk menghapus memori yang dialokasikan oleh malloc
        return;
    }

    while (bantu != NULL && bantu->noBuku != target) {
        sebelumBantu = bantu;
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    sebelumBantu->next = bantu->next;
    free(bantu); // Menggunakan free() untuk menghapus memori yang dialokasikan oleh malloc
}

void cetakList() {
    cout << endl;
    buku* bantu = awal;
    while (bantu != NULL) {
        cout << "Nomor Buku: " << bantu->noBuku << endl;
        cout << "Judul: " << bantu->judul << endl;
        cout << "Penulis: " << bantu->penulis << endl;
        cout << "Penerbit: " << bantu->penerbit << endl;
        cout << "Tahun Terbit: " << bantu->tahunTerbit << endl;
        cout << "Jenis Buku: " << bantu->jenisBuku << endl << endl;
        bantu = bantu->next;
    }
}
