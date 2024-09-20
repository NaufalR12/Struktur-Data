#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Pasien {
    string nama;
    string keluhan;
    int umur;
};

struct Obat {
    int id;
    bool diambil;
};

struct HistoriObat {
    int id;
    bool diambil;
};

Pasien antrianPasien[20];
int rearPasien = -1, frontPasien = -1;

Obat antrianObat[20];
int topObat = -1;

HistoriObat historiObat[20];
int topHistoriObat = -1;

void enqueuePasien(Pasien p);
Pasien dequeuePasien();
void pushObat();
int findObatIndex(int id);
void displayHistoryObat();
void popObat();
int findHistoriObatIndex(int id);
int findObatIndex(int id);



int main() {
    srand(time(0)); 

    int pilih;

    do {
        system("cls");
        cout << "===========================================" << endl;
        cout << "||                  Menu                 ||" << endl;
        cout << "===========================================" << endl;
        cout << "|| 1. Ambil Nomor Antrian                ||" << endl;
        cout << "|| 2. Pemanggilan Antrian                ||" << endl;
        cout << "|| 3. Pengambilan Obat                   ||" << endl;
        cout << "|| 4. Histori Pengambilan Obat           ||" << endl;
        cout << "|| 5. Keluar                             ||" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih menu : "; cin >> pilih;

        cin.ignore(); 
        switch (pilih) {
            case 1: {
                system("cls");
                Pasien p;
                cout << "===========================================" << endl;
                cout << "||                Pendaftaran            ||" << endl;
                cout << "===========================================" << endl;
                cout << "Masukkan Nama: ";  getline(cin, p.nama);
                cout << "Masukkan Keluhan: "; getline(cin, p.keluhan);
                cout << "Masukkan Umur: "; cin >> p.umur;
                enqueuePasien(p);
                cout << endl;
                cout << "===========================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                Pasien p = dequeuePasien();
                if (frontPasien != -1) {
                    cout << "===========================================" << endl;
                    cout << "||          Pemanggilan Pasien           ||" << endl;
                    cout << "===========================================" << endl;
                    cout << "Nama: " << p.nama << endl;
                    cout << "Umur: " << p.umur << endl;
                    cout << "Keluhan : " << p.keluhan << endl;
                    cout << "===========================================" << endl;
                    pushObat();
                } 
                cout << "===========================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                popObat();
                break;
            }
            case 4: {
                system("cls");
                displayHistoryObat();
                break;
            }
            case 5:
                system("cls");
                cout << "===========================================" << endl;
                cout << "||            Program selesai            ||" << endl;
                cout << "===========================================" << endl;
                break;
            default:
                system("cls");
                cout << "===========================================" << endl;
                cout << "||Pilihan tidak valid. Silakan coba lagi ||" << endl;
                cout << "===========================================" << endl;
                cout << "===========================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
        }
    } while (pilih != 5);

    return 0;
}


void enqueuePasien(Pasien p) {
    if ((rearPasien + 1) % 20 == frontPasien) {
        cout << "===========================================" << endl;
        cout << "||Antrian penuh, mohon datang lain waktu ||" << endl;
        cout << "===========================================" << endl;

    } else {
        if (frontPasien == -1) {
            frontPasien = rearPasien = 0;
        } else {
            rearPasien = (rearPasien + 1) % 20;
        }
        antrianPasien[rearPasien] = p;
        cout << "===========================================" << endl;
        cout << "Nomor Antrian Anda: " << rearPasien + 1 << endl;
        cout << "===========================================" << endl;
    }
}

Pasien dequeuePasien() {
    Pasien p;
    if (frontPasien == -1) {
        cout << "===========================================" << endl;
        cout << "||           Antrian kosong!             ||" << endl;
        cout << "===========================================" << endl;
    } else {
        int indexLansia = -1;
        for (int i = frontPasien; i <= rearPasien; i++) {
            if (antrianPasien[i].umur > 65) {
                indexLansia = i;
                break;
            }
        }

        if (indexLansia != -1) {
            p = antrianPasien[indexLansia];
            for (int i = indexLansia; i < rearPasien; i++) {
                antrianPasien[i] = antrianPasien[i + 1];
            }
            rearPasien--;
            
        } else {
            p = antrianPasien[frontPasien];
            frontPasien = (frontPasien + 1) % 20;
        }
    }
    return p;
}

void pushObat() {
    if (topObat == 19) {
        cout << "===========================================" << endl;
        cout << "||         Antrian obat penuh!           ||" << endl;
        cout << "===========================================" << endl << endl; 
    } else {
        topObat++;
        antrianObat[topObat].id = rand() % 1000 + 1; 
        antrianObat[topObat].diambil = false;

        topHistoriObat++;
        historiObat[topHistoriObat].id = antrianObat[topObat].id;
        historiObat[topHistoriObat].diambil = false;

        cout << "ID Obat Anda: " << antrianObat[topObat].id << endl;
    }
}


int findObatIndex(int id) {
    for (int i = 0; i <= topObat; i++) {
        if (antrianObat[i].id == id) {
            return i;
        }
    }
    return -1; 
}

int findHistoriObatIndex(int id) {
    for (int i = 0; i <= topHistoriObat; i++) {
        if (historiObat[i].id == id) {
            return i;
        }
    }
    return -1; 
}

void popObat() {
    if (topObat == -1) {
        cout << "===========================================" << endl;
        cout << "||        Antrian obat kosong            ||" << endl;
        cout << "===========================================" << endl << endl;
        cout << "===========================================" << endl;
        cout << "Kembali ke menu : ";
        system("pause");
    } else {
        int idObat;
        cout << "===========================================" << endl;
        cout << "||            Pengambilan Obat           ||" << endl;
        cout << "===========================================" << endl;
        cout << "Masukkan ID Obat: "; cin >> idObat;
        cout << "===========================================" << endl << endl;

        int index = findObatIndex(idObat);
        if (index != -1) {
            cout << "Proses berhasil. Obat dengan ID " << antrianObat[index].id << " telah diambil." << endl;
            antrianObat[index].diambil = true;

            int indexHistori = findHistoriObatIndex(idObat);
            if (indexHistori != -1) {
                historiObat[indexHistori].diambil = true;
            }
        } else {
            cout << "===========================================" << endl;
            cout << "Obat dengan ID " << idObat << " tidak ditemukan." << endl;
            cout << "===========================================" << endl << endl;
            
        }
        cout << "===========================================" << endl;
        cout << "Kembali ke menu : ";
        system("pause");
    }
}

void displayHistoryObat() {
    if (topHistoriObat == -1) {
        cout << "===========================================" << endl;
        cout << "||    Histori pengambilan obat kosong.   ||" << endl;
        cout << "===========================================" << endl;
    } else {
        cout << "===========================================" << endl;
        cout << "||        Histori Pengambilan Obat       ||" << endl;
        cout << "===========================================" << endl;
        for (int i = topHistoriObat; i >= 0; i--) {
            
            cout << "ID Obat: " << historiObat[i].id << endl;
            cout << "Status: " << (historiObat[i].diambil ? "Sudah diambil" : "Belum diambil") << endl;
            cout << "===========================================" << endl;
        }
    }
    cout << "\n===========================================" << endl;
    cout << "Kembali ke menu : ";
    system("pause");
}
