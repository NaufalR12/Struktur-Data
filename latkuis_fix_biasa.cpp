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
void cetak(),hapus();
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
    cout << "3. Hapus " << endl;
    cout << "4. Keluar " << endl;
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
                hapus();
                break;
            case 4:
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
        cout << "total harga : " << totalTmp << endl;


    if(listKosong()){
		pesananBaru->namaPemesan = namaTmp;
		pesananBaru->metodePembayaran = metodeTmp;
		pesananBaru->jumlahMenu = jumlahTmp;
		for (int i = 0; i < pesananBaru -> jumlahMenu; i++) {
			pesananBaru->dataMenu[i].namaMenu = menuTmp[i].namaMenu;
			pesananBaru->dataMenu[i].harga = menuTmp[i].harga;
		}
		pesananBaru->totalHarga = totalTmp;
		pesananBaru -> next = NULL;
		awal = pesananBaru;
		akhir = pesananBaru;
	}
	else if(awal -> next == NULL && akhir == NULL){
		pesananBaru->namaPemesan = namaTmp;
		pesananBaru->metodePembayaran = metodeTmp;
		pesananBaru->jumlahMenu = jumlahTmp;
		for (int i = 0; i < pesananBaru -> jumlahMenu; i++) {
			pesananBaru->dataMenu[i].namaMenu = menuTmp[i].namaMenu;
			pesananBaru->dataMenu[i].harga = menuTmp[i].harga;
		}
		pesananBaru->totalHarga = totalTmp;
        pesananBaru -> next = awal;
		awal -> next = pesananBaru;
	}
	else{
		pesananBaru->namaPemesan = namaTmp;
		pesananBaru->metodePembayaran = metodeTmp;
		pesananBaru->jumlahMenu = jumlahTmp;
		for (int i = 0; i < pesananBaru -> jumlahMenu; i++) {
			pesananBaru->dataMenu[i].namaMenu = menuTmp[i].namaMenu;
			pesananBaru->dataMenu[i].harga = menuTmp[i].harga;
		}
		pesananBaru->totalHarga = totalTmp;
        pesananBaru -> next = awal;
		akhir -> next = pesananBaru;
		akhir = pesananBaru; 
	}
    
    system("pause");
    menuBeranda();


}

void cetak() {
    system("cls");
    pesanan *bantu;
    bantu = awal;
    if (listKosong()) {
		cout << "list masih kosong" << endl;
	}
    do {
        cout << "Nama pemesan : " << bantu->namaPemesan << endl;
        cout << "Metode pembayaran : " << bantu->metodePembayaran << endl;
        cout << "Jumlah menu : " << bantu -> jumlahMenu << endl;
        for (int i = 0; i < bantu -> jumlahMenu; i++) {
            cout << "Data menu ke " << i+1 << endl;
            cout << "Nama menu : " << bantu -> dataMenu[i].namaMenu << endl;
            cout << "Harga : " << bantu -> dataMenu[i].harga << endl;
        }
        cout << "Total harga : " << bantu -> totalHarga << endl << endl;
        bantu = bantu -> next;
        cout << endl;
    }while (bantu!=awal); 
    
    system("pause");
    menuBeranda();
}

void hapus() {
	pesanan *hapus, *bantu;
	
	string namaHapus;
	cin.ignore();
	cout << "Masukkan nama : "; getline(cin, namaHapus);
	
	if (listKosong()) {
		cout << "list masih kosong" << endl;
	} else if (awal->namaPemesan == namaHapus) {
		hapus = awal;
		awal = hapus->next;
		free(hapus);
		cout << "berhasil dihapus" << endl;
	} else {
		bantu = awal;
		while (bantu->next->next != NULL && namaHapus != bantu->next->namaPemesan)
			bantu = bantu -> next;
		if (namaHapus == bantu->next->namaPemesan) {
			hapus = bantu->next;
			if (hapus == akhir) {
				akhir = bantu;
				akhir->next = NULL;
			} else {
				bantu->next = hapus->next;
				
			}
			free(hapus);
			cout << "berhasil dihapus" << endl;
		} else
			cout << "Data tidak ditemukan " << endl;
	}
	cout << endl;
	system("pause");
    menuBeranda();
	
}
