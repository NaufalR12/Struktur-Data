#include <iostream>
#include <string> // Menggunakan <string> untuk tipe data string
using namespace std;

typedef struct {
    string nama;
    int nilai;
} infodata;

infodata dataawal, *akhirnilai;

void penukaran_data() {
    akhirnilai = new infodata; // Menggunakan dynamic memory allocation untuk alokasi memori
    akhirnilai->nama = dataawal.nama; // Mengkopi nilai nama dari dataawal
    akhirnilai->nilai = 85;
}

int main() {
    dataawal.nama = "naufal"; // Mengisi nilai dengan tipe data string
    dataawal.nilai = 70;

    cout << "=====================================" << endl << endl;
    cout << "nama : " << dataawal.nama << endl;
    cout << "nilai : " << dataawal.nilai << endl << endl;
    cout << "=====================================" << endl << endl;

    penukaran_data();

    cout << "nama : " << akhirnilai->nama << endl;
    cout << "nilai: " << akhirnilai->nilai << endl << endl;
    cout << "=====================================" << endl << endl;

    delete akhirnilai; // Menggunakan operator delete untuk menghapus memori yang dialokasikan

    return 0;
}
