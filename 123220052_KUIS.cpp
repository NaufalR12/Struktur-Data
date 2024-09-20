#include <iostream>
#include <string>
using namespace std;

	
struct mhs {
	string nama;
	string nim;
	float kumpNilai[3];
	float rata2;
	mhs* next;
	};

mhs *awal, *akhir;

void menuBeranda(), buatList(),sisip(), cetak(), hapus();
bool listKosong();

int main () {
	buatList();
	menuBeranda();
	return 0;
}

void menuBeranda() { 
	system("cls");
	int jawab;
	cout << "======================" << endl;
	cout << "         Menu         " << endl;
	cout << "======================" << endl;
	cout << "1. Input " << endl;
	cout << "2. Tampilkan data" << endl;
	cout << "3. Hapus data " << endl;
	cout << "4. Keluar" << endl;
	cout << "======================" << endl;
	cout << "Pilih menu : "; cin >> jawab;
	
	switch (jawab) {
		case 1 :
			sisip(); break;
		case 2 : 
			cetak(); break;
		case 3 :
			hapus(); break;
		case 4 :
			exit(0); break;
		default : 
			cout << "Menu yang anda pilih tidak tersedia" << endl;
			cout << endl;
			system("pause");
			menuBeranda();
	}
}

void buatList(){
	awal = NULL;
	akhir = NULL;
}

bool listKosong(){
	if (awal == NULL)
		return true;
	else 
		return false;
	}
	
void sisip() {
	system("cls");
	mhs* mhsBaru = new mhs;
	string namaBaru;
	string nimBaru;
	float kumpNilaiBaru[3];
	float rata2Baru;
	
	cout << "======================" << endl;
	cout << "         INPUT        " << endl;
	cout << "======================" << endl;
	cin.ignore();
	cout << "Nama : "; getline(cin, namaBaru);
	cout << "NIM  : "; cin >> nimBaru;
	mhs* bantu;
	bantu = awal;
	while(bantu != NULL) {
		if (bantu->nim == nimBaru){
			cout << "NIM sudah ada, Harap input lagi!" << endl;
			system("pause");
			menuBeranda();
		}
		bantu = bantu->next;
		cout << endl;
	}
	cout << "======================" << endl;
	cout << "    Masukkan Nilai    " << endl;
	cout << "======================" << endl;
	cout << "NIlai tugas    : "; cin >> kumpNilaiBaru[0];
	cout << "Nilai kuis     : "; cin >> kumpNilaiBaru[1];
	cout << "Nilai responsi : "; cin >> kumpNilaiBaru[2];
	rata2Baru = (0.25*kumpNilaiBaru[0])+(0.35*kumpNilaiBaru[1])+(0.40*kumpNilaiBaru[2]);
	
	mhsBaru->nama = namaBaru;
	mhsBaru->nim = nimBaru;
	mhsBaru->kumpNilai[0] = kumpNilaiBaru[0];
	mhsBaru->kumpNilai[1] = kumpNilaiBaru[1];
	mhsBaru->kumpNilai[2] = kumpNilaiBaru[2];
	mhsBaru->rata2 = rata2Baru;
	
	if (listKosong()||rata2Baru>= awal->rata2) {
		mhsBaru->next = awal;
		awal = mhsBaru;
	} else {
		mhs* bantu = awal;
		mhs* sebelumBantu = NULL;
		while (bantu!= NULL && rata2Baru < bantu -> rata2) {
			sebelumBantu = bantu; 
			bantu = bantu->next;
		}
		sebelumBantu->next = mhsBaru;
		mhsBaru->next = bantu;
	}
	cout << endl;
	system("pause");
	menuBeranda();
}

void cetak() {
	system("cls");
	mhs* bantu;
	bantu = awal;
	if(listKosong()) {
		cout << "List masih kosong " << endl;
	}
	int i=0;
	while(bantu != NULL) {
		cout << "======================" << endl;
		cout << "Peringkat ke-" << i+1 << endl;
		cout << "======================" << endl;
		cout << "NIM  : " << bantu->nim << endl;
		cout << "Nama : " << bantu->nama << endl;
		cout << "Rata - rata nilai : " << bantu->rata2 << " (" 
			 << bantu->kumpNilai[0] << " " << bantu->kumpNilai[1]
			 << " " << bantu->kumpNilai[2] << ")" << endl;
		bantu = bantu->next;
		i++;
		cout << endl;
	}
	
	cout << endl;
	system("pause");
	menuBeranda();
}

void hapus() {
	mhs *hapus, *bantu;
	string nimHapus;
	cout << "NIM : "; cin >> nimHapus;
	
	if (listKosong()) {
		cout << "list masih kosong" << endl;
	} else if (awal->nim == nimHapus) {
		hapus = awal;
		awal = hapus->next;
		delete hapus;
		cout << "======================" << endl;
		cout << "   Berhasil dihapus   " << endl;
		cout << "======================" << endl;
	} else {
		bantu = awal;
		while (bantu->next->next != NULL && nimHapus != bantu->next->nim) {
			bantu = bantu->next;	
		}
		
		if (nimHapus == bantu->next->nim) {
			hapus = bantu->next;
			if (hapus == akhir) {
				akhir = bantu;
				akhir->next = NULL;
			} else {
				bantu->next = hapus->next;
			}
			//delete hapus;
			free (hapus);
			cout << "======================" << endl;
			cout << "   Berhasil dihapus   " << endl;
			cout << "======================" << endl;
		} else {
			cout << "======================" << endl;
			cout << "Data tidak ditemukan " << endl;
			cout << "======================" << endl;
		}
	}
	cout << endl;
	system("pause");
	menuBeranda();
	
}

