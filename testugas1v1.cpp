#include <iostream>
#include <malloc.h>
#include <string>

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

buku *awal, *akhir;

void buatList();
void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void cetakList();

int main() {
	int jumlahBuku;
	void buatList();
    cout << "Masukkan jumlah buku yang ingin Anda tambahkan: ";
    cin >> jumlahBuku;

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
        cout << endl;

        sisipDepan(no, judul, penulis, penerbit, tahun, jenis);
    }

    cetakList();

    return 0;
}

void buatList() {
	awal = NULL;
	akhir = NULL;
}

void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku *bukuBaru;
    bukuBaru = (buku*) malloc(sizeof(buku));
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

void cetakList() {
    buku *bantu;
    bantu = awal;
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
