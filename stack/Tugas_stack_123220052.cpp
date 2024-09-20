#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;


struct nodeTumpukan {
    int tinggi;
    int lebar;
    nodeTumpukan* next;
};

nodeTumpukan* buatNode(int tinggi, int lebar);
void push(nodeTumpukan*& stack, int tinggi, int lebar),pop(nodeTumpukan*& stack);
int topTinggi(const nodeTumpukan* stack);


int main() {
    int jumlahTumpukan;
    cout<<"="<<setfill('=')<<setw(50)<<"="<<"=\n";
    cout<<" "<<setfill(' ')<<setw(19)<<" "<<"Tugas Stack"<<setw(19)<<" "<<"\n";
    cout<<" "<<setfill(' ')<<setw(10)<<" "<<"Naufal Rafid Muhammad Faddila"<<setw(10)<<" "<<"\n";
    cout<<" "<<setfill(' ')<<setw(20)<<" "<<"123220052"<<setw(19)<<" "<<"\n";
    cout<<"="<<setfill('=')<<setw(50)<<"="<<"=\n";
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> jumlahTumpukan;

    vector<nodeTumpukan*> tumpukanBuku(jumlahTumpukan, nullptr);
    vector<string> namaTumpukan(jumlahTumpukan);
    vector<int> lebarTumpukan(jumlahTumpukan);

    // Memasukkan nama tumpukan, tinggi, dan lebar buku ke dalam vektor
    for (int i = 0; i < jumlahTumpukan; i++) {
        cout << endl;
        cin.ignore();
        cout<<"="<<setfill('=')<<setw(50)<<"="<<"=\n";
        cout << "Masukkan nama tumpukan " << i + 1 << ": ";
        getline(cin, namaTumpukan[i]);
		
		cout << "Lebar tumpukan\t: ";
        cin >> lebarTumpukan[i];
        
        int panjangTumpukan;
        cout << "Banyak item\t: ";
        cin >> panjangTumpukan;
		cout<<"-"<<setfill('-')<<setw(50)<<"-"<<"-\n";


        for (int j = 0; j < panjangTumpukan; j++) {
            int tinggi;
            cout << "Tinggi item ke " << j + 1 << " = ";
            cin >> tinggi;
            push(tumpukanBuku[i], tinggi, lebarTumpukan[i]);
        }
        cout<<"="<<setfill('=')<<setw(50)<<"="<<"=\n";
        
			cout << "\n\nTumpukan " << namaTumpukan[i] << endl;
			cout<<"="<<setfill('=')<<setw(lebarTumpukan[i])<<"="<<"=\n";
			int hitung = 0;
			nodeTumpukan* sekarang = tumpukanBuku[i];
			while (sekarang) {
				hitung++;
				sekarang = sekarang->next;
			}



			int index = 1;
			sekarang = tumpukanBuku[i];
			while (sekarang) {
				cout << "|" << sekarang->tinggi << " " << setfill(' ') << setw(lebarTumpukan[i] - to_string(sekarang->tinggi).length()) << "|" << endl;
				int tinggitabel = sekarang->tinggi - 1;
				for (int a=0; a<tinggitabel; a++) {
					cout << "|" << setfill(' ') << setw(1+lebarTumpukan[i]) << "|" << endl;
				}
				cout<<"="<<setfill('=')<<setw(lebarTumpukan[i])<<"="<<"=\n";
				index++;
				sekarang = sekarang->next;

			}
			
			cout << endl;
    }
    system("pause");

    // Menghitung total tinggi masing-masing tumpukan
    vector<int> totalTinggi(jumlahTumpukan, 0);

    for (int i = 0; i < jumlahTumpukan; i++) {
        nodeTumpukan* sekarang = tumpukanBuku[i];
        while (sekarang) {
            totalTinggi[i] += sekarang->tinggi;
            sekarang = sekarang->next;
        }
    }

    bool tumpukanPendek = false;

    while (!tumpukanPendek) {
        int tumpukanTerpendek = min_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();
        int tumpukanTerpanjang = max_element(totalTinggi.begin(), totalTinggi.end()) - totalTinggi.begin();

        if (totalTinggi[tumpukanTerpendek] == totalTinggi[tumpukanTerpanjang]) {
            tumpukanPendek = true;
        } else {
            int nilaiAtas = topTinggi(tumpukanBuku[tumpukanTerpanjang]);
            if (nilaiAtas != -1) {
                pop(tumpukanBuku[tumpukanTerpanjang]);
                totalTinggi[tumpukanTerpanjang] -= nilaiAtas;
            }
        }
    }

    // Menyamakan lebar tumpukan berdasarkan tumpukan terbesar
    int lebarTumpukanTerbesar = *max_element(lebarTumpukan.begin(), lebarTumpukan.end());

    for (int i = 0; i < jumlahTumpukan; i++) {
        lebarTumpukan[i] = lebarTumpukanTerbesar;
    }
	
	cout << "\n\n\n\n\n";
	cout<<" "<<setfill(' ')<<setw(3)<<" "<<"Tumpukan dengan tinggi dan lebar yang sama"<<setw(3)<<" "<<"\n";
	cout<<"="<<setfill('=')<<setw(50)<<"="<<"=\n";
    // Cetak tumpukan yang memiliki tinggi dan lebar yang sama dalam bentuk tabel
    for (int i = 0; i < jumlahTumpukan; i++) {
		cout << "\n\nTumpukan " << namaTumpukan[i] << endl;
        cout<<"="<<setfill('=')<<setw(lebarTumpukan[i])<<"="<<"=\n";
        int hitung = 0;
        nodeTumpukan* sekarang = tumpukanBuku[i];
        while (sekarang) {
            hitung++;
            sekarang = sekarang->next;
        }


        int index = 1;
        sekarang = tumpukanBuku[i];
        while (sekarang) {
            cout << "|" << sekarang->tinggi << " " << setfill(' ') << setw(lebarTumpukan[i] - to_string(sekarang->tinggi).length()) << "|" << endl;
            int tinggitabel = sekarang->tinggi - 1;
            for (int a=0; a<tinggitabel; a++) {
                cout << "|" << setfill(' ') << setw(1+lebarTumpukan[i]) << "|" << endl;
            }
            cout<<"="<<setfill('=')<<setw(lebarTumpukan[i])<<"="<<"=\n";
            index++;
            sekarang = sekarang->next;

        }

        cout << "Tinggi = " << totalTinggi[i] << endl;
        cout << "Lebar = " << lebarTumpukan[i] << endl;

        cout << "Banyak item = ";
        hitung = 0;
        sekarang = tumpukanBuku[i];
        while (sekarang) {
            hitung++;
            sekarang = sekarang->next;
        }
        cout << hitung << endl;

        index = 1;
        sekarang = tumpukanBuku[i];
        while (sekarang) {
            cout << "nilai item ke " << index << " (Tinggi: " << sekarang->tinggi << ", Lebar: " << lebarTumpukan[i] << ")" << endl;
            index++;
            sekarang = sekarang->next;
        }
        cout << endl;

    }

    // Cetak tumpukan yang memiliki tinggi dan lebar yang sama
    

    // Hapus memori yang dialokasikan
    for (int i = 0; i < jumlahTumpukan; i++) {
        nodeTumpukan* sekarang = tumpukanBuku[i];
        while (sekarang) {
            nodeTumpukan* temp = sekarang;
            sekarang = sekarang->next;
            delete temp;
        }
    }

    return 0;
}

void push(nodeTumpukan*& stack, int tinggi, int lebar) {
    nodeTumpukan* newNode = buatNode(tinggi, lebar);
    newNode->next = stack;
    stack = newNode;
}

nodeTumpukan* buatNode(int tinggi, int lebar) {
    nodeTumpukan* newNode = new nodeTumpukan;
    newNode->tinggi = tinggi;
    newNode->lebar = lebar;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk pop node dari stack
void pop(nodeTumpukan*& stack) {
    if (stack) {
        nodeTumpukan* temp = stack;
        stack = stack->next;
        delete temp;
    }
}

// Fungsi untuk mendapatkan nilai atas stack
int topTinggi(const nodeTumpukan* stack) {
    if (stack) {
        return stack->tinggi;
    }
    return -1; // Menandakan tumpukan kosong
}
