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
    buku* next;
};

buku *awal, *akhir;

void buatListBaru(), menu(), input(), hapusList(int target), cetakList();
void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void sisipTengah(int no, string judul, string penulis, string penerbit, int tahun, string jenis);
void sisipBelakang(int no, string judul, string penulis, string penerbit, int tahun, string jenis);


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
			
			
			cout << "Jumlah buku yang ingin ditambahkan: ";	cin >> jumlahBuku;
			cin.ignore();
			cout << endl;
			
			for (int i = 0; i < jumlahBuku; i++) {
				int no;
				string judul, penulis, penerbit, jenis;
				int tahun;

				cout << "Masukkan data buku ke-" << i + 1 << endl;
				cout << "Nomor Buku: ";	cin >> no;
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
			
			cout << "Jumlah buku yang ingin ditambahkan: ";	cin >> jumlahBuku;
			cin.ignore();
			cout << endl;

			for (int i = 0; i < jumlahBuku; i++) {
				int no;
				string judul, penulis, penerbit, jenis;
				int tahun;

				cout << "Masukkan data buku ke-" << i + 1 << endl;
				cout << "Nomor Buku: ";	cin >> no;
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
				sisipTengah(no, judul, penulis, penerbit, tahun, jenis);
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
			
			cout << "Jumlah buku yang ingin ditambahkan: ";	cin >> jumlahBuku;
			cin.ignore();
			cout << endl;

			for (int i = 0; i < jumlahBuku; i++) {
				int no;
				string judul, penulis, penerbit, jenis;
				int tahun;

				cout << "Masukkan data buku ke-" << i + 1 << endl;
				cout << "Nomor Buku: ";	cin >> no;
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

				sisipBelakang(no, judul, penulis, penerbit, tahun, jenis);
			}
			cout << "=======================================" << endl;
			cout << "Kembali ke menu: ";
			system("pause");
			menu();
			break;
		
		case 4:
			system("cls");
			int noHapus;
			cout << "=================================" << endl;
			cout << "            Hapus Buku           " << endl;
			cout << "=================================" << endl;
			cout << "No buku yang ingin di hapus : "; cin >> noHapus;
			hapusList(noHapus);
			cout << "=======================================" << endl;
			cout << "Kembali ke menu: ";
			system("pause");
			menu();
			break;
		case 5:
			system("cls");
			if (awal == NULL) {
                cout << "=======================================" << endl;
                cout << "      Tidak ada data buku tersedia     " << endl;
                cout << "=======================================" << endl;
            } else {
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
    awal = NULL;
    akhir = NULL;
}

void sisipDepan(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = new buku;
    bukuBaru->noBuku = no;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->penerbit = penerbit;
    bukuBaru->tahunTerbit = tahun;
    bukuBaru->jenisBuku = jenis;
    bukuBaru->next = NULL;

    try {
        if (awal == NULL) {
            awal = bukuBaru;
            akhir = bukuBaru;
        } else {
            bukuBaru->next = awal;
            awal = bukuBaru;
        }
        cout << "=======================================" << endl;
		cout << "||        Berhasil di sisip          ||" << endl;
		cout << "=======================================\n" << endl; 
    } catch (const std::bad_alloc& e) {
        cout << "Error: Alokasi memori gagal. Sisip depan tidak berhasil dilakukan." << endl;
        delete bukuBaru; 
    }
}

void sisipTengah(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = new buku;
    bukuBaru->noBuku = no;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->penerbit = penerbit;
    bukuBaru->tahunTerbit = tahun;
    bukuBaru->jenisBuku = jenis;
    bukuBaru->next = NULL;

 
    try {
		buku* bantu = awal;

		while (bantu->next != NULL && bantu->next->noBuku < no) {
			bantu = bantu->next;
		}

		bukuBaru->next = bantu->next;
		bantu->next = bukuBaru;
		
		cout << "=======================================" << endl;
		cout << "||        Berhasil di sisip          ||" << endl;
		cout << "=======================================\n" << endl;
	} catch (const std::bad_alloc& e) {
	    cout << "Error: Alokasi memori gagal. Sisip tengah tidak berhasil dilakukan." << endl;
        delete bukuBaru; 
    }
}

void sisipBelakang(int no, string judul, string penulis, string penerbit, int tahun, string jenis) {
    buku* bukuBaru = new buku;
    bukuBaru->noBuku = no;
    bukuBaru->judul = judul;
    bukuBaru->penulis = penulis;
    bukuBaru->penerbit = penerbit;
    bukuBaru->tahunTerbit = tahun;
    bukuBaru->jenisBuku = jenis;
    bukuBaru->next = NULL;

	try {
		if (awal == NULL) {
			awal = bukuBaru;
			return;
		}

		buku* bantu = awal;
		while (bantu->next != NULL) {
			bantu = bantu->next;
		}

		bantu->next = bukuBaru;
		
		cout << "=======================================" << endl;
		cout << "||        Berhasil di sisip          ||" << endl;
		cout << "=======================================\n" << endl;
	} catch (const std::bad_alloc& e) {
	    cout << "Error: Alokasi memori gagal. Sisip belakang tidak berhasil dilakukan." << endl;
        delete bukuBaru; 
    }
}

void hapusList(int target) {
    buku* bantu = awal;
    buku* sebelumBantu = NULL;

    if (bantu != NULL && bantu->noBuku == target) {
        awal = bantu->next;
        delete bantu;
        return;
    }

    while (bantu != NULL && bantu->noBuku != target) {
        sebelumBantu = bantu;
        bantu = bantu->next;
    }

    if (bantu == NULL) {
		cout << "=======================================" << endl;
        cout << "          Data tidak ditemukan         " << endl;
        cout << "=======================================" << endl;
        return;
    }

    sebelumBantu->next = bantu->next;
    delete bantu;
}

void cetakList() {
    cout << endl;
    buku* bantu = awal;
	cout << "=======================================" << endl;
	cout << "       Data Buku di Perpustakaan       " << endl;
	cout << "=======================================" << endl << endl;
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
