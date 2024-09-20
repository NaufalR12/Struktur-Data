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
    if (root == nullptr) {
        return buatSimpul(nama, angkatan, jurusan, ipk);
    }

    if (nama < root->nama) {
        root->left = tambahMahasiswa(root->left, nama, angkatan, jurusan, ipk);
    } else if (nama > root->nama) {
        root->right = tambahMahasiswa(root->right, nama, angkatan, jurusan, ipk);
    } else {  // Jika 'nama' sudah ada, tidak tambahkan node baru
        cout << "Node dengan nama tersebut sudah ada." << endl;
    }
    return root;
}

void inorderCetak(Mahasiswa* root) {
    if (root != nullptr) {
        inorderCetak(root->left);
        cout << "Nama: " << root->nama << " | Angkatan: " << root->angkatan << " | Jurusan: " << root->jurusan << " | IPK: " << root->ipk << endl;
        inorderCetak(root->right);
    }
}

void preorderCetak(Mahasiswa* root) {
    if (root != nullptr) {
        cout << "Nama: " << root->nama << " | Angkatan: " << root->angkatan << " | Jurusan: " << root->jurusan << " | IPK: " << root->ipk << endl;
        preorderCetak(root->left);
        preorderCetak(root->right);
    }
}

void postorderCetak(Mahasiswa* root) {
    if (root != nullptr) {
        postorderCetak(root->left);
        postorderCetak(root->right);
        cout << "Nama: " << root->nama << " | Angkatan: " << root->angkatan << " | Jurusan: " << root->jurusan << " | IPK: " << root->ipk << endl;
    }
}

Mahasiswa* cariNode(Mahasiswa* root, string nama) {
    if (root == nullptr || root->nama == nama) {
        return root;
    }

    if (nama < root->nama) {
        return cariNode(root->left, nama);
    }

    return cariNode(root->right, nama);
}

void editData(Mahasiswa* root, string nama, int angkatan, string jurusan, double ipk) {
    Mahasiswa* target = cariNode(root, nama);
    if (target != nullptr) {
        target->angkatan = angkatan;
        target->jurusan = jurusan;
        target->ipk = ipk;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

Mahasiswa* hapusNode(Mahasiswa* root, string nama) {
    if (root == nullptr) {
        return root;
    }

    if (nama < root->nama) {
        root->left = hapusNode(root->left, nama);
    } else if (nama > root->nama) {
        root->right = hapusNode(root->right, nama);
    } else {
        if (root->left == nullptr) {
            Mahasiswa* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Mahasiswa* temp = root->left;
            delete root;
            return temp;
        } else {
            Mahasiswa* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->nama = temp->nama;
            root->angkatan = temp->angkatan;
            root->jurusan = temp->jurusan;
            root->ipk = temp->ipk;
            root->right = hapusNode(root->right, temp->nama);
        }
    }
    return root;
}

int main() {
    Mahasiswa* root = nullptr;

    char opsi;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Cetak data mahasiswa (Inorder)\n";
        cout << "3. Cetak data mahasiswa (Preorder)\n";
        cout << "4. Cetak data mahasiswa (Postorder)\n";
        cout << "5. Edit data mahasiswa\n";
        cout << "6. Hapus data mahasiswa\n";
        cout << "7. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> opsi;

        switch (opsi) {
            case '1': {
                string nama, jurusan;
                int angkatan;
                double ipk;
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
                break;
            }
            case '2':
                cout << "Cetak data mahasiswa (Inorder):\n";
                inorderCetak(root);
                break;
            case '3':
                cout << "Cetak data mahasiswa (Preorder):\n";
                preorderCetak(root);
                break;
            case '4':
                cout << "Cetak data mahasiswa (Postorder):\n";
                postorderCetak(root);
                break;
            case '5': {
                string nama, jurusan;
                int angkatan;
                double ipk;
                cin.ignore();
                cout << "Masukkan nama data yang ingin diubah: ";
                getline(cin, nama);
                cout << "Masukkan angkatan baru: ";
                cin >> angkatan;
                cin.ignore();
                cout << "Masukkan jurusan baru: ";
                getline(cin, jurusan);
                cout << "Masukkan IPK baru: ";
                cin >> ipk;
                editData(root, nama, angkatan, jurusan, ipk);
                break;
            }
            case '6': {
                string hapusNama;
                cin.ignore();
                cout << "Masukkan nama data yang ingin dihapus: ";
                getline(cin, hapusNama);
                root = hapusNode(root, hapusNama);
                break;
            }
            case '7':
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid.\n";
        }
    } while (opsi != '7');

    return 0;
}
