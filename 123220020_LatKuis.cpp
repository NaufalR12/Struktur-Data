#include <iostream>
#include <string>
#include <malloc.h>
#include <iomanip>

using namespace std;
void listbaru(), menuawal();
void input(), hapus();
void tampil();
bool  listkosong();
char kembali='y', ulang='y';

struct menu{
    string nama;
    int harga;
};
menu mn[1000];

struct pesanan{
    menu datamenu[1000];
    int id;
    string namapes;
    string pembayaran;
    int jumlah;
    int tb;
    pesanan* next;
};
pesanan *awal, *ekor;



int main() {
    listbaru();
    menuawal();
}

void menuawal(){
    int pilih;
        while (toupper(ulang)=='Y') {
        system("cls");
        cout<<"\n\t     History Pesanan Harian"<<endl;
        cout<<"\t================================"<<endl;
        cout<<"1. Input data"<<endl;
        cout<<"2. Lihat data"<<endl;
        cout<<"3. Hapus data"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<"Pilih : "; cin>>pilih;
        switch(pilih){
            case 1:
                    input();
                    break;
            case 2:
                    tampil();
                    break;
            case 3:
                    hapus();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    cout<< "Inputan ada tidak sesuai!";
                    system("pause");
        }
        cout<<"apakah ingin ulang ke menu awal? y/n : ";
        cin>>ulang;
    }
}

void listbaru() {
    awal = NULL;
    ekor = NULL;
}

bool listkosong(){
	if(awal == NULL)
	return true;
	else
	return false;
}

void input(){
        system("cls");
        pesanan* PB = new pesanan;
        string namamn;
        string metode;
        int jumlahmn, idmn, totalmn = 0;
        cout<<"\n\t        Input data"<<endl;
        cout<<"\t==========================="<<endl;
        cout<<"ID pesanan        : "; cin >> idmn ;
        cout<<"Nama pemesan      : ";
        cin.ignore();
        getline(cin, namamn);
        cout<<"Metode pembayaran : "; getline(cin, metode);
        cout<<"Jumlah menu       : "; cin >> jumlahmn;
        for (int i = 0; i < jumlahmn; i++) {
            cout<<"\n\t   Menu " << i+1 << endl;
            cout<<"\tNama menu : ";
            cin.ignore();
            getline(cin, mn[i].nama );
            cout<<"\tHarga     : ";
            cin >> mn[i].harga;
            totalmn = totalmn + mn[i].harga;
        }
        cout<<"\ntotal harga       : " << totalmn << endl;

        PB->id = idmn;
        PB->namapes = namamn;
        PB->pembayaran = metode;
        PB->jumlah = jumlahmn;
        for (int i = 0; i < PB -> jumlah; i++) {
            PB->datamenu[i].nama = mn[i].nama;
            PB->datamenu[i].harga = mn[i].harga;
        }
        PB->tb = totalmn;
        PB->next = NULL;

        if (listkosong()||totalmn >= awal->tb) {
        PB->next = awal;
        awal = PB;
        } else {
        pesanan* bantu = awal;
        pesanan* sebelumBantu = NULL;
        while (bantu != NULL && totalmn < bantu->tb) {
            sebelumBantu = bantu;
            bantu = bantu->next;
        }
        sebelumBantu->next = PB;
        PB->next = bantu;
    }

}

void tampil() {

    pesanan *bantu;
    bantu= awal;

    if (listkosong()) {
		cout << "list masih kosong" << endl;
	}

        while (bantu!=NULL) {
            system("cls");
            cout << endl;
            cout << "ID pesanan        : " << bantu->id << endl;
            cout << "Nama pemesan      : " << bantu->namapes << endl;
            cout << "Metode pembayaran : " << bantu->pembayaran << endl;
            cout << "Jumlah menu       : " << bantu -> jumlah << endl;
            for (int i = 0; i < bantu -> jumlah; i++) {
                cout << "Data menu ke " << i+1 << "    : " << bantu -> datamenu[i].nama << " - " << bantu -> datamenu[i].harga << endl;
            }
            cout << "Total harga       : " << bantu -> tb << endl << endl;
            bantu = bantu -> next;
            cout << endl;
        }

}

void hapus() {
	pesanan *hapus, *bantu;

	int IH;
	cout << "Masukkan id : "; cin >> IH;

	if (listkosong()) {
		cout << "list masih kosong" << endl;
	} else if (awal->id == IH) {
		hapus = awal;
		awal = awal->next; // Perbaikan 1: Ganti hapus->next menjadi awal->next
		delete hapus; // Perbaikan 2: Gunakan delete untuk menghapus alamat memori
		cout << "berhasil dihapus" << endl;
	} else {
		bantu = awal;
		while (bantu->next != NULL && IH != bantu->next->id) { // Perbaikan 3: Ganti bantu->next->next menjadi bantu->next
			bantu = bantu->next;
		}
		if (bantu->next != NULL && IH == bantu->next->id) { // Perbaikan 4: Tambahkan pengecekan bantu->next != NULL
			hapus = bantu->next;
			bantu->next = hapus->next;
			if (hapus == ekor) {
				ekor = bantu;
			}
			delete hapus; // Perbaikan 5: Gunakan delete untuk menghapus alamat memori
			cout << "berhasil dihapus" << endl;
		} else {
			cout << "Data tidak ditemukan " << endl;
		}
	}
	cout << endl;
}

