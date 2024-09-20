#include <iostream>
using namespace std;

struct data {
    string nama;
    int angkatan;
    string jurusan;
    float ipk;
    data* kiri;
    data* kanan;
};

data* buatPtb(string nama, int angkatan, string jurusan, float ipk) {
    data* dataBaru = new data;
    dataBaru->nama = nama;
    dataBaru->angkatan = angkatan;
    dataBaru->jurusan = jurusan;
    dataBaru->ipk = ipk;
    dataBaru->kiri = nullptr;
    dataBaru->kanan = nullptr;
    return dataBaru;
}

data* sisipNode(data* root, string nama, int angkatan, string jurusan, float ipk) {
    if (root == nullptr) {
        return buatPtb(nama, angkatan, jurusan, ipk);
    }

    if (nama < root->nama) {
        root->kiri = sisipNode(root->kiri, nama, angkatan, jurusan, ipk);
    } else if (nama > root->nama) {
        root->kanan = sisipNode(root->kanan, nama, angkatan, jurusan, ipk);
    } else {
        cout << "Data dengan nama tersebut sudah ada." << endl;
    }
    return root;
}

void inorder(data* root) {
    if (root != nullptr) {
        inorder(root->kiri);
        cout << "  " << root->nama << " - " << root->angkatan << " - " << root->jurusan << " - " << root->ipk << endl;
        inorder(root->kanan);
    }
}


void preorder(data* root) {
    if (root != nullptr) {
        cout << "  " << root->nama << " - " << root->angkatan << " - " << root->jurusan << " - " << root->ipk << endl;
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void postorder(data* root) {
    if (root != nullptr) {
        postorder(root->kiri);
        postorder(root->kanan);
        cout << "  " << root->nama << " - " << root->angkatan << " - " << root->jurusan << " - " << root->ipk << endl;
    }
}

data* cariNode(data* root, string nama) {
    if (root == nullptr || root->nama == nama) {
        return root;
    }

    if (nama < root->nama) {
        return cariNode(root->kiri, nama);
    }

    return cariNode(root->kanan, nama);
}

void editData(data* root) {
    if (root == nullptr) {
        cout << " Data masih kosong." << endl;
        return;
    }

    string targetNama, nama, jurusan;
    int angkatan;
    float ipk;

    cin.ignore();
    cout << "Masukkan nama mahasiswa yang ingin diubah: ";
    getline(cin, targetNama);

    data* target = cariNode(root, targetNama);
    if (target != nullptr) {
        cout << " Masukkan nama baru    : ";
        getline(cin, nama);
        cout << " Masukkan angkatan baru: ";
        cin >> angkatan;
        cin.ignore();
        cout << " Masukkan jurusan baru : ";
        getline(cin, jurusan);
        cout << " Masukkan IPK baru     : ";
        cin >> ipk;

        target->nama = nama;
        target->angkatan = angkatan;
        target->jurusan = jurusan;
        target->ipk = ipk;

        cout << "Data berhasil diubah." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

data* deleteNode(data* root, const string& k, bool& success) {
    if (root == nullptr) {
        success = false;
        return root;
    }

    if (k < root->nama) {
        root->kiri = deleteNode(root->kiri, k, success);
        return root;
    } else if (k > root->nama) {
        root->kanan = deleteNode(root->kanan, k, success);
        return root;
    }

    if (root->kiri == nullptr) {
        data* temp = root->kanan;
        delete root;
        success = true;
        return temp;
    } else if (root->kanan == nullptr) {
        data* temp = root->kiri;
        delete root;
        success = true;
        return temp;
    } else {
        data* successorAkar = root;
        data* successor = root->kanan;
        while (successor->kiri != nullptr) {
            successorAkar = successor;
            successor = successor->kiri;
        }

        if (successorAkar != root) {
            successorAkar->kiri = successor->kanan; // Fix this line to handle the right subtree of the successor
        } else {
            successorAkar->kanan = successor->kanan; // Handle the case where the successor is the root of the right subtree
        }

        root->nama = successor->nama;
        root->angkatan = successor->angkatan;
        root->jurusan = successor->jurusan;
        root->ipk = successor->ipk;

        delete successor;
        success = true;
        return root;
    }
}


data* hapusNode(data* root) {
    if (root == nullptr) {
        cout << "Data masih kosong." << endl;
        return nullptr;
    }

    string hapusNama;
    cin.ignore();
    cout << "\nMasukkan nama mahasiswa yang ingin dihapus: ";
    getline(cin, hapusNama);

    data* akar = nullptr;
    data* bantu = root;

    while (bantu != nullptr && bantu->nama != hapusNama) {
        akar = bantu;
        if (hapusNama < bantu->nama) {
            bantu = bantu->kiri;
        } else {
            bantu = bantu->kanan;
        }
    }

    if (bantu == nullptr) {
        cout << "Data tidak ditemukan." << endl;
        return root;
    }

    bool success = false;
    root = deleteNode(root, hapusNama, success);

    if (success) {
        cout << "Data berhasil dihapus." << endl;
    } else {
        cout << "Gagal menghapus data." << endl;
    }

    return root;
}

int main() {
    data* root = nullptr;

    int pilih;
    do {
        system("cls");
        cout << "+=============================+\n";
        cout << "         -+- Menu -+-\n";
        cout << "+=============================+\n";
        cout << " 1. Tambah data\n";
        cout << " 2. Cetak In-order\n";
        cout << " 3. Cetak Pre-order\n";
        cout << " 4. Cetak Post-order\n";
        cout << " 5. Edit\n";
        cout << " 6. Hapus\n";
        cout << " 7. Keluar\n";
        cout << "+=============================+\n";
        cout << " Pilih menu: ";
        cin >> pilih;
        cout << "+=============================+\n";

        if (pilih == 1) {
            string nama, jurusan;
            int angkatan;
            float ipk;
            cout << "    -+- Data Mahasiswa -+-\n";
            cout << "+=============================+\n";
            cin.ignore();
            cout << " Nama     : ";
            getline(cin, nama);
            cout << " Angkatan : ";
            cin >> angkatan;
            cin.ignore();
            cout << " Jurusan  : ";
            getline(cin, jurusan);
            cout << " IPK      : ";
            cin >> ipk;
            root = sisipNode(root, nama, angkatan, jurusan, ipk);
            cout << endl;
            system("pause");
        } else if (pilih == 2) {
            if (root == nullptr) {
                cout << " Data masih kosong." << endl;
            } else {
                cout << "    Cetak data Inorder\n";
                cout << "  Nama-Angkatan-Jurusan-IPK" << endl;
                cout << "+=============================+\n";
                inorder(root);
            }
            cout << endl;
            system("pause");
        } else if (pilih == 3) {
            if (root == nullptr) {
                cout << " Data masih kosong." << endl;
            } else {
                cout << "    Cetak data Preorder\n";
                cout << "  Nama-Angkatan-Jurusan-IPK" << endl;
                cout << "+=============================+\n";
                preorder(root);
            }
            cout << endl;
            system("pause");
        } else if (pilih == 4) {
            if (root == nullptr) {
                cout << " Data masih kosong." << endl;
            } else {
                cout << "    Cetak data Postorder\n";
                cout << "  Nama-Angkatan-Jurusan-IPK" << endl;
                cout << "+=============================+\n";
                postorder(root);
            }
            cout << endl;
            system("pause");
        } else if (pilih == 5) {
            editData(root);
            cout << endl;
            system("pause");
        } else if (pilih == 6) {
            root = hapusNode(root);
            cout << endl;
            system("pause");
        } else if (pilih == 7) {
            cout << "\n Keluar dari program.\n";
            cout << endl;
        } else {
            cout << "\n Pilihan tidak valid.\n";
            cout << endl;
        }

    } while (pilih != 7);

    return 0;
}
