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

struct TypeQueue {
    int depan, belakang;
    Pasien elemen[20];
};

TypeQueue queuePasien;
Obat antrianObat[20];
int topObat = -1;
HistoriObat historiObat[20];
int topHistoriObat = -1;

void buatQueue(TypeQueue &Q);
int queueKosong(TypeQueue Q);
int queuePenuh(TypeQueue Q);
void enqueuePasien(TypeQueue &Q, Pasien p);
Pasien dequeuePasien(TypeQueue &Q);
void pushObat();
int findObatIndex(int id);
void displayHistoryObat();
void popObat();
int findHistoriObatIndex(int id);

int main() {
    srand(time(0)); 

    int pilih;

    buatQueue(queuePasien);

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
                enqueuePasien(queuePasien, p);
                cout << endl;
                cout << "===========================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                Pasien p = dequeuePasien(queuePasien);
                if (!queueKosong(queuePasien)) {
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

void buatQueue(TypeQueue &Q) {
    Q.depan = 0;
    Q.belakang = 0;
}

int queueKosong(TypeQueue Q) {
    return Q.depan == Q.belakang;
}

int queuePenuh(TypeQueue Q) {
    return (Q.belakang + 1) % 20 == Q.depan;
}

void enqueuePasien(TypeQueue &Q, Pasien p) {
    if (queuePenuh(Q)) {
        cout << "===========================================" << endl;
        cout << "||Antrian penuh, mohon datang lain waktu ||" << endl;
        cout << "===========================================" << endl;
    } else {
        Q.belakang = (Q.belakang + 1) % 20;
        Q.elemen[Q.belakang] = p;
        cout << "===========================================" << endl;
        cout << "Nomor Antrian Anda: " << Q.belakang + 1 << endl;
        cout << "===========================================" << endl;
    }
}

Pasien dequeuePasien(TypeQueue &Q) {
    Pasien p;
    if (queueKosong(Q)) {
        cout << "===========================================" << endl;
        cout << "||           Antrian kosong!             ||" << endl;
        cout << "===========================================" << endl;
    } else {
        p = Q.elemen[(Q.depan + 1) % 20];
        Q.depan = (Q.depan + 1) % 20;
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
