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
Mahasiswa* hapusNode(Mahasiswa* root, string hapusNama);
Mahasiswa* cariParent(Mahasiswa* root, Mahasiswa* child);

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
        cout << "Pilih opsi: ";
        cin >> pilih;

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
                    cout << "Nama: " << cari->nama << endl;
                    cout << "Angkatan: " << cari->angkatan << endl;
                    cout << "Jurusan: " << cari->jurusan << endl;
                    cout << "IPK: " << cari->ipk << endl;
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
                cout << "Masukkan nama data yang ingin diubah: ";
                getline(cin, editNama);
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
                root = hapusNode(root, hapusNama); 
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
    return root == nullptr;
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

    if (nama < root->nama) {
        root->left = tambahMahasiswa(root->left, nama, angkatan, jurusan, ipk);
    } else {
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
        cout << "Data kosong." << endl;
        return nullptr;
    }

    Mahasiswa* target = cariNode(root, hapusNama);

    if (target == nullptr) {
        return root;
    }

    Mahasiswa* parent = cariParent(root, target);

    // Case 1: Node yang dihapus adalah daun (tidak memiliki anak)
    if (target->left == nullptr && target->right == nullptr) {
        if (parent == nullptr) {
            // Node yang dihapus adalah root dan satu-satunya node di tree
            delete target;
            cout << "Data berhasil dihapus." << endl;
            return nullptr;
        } else if (target == parent->left) {
            // Node yang dihapus adalah left child dari parent
            parent->left = nullptr;
        } else {
            // Node yang dihapus adalah right child dari parent
            parent->right = nullptr;
        }
        delete target;
    }
    // Case 2: Node yang dihapus memiliki satu anak (kiri atau kanan)
    else if (target->left == nullptr || target->right == nullptr) {
        Mahasiswa* nonNullChild = (target->left != nullptr) ? target->left : target->right;
        if (parent == nullptr) {
            // Node yang dihapus adalah root dan memiliki satu anak
            delete target;
            cout << "Data berhasil dihapus." << endl;
            return nonNullChild;
        } else if (target == parent->left) {
            // Node yang dihapus adalah left child dari parent
            parent->left = nonNullChild;
        } else {
            // Node yang dihapus adalah right child dari parent
            parent->right = nonNullChild;
        }
        delete target;
    }
    // Case 3: Node yang dihapus memiliki dua anak
    else {
        Mahasiswa* successor = target->right;
        Mahasiswa* successorParent = nullptr;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // Pindahkan data successor ke target
        target->nama = successor->nama;
        target->angkatan = successor->angkatan;
        target->jurusan = successor->jurusan;
        target->ipk = successor->ipk;

        // Hapus successor yang sebenarnya
        if (successorParent != nullptr) {
            successorParent->left = nullptr;
        } else {
            target->right = nullptr;
        }
        delete successor;
    }

    cout << "Data berhasil dihapus." << endl;
    return root;
}






Mahasiswa* cariParent(Mahasiswa* root, Mahasiswa* child) {
    if (root == nullptr || root == child) {
        return nullptr;
    }

    if ((root->left == child) || (root->right == child)) {
        return root;
    }

    // Cari pada subtree kiri dan kanan
    Mahasiswa* parent = cariParent(root->left, child);
    if (parent == nullptr) {
        parent = cariParent(root->right, child);
    }

    return parent;
}
