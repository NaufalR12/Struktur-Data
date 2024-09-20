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
        float totalTmp;
        
        int jumlahMenu;
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

	
	pesananBaru->namaPemesan = namaTmp;
    pesananBaru->metodePembayaran = metodeTmp;
    pesananBaru->jumlahMenu = jumlahTmp;
    for (int i = 0; i < pesananBaru -> jumlahMenu; i++) {
        pesananBaru->dataMenu[i].namaMenu = menuTmp[i].namaMenu;
        pesananBaru->dataMenu[i].harga = menuTmp[i].harga;
    }
    pesananBaru->totalHarga = totalTmp; // Set totalHarga ke totalTmp
    pesananBaru->next = NULL;

    // Sisipkan pesanan baru sesuai urutan total harga
    if (listKosong() || totalTmp >= awal->totalHarga) {
        pesananBaru->next = awal;
        awal = pesananBaru;
    } else {
        pesanan* current = awal;
        pesanan* prev = NULL;
        while (current != NULL && totalTmp < current->totalHarga) {
            prev = current;
            current = current->next;
        }
        prev->next = pesananBaru;
        pesananBaru->next = current;
    }

    system("pause");
    menuBeranda();
}


void cetak() {
    system("cls");
    pesanan *bantu;
    bantu = awal;
    do {
        cout << "Nama pemesan : " << bantu->namaPemesan;
        cout << "Metode pembayaran : " << bantu->metodePembayaran;
        cout << "Jumlah menu : " << bantu -> jumlahMenu;
        for (int i = 0; i < bantu -> jumlahMenu; i++) {
            cout << "Data menu ke " << i+1 << endl;
            cout << "Nama menu : " << bantu -> dataMenu[i].namaMenu;
            cout << "Harga : " << bantu -> dataMenu[i].harga;
        }
        cout << "Total harga : " << bantu -> totalHarga;
        bantu = bantu -> next;
        cout << endl;
    } while(bantu!= awal);
    
    system("pause");
    menuBeranda();
}

