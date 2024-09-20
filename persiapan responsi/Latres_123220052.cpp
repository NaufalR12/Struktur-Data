#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

struct Pasien {
    string nama;
    string keluhan;
    int umur;
    int nomorAntrian;
    int idObat;
    string statusObat;
};

class Klinik {
private:
    vector<Pasien> antrianPasien;
    vector<Pasien> riwayatPengambilanObat;

public:
    void ambilNomor();
    void panggilAntrian();
    void IdObat(Pasien& pasien);
    void tampilkanPasien(const Pasien& pasien);
    void ambilObat();
    void riwayatPengambilan();
};



int main() {
    Klinik klinik;
    int jawab;

    while (jawab != 5) {
        system("cls");
        cout << "=======================================" << endl;
        cout << "||              Menu Utama           ||" << endl;
        cout << "=======================================" << endl;
        cout << "|| 1. Ambil Nomor                    ||" << endl;
        cout << "|| 2. Pemanggilan Antrian            ||" << endl;
        cout << "|| 3. Pengambilan Obat               ||" << endl;
        cout << "|| 4. Riwayat Pengambilan Obat       ||" << endl;
        cout << "|| 5. Exit                           ||" << endl;
        cout << "=======================================" << endl;
        cout << "Pilih menu: "; cin >> jawab;

        switch (jawab) {
            case 1:
                klinik.ambilNomor();
                break;
            case 2:
                klinik.panggilAntrian();
                break;
            case 3:
                klinik.ambilObat();
                break;
            case 4:
                klinik.riwayatPengambilan();
                break;
            case 5:
                cout << "=======================================" << endl;
                cout << "||         Program Selesai!          ||" << endl;
                cout << "=======================================" << endl;
                cout << "Kembali ke menu: "; 
                system("pause");
                break;
            default:
                cout << "=======================================" << endl;
                cout << "||        Pilihan tidak valid!       ||" << endl;
                cout << "=======================================" << endl;
                cout << "=======================================" << endl;
                cout << "Kembali ke menu: "; 
                system("pause");
        }
    } ;

    return 0;
}

void Klinik::ambilNomor() {
    system("cls");
    Pasien pasien;
    cout << "=======================================" << endl;
    cout << "||           Ambil Antrian           ||" << endl;
    cout << "=======================================" << endl;
    cin.ignore();
    cout << "Nama: "; getline(cin, pasien.nama);
    cout << "Keluhan: "; getline(cin, pasien.keluhan);
    cout << "Umur: "; cin >> pasien.umur;

    pasien.nomorAntrian = antrianPasien.size() + 1;

    cout << "Nomor Antrian: " << pasien.nomorAntrian << endl;

    antrianPasien.push_back(pasien);
    cout << "=======================================" << endl;
    cout << "Kembali ke menu: "; 
    system("pause");
}

void Klinik::panggilAntrian() {
    system("cls");
    if (!antrianPasien.empty()) {
        int indeksLansia = -1;

        for (int i = 0; i < antrianPasien.size(); ++i) {
            if (antrianPasien[i].umur > 65) {
                indeksLansia = i;
                break;
            }
        }

        if (indeksLansia != -1) {
            Pasien lansia = antrianPasien[indeksLansia];
            antrianPasien.erase(antrianPasien.begin() + indeksLansia);
            IdObat(lansia);
            tampilkanPasien(lansia);
        } else {
            Pasien pasienBerikutnya = antrianPasien.front();
            antrianPasien.erase(antrianPasien.begin());
            IdObat(pasienBerikutnya);
            tampilkanPasien(pasienBerikutnya);
        }
    } else {
        cout << "=======================================" << endl;
        cout << "||         Antrian Kosong!           ||" << endl;
        cout << "=======================================" << endl;
        cout << "Kembali ke menu: "; 
        system("pause");
    }
}

void Klinik::IdObat(Pasien& pasien) {
    srand(time(0));
    pasien.idObat = rand() % 1000 + 1;
    riwayatPengambilanObat.push_back(pasien);
}

void Klinik::tampilkanPasien(const Pasien& pasien) {
    cout << "=======================================" << endl;
    cout << "||        Pemanggilan Pasien         ||" << endl;
    cout << "=======================================" << endl;
    cout << "No Antrian: " << pasien.nomorAntrian << endl;
    cout << "Nama: " << pasien.nama << endl;
    cout << "Keluhan: " << pasien.keluhan << endl; 
    cout << "Umur: " << pasien.umur << endl;
    cout << "Id obat: " << pasien.idObat << endl;
    cout << "=======================================" << endl;
    cout << "Kembali ke menu: "; 
    system("pause");
}

void Klinik::ambilObat() {
    if (!riwayatPengambilanObat.empty()) {
        system("cls");
        int idObat;
        cout << "=======================================" << endl;
        cout << "||          Pengambilan Obat         ||" << endl;
        cout << "=======================================" << endl;
        cout << "Masukkan id obat: "; cin >> idObat;

        for (Pasien& pasien : riwayatPengambilanObat) {
            if (pasien.idObat == idObat) {
                if (pasien.statusObat.empty()) {
                    
                    pasien.statusObat = "Obat sudah diambil";
                    cout << "\n=======================================" << endl;
                    cout << "||     Proses transaksi berhasil!    ||" << endl;
                    cout << "=======================================" << endl;
                    cout << "Obat dengan Id:  " << pasien.idObat << " telah diambil!." << endl;
                } else {
                    cout << "\n=======================================" << endl;
                    cout << "||   Obat sudah diambil sebelumnya!  ||" << endl;
                    cout << "=======================================" << endl;
                }
                cout << "=======================================" << endl;
                cout << "Kembali ke menu: "; 
                system("pause");
                return;
            }
        }
        cout << "=======================================" << endl;
        cout << "||        ID Obat tidak valid!       ||" << endl;
        cout << "=======================================" << endl;
    } else {
        cout << "=======================================" << endl;
        cout << "||           Riwayat Kosong          ||" << endl;
        cout << "=======================================" << endl;
    }
    cout << "=======================================" << endl;
    cout << "Kembali ke menu: "; 
    system("pause");
}

void Klinik::riwayatPengambilan() {
    system("cls");
    cout << "=======================================" << endl;
    cout << "||      Riwayat Pengambilan Obat     ||" << endl;
    cout << "=======================================" << endl << endl;
    for (const Pasien& pasien : riwayatPengambilanObat) {
        cout << "=======================================" << endl;
        cout << "Id obat: " << pasien.idObat << endl;
        cout << "Nama pasien: " << pasien.nama << endl;
        cout << "Status: " << (pasien.statusObat.empty() ? "Belum diambil" : pasien.statusObat) << endl;
        cout << "=======================================" << endl << endl;
    }
    cout << "=======================================" << endl;
    cout << "Kembali ke menu: "; 
    system("pause");
}