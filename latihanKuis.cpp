#include <iostream>
#include <string>
using namespace std;

struct menu {
    string namaMenu;
    float harga;
};

menu menuTmp[100];

struct pesanan {
    string namaPemesan;
    string metodePembayaran;
    menu dataMenu[100];
    int jumlahMenu;
    float totalHarga;
    pesanan* next;
};

pesanan *awal, *akhir;

void menuBeranda(), buatListbaru(),  sisipNode();
void cetak();
bool listKosong();

int main() {
    buatListbaru();
    menuBeranda();
    return 0;
}

void menuBeranda () {
    system("cls");
    int jawab;
    cout << "=============================" << endl;
    cout << "  restoran  " << endl;
    cout << "=============================" << endl;
    cout << "1. Input " << endl;
    cout << "2. Output " << endl;
    cout << "3. Keluar " << endl;
    cout << "=============================" << endl;
    cout << "Pilih menu : "; cin >> jawab;

     switch (jawab) {
            case 1:
                sisipNode();
                break;
            case 2:
                cetak();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                menuBeranda();
                
    }
}

void buatListbaru() {
    awal = NULL;
    akhir = NULL;
}

bool listKosong() {
    if (awal == NULL) {
        return true;
    }
    else {
        return false;
    }
        
}

void sisipNode() {
    system ("cls");
        pesanan* pesananBaru = new pesanan;

        string namaTmp;
        string metodeTmp;
        int jumlahTmp;
        float totalTmp = 0;
        
     
        cout << "=============================" << endl;
        cout << " Input " << endl;
        cout << "=============================" << endl;
        cin.ignore();
        cout << "Nama pemesan : "; getline(cin, namaTmp);
        cout << "Metode pembayaran : "; getline(cin, metodeTmp);
        cout << "Jumlah menu : "; cin >> jumlahTmp;
        for (int i = 0; i < jumlahTmp; i++) {
            cout << "Data menu ke " << i+1 << endl;
            cin.ignore();
            cout << "Nama menu : "; getline(cin, menuTmp[i].namaMenu );
            cout << "Harga : ";  cin >> menuTmp[i].harga; 
            totalTmp = totalTmp + menuTmp[i].harga;
        }
        cout << "total harga : " << totalTmp;

	
	if(listKosong()){
        pesananBaru -> namaPemesan = namaTmp;
        pesananBaru -> metodePembayaran = metodeTmp;
        pesananBaru -> jumlahMenu = jumlahTmp;
        for (int i = 0; i < jumlahTmp; i++) {
            pesananBaru -> dataMenu[i].namaMenu = menuTmp[i].namaMenu;
            pesananBaru -> dataMenu[i].harga = menuTmp[i].harga;
        }
        pesananBaru -> totalHarga = totalTmp;
		pesananBaru -> next = NULL;
		awal = pesananBaru;
		akhir = pesananBaru;
	}
	else if(awal -> next == NULL && akhir == NULL){
		pesananBaru -> namaPemesan = namaTmp;
        pesananBaru -> metodePembayaran = metodeTmp;
        pesananBaru -> jumlahMenu = jumlahTmp;
        for (int i = 0; i < jumlahTmp; i++) {
            pesananBaru -> dataMenu[i].namaMenu = menuTmp[i].namaMenu;
            pesananBaru -> dataMenu[i].harga = menuTmp[i].harga;
        }
        pesananBaru -> totalHarga = totalTmp;
        pesananBaru -> next = awal;
		awal -> next = pesananBaru;
	}
	else{
		pesananBaru -> namaPemesan = namaTmp;
        pesananBaru -> metodePembayaran = metodeTmp;
        pesananBaru -> jumlahMenu = jumlahTmp;
        for (int i = 0; i < jumlahTmp; i++) {
            pesananBaru -> dataMenu[i].namaMenu = menuTmp[i].namaMenu;
            pesananBaru -> dataMenu[i].harga = menuTmp[i].harga;
        }
        pesananBaru -> totalHarga = totalTmp;
        pesananBaru -> next = awal;
		akhir -> next = pesananBaru;
		akhir = pesananBaru; 
	}
    system("pause");
    menuBeranda();


}

void cetak() {
    system("cls");
    if (listKosong()) {
        cout << "Daftar pesanan kosong." << endl;
        return;
    }

    // Buat array dinamis untuk menyimpan pesanan
    pesanan** daftarPesanan = new pesanan*[100];
    pesanan* current = awal;
    int jumlahPesanan = 0;

    while (current != nullptr) {
        daftarPesanan[jumlahPesanan] = current;
        jumlahPesanan++;
        current = current->next;
    }

    // Sorting data pesanan berdasarkan total harga
    for (int i = 0; i < jumlahPesanan - 1; i++) {
        for (int j = 0; j < jumlahPesanan - i - 1; j++) {
            if (daftarPesanan[j]->totalHarga < daftarPesanan[j + 1]->totalHarga) {
                swap(daftarPesanan[j], daftarPesanan[j + 1]);
            }
        }
    }

    // Cetak data pesanan yang sudah diurutkan
    cout << "Daftar Pesanan (Total Harga Terbesar ke Terkecil):" << endl;
    for (int i = 0; i < jumlahPesanan; i++) {
        cout << "Pesanan #" << i + 1 << endl;
        cout << "Nama Pemesan: " << daftarPesanan[i]->namaPemesan << endl;
        cout << "Metode Pembayaran: " << daftarPesanan[i]->metodePembayaran << endl;
        cout << "Jumlah Menu: " << daftarPesanan[i]->jumlahMenu << endl;
        cout << "Total Harga: " << daftarPesanan[i]->totalHarga << endl;
        cout << "Menu yang Dipesan:" << endl;
        for (int j = 0; j < daftarPesanan[i]->jumlahMenu; j++) {
            cout << daftarPesanan[i]->dataMenu[j].namaMenu << ": " << daftarPesanan[i]->dataMenu[j].harga << endl;
        }
        cout << endl;
    }

    // Hapus array dinamis
    delete[] daftarPesanan;

    system("pause");
    menuBeranda();
}
