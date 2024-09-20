#include <iostream>
#include <string>
using namespace std;

struct data {
	int noBuku;
    string judul;
    string penulis;
    string penerbit;
    int tahunTerbit;
    string jenisBuku;
	};
	
struct buku {
    data info;
    buku* next;
};


buku* awal;
buku* akhir;

void buatListBaru();
void input();
void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void sisipTengah(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void sisipBelakang(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void cetakList();

int main() {
    buatListBaru();
    

    cetakList();

    buku* bantu = awal;
    while (bantu != NULL) {
        buku* hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    return 0;
}

void input() {
int jumlahBuku;
    cout << "Masukkan jumlah buku yang ingin Anda tambahkan: ";
    cin >> jumlahBuku;
    cin.ignore();

    for (int i = 0; i < jumlahBuku; i++) {
        int no;
        string judul, penulis, penerbit, jenis;
        int tahun;

        cout << "Masukkan data buku ke-" << i + 1 << endl;
        cout << "Nomor Buku: ";
        cin >> no;
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

        sisipDepan(no, judul, penulis, penerbit, tahun, jenis);
    }
}

void buatListBaru() {
    awal = NULL;
    akhir = NULL;
}

void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = new buku;
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

void sisipTengah(int no, string judul, string penulis, string penerbit, int tahun, string jenis, int posisi) {
    buku* bukuBaru = new buku;
    bukuBaru->noBuku = no;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->penerbit = penerbit;
    bukuBaru->tahunTerbit = tahun;
    bukuBaru->jenisBuku = jenis;
    bukuBaru->next = NULL;

    if (posisi == 1) {
        bukuBaru->next = awal;
        awal = bukuBaru;
    } else {
        buku* bantu = awal;
        int count = 1;
        while (count < posisi - 1 && bantu->next != NULL) {
            bantu = bantu->next;
            count++;
        }
        bukuBaru->next = bantu->next;
        bantu->next = bukuBaru;
    }
}

void sisipBelakang(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = new buku;
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
        akhir->next = bukuBaru;
        akhir = bukuBaru;
    }
}

void hapusList(int target) {
    buku* bantu = awal;
    buku* sebelumBantu = NULL;

    if (bantu != NULL && bantu->noBuku == target) {
        awal = bantu->next;
        delete bantu;
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
    delete bantu;
}

void cetakList() {
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
