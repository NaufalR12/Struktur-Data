#include <iostream>
#include <string>

using namespace std;

struct buku {
    int noBuku;
    string judul;
    string penulis;
    string penerbit;
    int tahunTerbit;
    string jenisBuku;
};


struct elmn {    
    buku info;
    int next;
};

elmn elemen[100];

elmn tmp;

int awallist = -1; 
int akhirlist = -1; 
int listkosong = 0; 

void buatListBaru();
void menu();
void hapusDepan(int target);
void hapusTengah(int target);
void hapusBelakang(int target);
void cetakList();
void sisipDepan(elmn tmp);
void sisipTengah(elmn tmp);
void sisipBelakang(elmn tmp);

int main() {
    buatListBaru();
    menu();
    return 0;
}

void menu() {
    system("cls");
    int jumlahBuku;
    int jawab;
    cout << "\n=======================================" << endl;
    cout << "              Perpustakaan             " << endl;
    cout << "=======================================" << endl;
    cout << "1. Sisip Depan                   " << endl;
    cout << "2. Sisip Tengah                  " << endl;
    cout << "3. Sisip Belakang                " << endl;
    cout << "4. Hapus Node                    " << endl;
    cout << "5. Tampilkan Data                " << endl;
    cout << "6. Keluar                        " << endl;
    cout << "=======================================" << endl;
    cout << "Pilih menu : "; cin >> jawab;

    switch (jawab) {
    case 1:
        system("cls");
        cout << "=======================================" << endl;
        cout << "              Sisip Depan              " << endl;
        cout << "=======================================" << endl;

        cout << "Jumlah buku yang ingin ditambahkan: "; cin >> jumlahBuku;
        cin.ignore();
        cout << endl;

		cout << "=======================================" << endl;
		cout << "    Data yang input lebih dulu akan    " << endl;
		cout << "         disisipkan lebih dulu.        " << endl;
		cout << "=======================================" << endl << endl;

        for (int i = 0; i < jumlahBuku; i++) {
            cout << "Masukkan data buku ke-" << i + 1 << endl;
            cout << "Nomor Buku: "; cin >> tmp.info.noBuku;
            cin.ignore();
            cout << "Judul: ";
            getline(cin, tmp.info.judul);
            cout << "Penulis: ";
            getline(cin, tmp.info.penulis);
            cout << "Penerbit: ";
            getline(cin, tmp.info.penerbit);
            cout << "Tahun Terbit: ";
            cin >> tmp.info.tahunTerbit;
            cin.ignore();
            cout << "Jenis Buku: ";
            getline(cin, tmp.info.jenisBuku);
            cout << endl;
            sisipDepan(tmp);
        }
        cout << "=======================================" << endl;
        cout << "Kembali ke menu: ";
        system("pause");
        menu();
        break;

    case 2:
        system("cls");
        cout << "=======================================" << endl;
        cout << "             Sisip Tengah              " << endl;
        cout << "=======================================" << endl;

        cout << "Jumlah buku yang ingin ditambahkan: "; cin >> jumlahBuku;
        cin.ignore();
        cout << endl;
		
		cout << "=======================================" << endl;
		cout << "    Data yang input lebih dulu akan    " << endl;
		cout << "         disisipkan lebih dulu.        " << endl;
		cout << "=======================================" << endl << endl;
		
        for (int i = 0; i < jumlahBuku; i++) {
            cout << "Masukkan data buku ke-" << i + 1 << endl;
            cout << "Nomor Buku: "; cin >> tmp.info.noBuku;
            cin.ignore();
            cout << "Judul: ";
            getline(cin, tmp.info.judul);
            cout << "Penulis: ";
            getline(cin, tmp.info.penulis);
            cout << "Penerbit: ";
            getline(cin, tmp.info.penerbit);
            cout << "Tahun Terbit: ";
            cin >> tmp.info.tahunTerbit;
            cin.ignore();
            cout << "Jenis Buku: ";
            getline(cin, tmp.info.jenisBuku);
            cout << endl;
            sisipTengah(tmp);
        }
        cout << "=======================================" << endl;
        cout << "Kembali ke menu: ";
        system("pause");
        menu();
        break;

    case 3:
        system("cls");
        cout << "=======================================" << endl;
        cout << "             Sisip Belakang            " << endl;
        cout << "=======================================" << endl;

        cout << "Jumlah buku yang ingin ditambahkan: "; cin >> jumlahBuku;
        cin.ignore();
        cout << endl;

		cout << "=======================================" << endl;
		cout << "    Data yang input lebih dulu akan    " << endl;
		cout << "         disisipkan lebih dulu.        " << endl;
		cout << "=======================================" << endl << endl;

        for (int i = 0; i < jumlahBuku; i++) {
            cout << "Masukkan data buku ke-" << i + 1 << endl;
            cout << "Nomor Buku: "; cin >> tmp.info.noBuku;
            cin.ignore();
            cout << "Judul: ";
            getline(cin, tmp.info.judul);
            cout << "Penulis: ";
            getline(cin, tmp.info.penulis);
            cout << "Penerbit: ";
            getline(cin, tmp.info.penerbit);
            cout << "Tahun Terbit: ";
            cin >> tmp.info.tahunTerbit;
            cin.ignore();
            cout << "Jenis Buku: ";
            getline(cin, tmp.info.jenisBuku);
            cout << endl;
            sisipBelakang(tmp);
        }
        cout << "=======================================" << endl;
        cout << "Kembali ke menu: ";
        system("pause");
        menu();
        break;

    case 4:
        system("cls");
        int noHapus,pilih;
        cout << "=======================================" << endl;
        cout << "               Hapus Buku              " << endl;
        cout << "=======================================" << endl;
        cout << "No buku yang ingin dihapus : "; cin >> noHapus;
		cout << "=======================================" << endl;
        cout << "1. Hapus list di depan" << endl;
        cout << "2. Hapus list di tengah" << endl;
        cout << "3. Hapus list di belakang" << endl;
		cout << "=======================================" << endl;
        cout << "Pilih : "; cin >> pilih;
        
        switch (pilih) {
			case 1 : hapusDepan(noHapus); break;
			case 2 : hapusTengah(noHapus); break;
			case 3 : hapusBelakang(noHapus); break;
			default :   
				cout << "=======================================" << endl;
				cout << "  Menu yang anda pilih tidak tersedia! " << endl;
				cout << "=======================================" << endl;
				cout << "=======================================" << endl;
				cout << "Kembali ke menu: ";
				system("pause");
				menu();
			}
        
        cout << "=======================================" << endl;
        cout << "Kembali ke menu: ";
        system("pause");
        menu();
        break;
    case 5:
        system("cls");
        if (awallist == -1) {
			
            cout << "=======================================" << endl;
            cout << "      Tidak ada data buku tersedia     " << endl;
            cout << "=======================================" << endl;
        }
        else {
            cetakList();
        }
        cout << "=======================================" << endl;
        cout << "Kembali ke menu: ";
        system("pause");
        menu();
        break;
    case 6:
        system("cls");
        cout << "=======================================" << endl;
        cout << "||           TERIMA KASIH            ||" << endl;
        cout << "=======================================" << endl;
        exit(0);
    default:
        cout << "=======================================" << endl;
        cout << "  Menu yang anda pilih tidak tersedia! " << endl;
        cout << "=======================================" << endl;
        cout << "=======================================" << endl;
        cout << "Kembali ke menu: ";
        system("pause");
        menu();
    }

}

void buatListBaru() {
    for (int i = 0; i < 100; i++) {
        elemen[i].next = i + 1;
    }
    elemen[99].next = -1;
    listkosong = 0;
    awallist = -1;
    akhirlist = -1;
}

void sisipDepan(elmn tmp) {
    if (listkosong == -1) {   
        cout << "=======================================" << endl;
        cout << "       Memori penuh, sisip gagal!      " << endl;
        cout << "=======================================" << endl;
        return;
    }

    int listbaru = listkosong;
    listkosong = elemen[listkosong].next;

    elemen[listbaru].info.noBuku = tmp.info.noBuku;
    elemen[listbaru].info.judul = tmp.info.judul;
    elemen[listbaru].info.penulis = tmp.info.penulis;
    elemen[listbaru].info.penerbit = tmp.info.penerbit;
    elemen[listbaru].info.tahunTerbit = tmp.info.tahunTerbit;
    elemen[listbaru].info.jenisBuku = tmp.info.jenisBuku;
    elemen[listbaru].next = -1;

    if (awallist == -1) {
        awallist = listbaru;
        akhirlist = listbaru;
    }
    else {
        elemen[listbaru].next = awallist;
        awallist = listbaru;
    }

    cout << "=======================================" << endl;
    cout << "||        Berhasil di sisip          ||" << endl;
    cout << "=======================================\n" << endl;
}

void sisipTengah(elmn tmp) {
    if (listkosong == -1) {
        cout << "=======================================" << endl;
        cout << "       Memori penuh, sisip gagal!      " << endl;
        cout << "=======================================" << endl;
        return;
    }

    int listbaru = listkosong;
    listkosong = elemen[listkosong].next;

    elemen[listbaru].info.noBuku = tmp.info.noBuku;
    elemen[listbaru].info.judul = tmp.info.judul;
    elemen[listbaru].info.penulis = tmp.info.penulis;
    elemen[listbaru].info.penerbit = tmp.info.penerbit;
    elemen[listbaru].info.tahunTerbit = tmp.info.tahunTerbit;
    elemen[listbaru].info.jenisBuku = tmp.info.jenisBuku;
    elemen[listbaru].next = -1;

    if (awallist == -1) {
        awallist = listbaru;
        akhirlist = listbaru;
    }
    else if (elemen[listbaru].info.noBuku < elemen[awallist].info.noBuku) {
        elemen[listbaru].next = awallist;
        awallist = listbaru;
    }
    else if (elemen[listbaru].info.noBuku > elemen[akhirlist].info.noBuku) {
        elemen[akhirlist].next = listbaru;
        akhirlist = listbaru;
    }
    else {
        int bantu = awallist;
        while (elemen[bantu].next != -1 && elemen[elemen[bantu].next].info.noBuku < elemen[listbaru].info.noBuku) {
            bantu = elemen[bantu].next;
        }
        elemen[listbaru].next = elemen[bantu].next;
        elemen[bantu].next = listbaru;
    }

    cout << "=======================================" << endl;
    cout << "||        Berhasil di sisip          ||" << endl;
    cout << "=======================================\n" << endl;
}

void sisipBelakang(elmn tmp) {
    if (listkosong == -1) {
        cout << "=======================================" << endl;
        cout << "       Memori penuh, sisip gagal!      " << endl;
        cout << "=======================================" << endl;
        return;
    }

    int listbaru = listkosong;
    listkosong = elemen[listkosong].next;

    elemen[listbaru].info.noBuku = tmp.info.noBuku;
    elemen[listbaru].info.judul = tmp.info.judul;
    elemen[listbaru].info.penulis = tmp.info.penulis;
    elemen[listbaru].info.penerbit = tmp.info.penerbit;
    elemen[listbaru].info.tahunTerbit = tmp.info.tahunTerbit;
    elemen[listbaru].info.jenisBuku = tmp.info.jenisBuku;
    elemen[listbaru].next = -1;

    if (awallist == -1) {
        awallist = listbaru;
        akhirlist = listbaru;
    }
    else {
        elemen[akhirlist].next = listbaru;
        akhirlist = listbaru;
    }

    cout << "=======================================" << endl;
    cout << "||        Berhasil di sisip          ||" << endl;
    cout << "=======================================\n" << endl;
}



void hapusDepan(int target) {
    if (awallist == -1) {
        cout << "=======================================" << endl;
        cout << "      Tidak ada data buku tersedia     " << endl;
        cout << "=======================================" << endl;
        return;
    }


    if (elemen[awallist].info.noBuku == target) {
		int indeksHapus = awallist;
		awallist = elemen[indeksHapus].next;

		elemen[indeksHapus].next = listkosong;
		listkosong = indeksHapus;

		cout << "=======================================" << endl;
		cout << "    Data pertama berhasil dihapus     " << endl;
		cout << "=======================================" << endl;
	} else {
        cout << "=======================================" << endl;
        cout << "    Hanya bisa menghapus di depan      " << endl;
        cout << "      atau data tidak ditemukan        " << endl;
        cout << "=======================================" << endl;
	}
    
}

void hapusTengah(int target) {
    if (awallist == -1) {
        cout << "=======================================" << endl;
        cout << "      Tidak ada data buku tersedia     " << endl;
        cout << "=======================================" << endl;
        return;
    }

    int indeksHapus = -1;
    int bantu = awallist;
    int sebelumBantu = -1;

    while (bantu != -1) {
        if (elemen[bantu].info.noBuku == target) {
            indeksHapus = bantu;
            break;
        }
        sebelumBantu = bantu;
        bantu = elemen[bantu].next;
    }

    if (indeksHapus == -1) {
        cout << "=======================================" << endl;
        cout << "          Data tidak ditemukan         " << endl;
        cout << "=======================================" << endl;
        return; 
    }

    if (indeksHapus == awallist || elemen[indeksHapus].next == -1) {
        cout << "=======================================" << endl;
        cout << "   Tidak dapat menghapus di awal atau  " << endl;
        cout << "  akhir silakan pilih menu yang sesuai " << endl;
        cout << "=======================================" << endl;
        return;
    }

    elemen[sebelumBantu].next = elemen[indeksHapus].next;
    elemen[indeksHapus].next = listkosong;
    listkosong = indeksHapus;

    cout << "=======================================" << endl;
    cout << "        Data berhasil dihapus          " << endl;
    cout << "=======================================" << endl;
}



void hapusBelakang(int target) {
    if (awallist == -1) {
        cout << "=======================================" << endl;
        cout << "      Tidak ada data buku tersedia     " << endl;
        cout << "=======================================" << endl;
        return;
    }
	
    int indeksHapus = akhirlist;
    int bantu = awallist;
    int sebelumBantu = -1;
	
	
	
    while (elemen[bantu].info.noBuku != target) {
        if (elemen[bantu].next == -1) {
			
            cout << "=======================================" << endl;
            cout << "         Data tidak ditemukan          " << endl;
            cout << "=======================================" << endl;
            return; 
        }
        sebelumBantu = bantu;
        bantu = elemen[bantu].next;
    }
    
	if (bantu != akhirlist) {
        cout << "=======================================" << endl;
        cout << "   Tidak dapat menghapus bukan elemen " << endl;
        cout << "            terakhir!                  " << endl;
        cout << "=======================================" << endl;
        return;
    }

    if (indeksHapus == awallist) {
        awallist = -1;
        akhirlist = -1;
    }
    else {
        akhirlist = sebelumBantu;
        elemen[sebelumBantu].next = -1;
    }

    elemen[indeksHapus].next = listkosong;
    listkosong = indeksHapus;

    cout << "=======================================" << endl;
    cout << "    Data terakhir berhasil dihapus    " << endl;
    cout << "=======================================" << endl;
}



void cetakList() {
    cout << endl;
    int bantu = awallist;
    cout << "=======================================" << endl;
    cout << "       Data Buku di Perpustakaan       " << endl;
    cout << "=======================================" << endl << endl;

    while (bantu != -1) {
        cout << "Nomor Buku: " << elemen[bantu].info.noBuku << endl;
        cout << "Judul: " << elemen[bantu].info.judul << endl;
        cout << "Penulis: " << elemen[bantu].info.penulis << endl;
        cout << "Penerbit: " << elemen[bantu].info.penerbit << endl;
        cout << "Tahun Terbit: " << elemen[bantu].info.tahunTerbit << endl;
        cout << "Jenis Buku: " << elemen[bantu].info.jenisBuku << endl << endl;
        bantu = elemen[bantu].next;
    }
}
