#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int angkatan;
    string jurusan;
    double ipk;
    Mahasiswa* left;
    Mahasiswa* right;
};

int ptb_kosong(Mahasiswa* root);
Mahasiswa* buatSimpul(string nama, int angkatan, string jurusan, double ipk);
Mahasiswa* tambahMahasiswa(Mahasiswa* root, string nama, int angkatan, string jurusan, double ipk);
void inorderCetak(Mahasiswa* root);
void preorderCetak(Mahasiswa* root);
void postorderCetak(Mahasiswa* root);
Mahasiswa* cariNode(Mahasiswa* root, string nama);
void editData(Mahasiswa* root, string nama);
Mahasiswa* hapusNode(Mahasiswa* root, string nama) ;



int main() {
    Mahasiswa* root = nullptr;

    char pilih;
    do {
		system("cls");
        cout << "====================================" << endl;
        cout << "                Menu                " << endl;
        cout << "====================================" << endl;
        cout << "1. Input data" << endl;
        cout << "2. Cetak data (Inorder)" << endl;
        cout << "3. Cetak data (Preorder)" << endl;
        cout << "4. Cetak data (Postorder)" << endl;
        cout << "5. Cari data" << endl;
        cout << "6. Edit data" << endl;
        cout << "7. Hapus data" << endl;
        cout << "8. Keluar" << endl;
        cout << "====================================" << endl;
        cout << "Pilih opsi: "; cin >> pilih;

        switch (pilih) {
            case '1': {
                string nama, jurusan;
                int angkatan;
                double ipk;
                cout << "====================================" << endl;
                cout << "             Input data             " << endl;
                cout << "====================================" << endl;
                cin.ignore();
                cout << "Masukkan nama: ";
                getline(cin, nama);
                cout << "Masukkan angkatan: ";
                cin >> angkatan;
                cin.ignore();
                cout << "Masukkan jurusan: ";
                getline(cin, jurusan);
                cout << "Masukkan IPK: ";
                cin >> ipk;
                root = tambahMahasiswa(root, nama, angkatan, jurusan, ipk);
                cout << "====================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            }
            case '2':
                cout << "====================================" << endl;
                cout << "       Cetak data (Inorder)         " << endl;
                cout << "====================================" << endl;
                if (ptb_kosong(root)) {
                    cout << "Data kosong!" << endl;
                }
                inorderCetak(root);
                cout << "====================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            case '3':
                cout << "====================================" << endl;
                cout << "       Cetak data (Preorder)        " << endl;
                cout << "====================================" << endl;
                if (ptb_kosong(root)) {
                    cout << "Data kosong!" << endl;
                }
                preorderCetak(root);
                cout << "====================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            case '4':
                cout << "====================================" << endl;
                cout << "       Cetak data (Postorder)       " << endl;
                cout << "====================================" << endl;
                if (ptb_kosong(root)) {
                    cout << "Data kosong!" << endl;
                }
                postorderCetak(root);
                cout << "====================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            case '5': {
                string cariNama;
                cout << "====================================" << endl;
                cout << "              Cari data             " << endl;
                cout << "====================================" << endl;
                cin.ignore();
                cout << "Harap masukan nama lengkap untuk mencari!!!" << endl;
                cout << "Masukkan nama yang ingin dicari: ";
                getline(cin, cariNama);
                Mahasiswa* cari = cariNode(root, cariNama);
                if (cari != nullptr) {
                    cout << "Data ditemukan:\n";
                    cout << "====================================" << endl;
                    cout << "Nama: " << root->nama << endl;
                    cout << "Angkatan: " << root->angkatan << endl;
                    cout << "Jurusan: " << root->jurusan << endl;
                    cout << "IPK: " << root->ipk << endl;
                }
                cout << "====================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            }
            case '6': {
                string editNama;
                cout << "====================================" << endl;
                cout << "              Edit data             " << endl;
                cout << "====================================" << endl;
                cin.ignore();
                cout << "Harap masukan nama lengkap untuk mencari!!!" << endl;
                cout << "Masukkan nama data yang ingin diubah: "; getline(cin,editNama);
                cout << "============!!ENTER!!===============" << endl;
                editData(root, editNama);
                cout << "====================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            }
            case '7': {
                string hapusNama;
                cout << "====================================" << endl;
                cout << "              Hapus data            " << endl;
                cout << "====================================" << endl;
                cin.ignore();
                cout << "Masukkan nama data yang ingin dihapus: ";
                getline(cin, hapusNama);
                root = hapusNode(root, hapusNama); // Perhatikan penggunaan root untuk menyimpan hasil penghapusan
                if (root = nullptr) {
                    cout << "Data mahasiswa dengan nama " << hapusNama << " telah dihapus.\n";
                } else {
                    cout << "Gagal menghapus data mahasiswa dengan nama " << hapusNama << "\n";
                }
                cout << "====================================" << endl;
                cout << "Kembali ke menu : ";
                system("pause");
                break;
            }

            case '8':
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan anda tidak valid.\n";
        }
    } while (pilih != '8');

    return 0;
}

int ptb_kosong(Mahasiswa* root) {
    if (root == nullptr)
        return true;
    else
        return false;
}

Mahasiswa* buatSimpul(string nama, int angkatan, string jurusan, double ipk) {
    Mahasiswa* mahasiswaBaru = new Mahasiswa;
    mahasiswaBaru->nama = nama;
    mahasiswaBaru->angkatan = angkatan;
    mahasiswaBaru->jurusan = jurusan;
    mahasiswaBaru->ipk = ipk;
    mahasiswaBaru->left = nullptr;
    mahasiswaBaru->right = nullptr;
    return mahasiswaBaru;
}

Mahasiswa* tambahMahasiswa(Mahasiswa* root, string nama, int angkatan, string jurusan, double ipk) {
    if (ptb_kosong(root)) {
        return buatSimpul(nama, angkatan, jurusan, ipk);
    }

    // Jika nama yang baru kurang dari nama pada simpul saat ini, masukkan ke kiri
    if (nama < root->nama) {
        root->left = tambahMahasiswa(root->left, nama, angkatan, jurusan, ipk);
    } else { // Jika nama yang baru lebih dari atau sama dengan nama pada simpul saat ini, masukkan ke kanan
        root->right = tambahMahasiswa(root->right, nama, angkatan, jurusan, ipk);
    }
    return root;
}

void inorderCetak(Mahasiswa* root) {
    if (!ptb_kosong(root)) {
        inorderCetak(root->left);
        cout << "====================================" << endl;
        cout << "Nama: " << root->nama << endl;
        cout << "Angkatan: " << root->angkatan << endl;
        cout << "Jurusan: " << root->jurusan << endl;
        cout << "IPK: " << root->ipk << endl << endl;
        inorderCetak(root->right);
    } 
}

void preorderCetak(Mahasiswa* root) {
    if (!ptb_kosong(root)) {
        cout << "====================================" << endl;
        cout << "Nama: " << root->nama << endl;
        cout << "Angkatan: " << root->angkatan << endl;
        cout << "Jurusan: " << root->jurusan << endl;
        cout << "IPK: " << root->ipk << endl << endl;
        preorderCetak(root->left);
        preorderCetak(root->right);
    } 
}

void postorderCetak(Mahasiswa* root) {
    if (!ptb_kosong(root)) {
        postorderCetak(root->left);
        postorderCetak(root->right);
        cout << "====================================" << endl;
        cout << "Nama: " << root->nama << endl;
        cout << "Angkatan: " << root->angkatan << endl;
        cout << "Jurusan: " << root->jurusan << endl;
        cout << "IPK: " << root->ipk << endl << endl;
    } 
}

Mahasiswa* cariNode(Mahasiswa* root, string nama) {
    Mahasiswa* current = root;

    while (current != nullptr) {
        if (nama == current->nama) {
            return current;
        } else if (nama < current->nama) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Jika tidak ditemukan, return nullptr
    cout << "Data tidak ditemukan." << endl;
    return nullptr;
}


void editData(Mahasiswa* root, string nama) {
    Mahasiswa* target = cariNode(root, nama);
    if (target != nullptr) {
        cin.ignore();
        cout << "Masukkan nama baru: ";
        getline(cin, target->nama);
        cout << "Masukkan angkatan baru: ";
        cin >> target->angkatan;
        cin.ignore();
        cout << "Masukkan jurusan baru: ";
        getline(cin, target->jurusan);
        cout << "Masukkan IPK baru: ";
        cin >> target->ipk;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

Mahasiswa* hapusNode(Mahasiswa* root, string hapusNama) {
    if (root == nullptr) {
        cout << "Data masih kosong." << endl;
        return root;
    }

    Mahasiswa* parent = nullptr;
    Mahasiswa* current = root;

    // Cari node yang akan dihapus
    while (current != nullptr && current->nama != hapusNama) {
        parent = current;
        if (hapusNama < current->nama) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Jika node tidak ditemukan
    if (current == nullptr) {
        cout << "Data tidak ditemukan." << endl;
        return root;
    }

    // Jika node adalah leaf node (tidak memiliki anak)
    if (current->left == nullptr && current->right == nullptr) {
        if (parent == nullptr) {
            // Node adalah root dan satu-satunya node
            delete current;
            return nullptr;
        } else if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    }
    // Jika node memiliki satu anak
    else if (current->left == nullptr || current->right == nullptr) {
        Mahasiswa* temp = (current->left != nullptr) ? current->left : current->right;
        if (parent == nullptr) {
            // Node adalah root
            delete current;
            return temp;
        } else if (parent->left == current) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        delete current;
    }
    // Jika node memiliki dua anak
    else {
        Mahasiswa* successorParent = current;
        Mahasiswa* successor = current->right;
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // Salin nilai dari successor ke current
        current->nama = successor->nama;
        current->angkatan = successor->angkatan;
        current->jurusan = successor->jurusan;
        current->ipk = successor->ipk;

        // Hapus successor
        if (successorParent->left == successor) {
            successorParent->left = hapusNode(successorParent->left, successor->nama);
        } else {
            successorParent->right = hapusNode(successorParent->right, successor->nama);
        }
    }

    cout << "Data berhasil dihapus." << endl;
    return root;
}



