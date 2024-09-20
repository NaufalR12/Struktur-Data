#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* kiri;
    int value;
    Node* kanan;
};

void sisipNode(int newValue, Node** root) {

}

Node* minValue(Node* root) {

}

Node* maxValue(Node* root) {

}

void preOrder(Node* root) {

}

void inOrder(Node* root) {

}

void postOrder(Node* root) {

}

void deleteNode(Node** root, Node** P, int k) {
   
}

int main() {
    Node* root = nullptr;
    while (true) {
        system("cls");
        cout << "1. Sisip\n2. Hapus\n3. Cetak\n4. Minimum\n5. Maximum\n6. Malas input\n7. Keluar\nJawaban: ";
        int jwb;
        cin >> jwb;
        if (jwb == 1) {
            cout << "Nilai : ";
            int nil;
            cin >> nil;
            sisipNode(nil, &root);
        } else if (jwb == 2) {
            cout << "Nilai : ";
            int nil;
            cin >> nil;
            deleteNode(&root, &root, nil);
        } else if (jwb == 3) {
            cout << "PreOrder: ";
            preOrder(root);
            cout << "\nInOrder: ";
            inOrder(root);
            cout << "\nPostOrder: ";
            postOrder(root);
            cout << endl;
            system("pause");
        } else if (jwb == 4) {
            Node* hasil = minValue(root);
            cout << "Minimum = " << hasil->value << endl;
            system("pause");
        } else if (jwb == 5) {
            Node* hasil = maxValue(root);
            cout << "Maximum = " << hasil->value << endl;
            system("pause");
        } else if (jwb == 6) {
            // Add test insertions here
            cout << endl << endl;
        } else {
            break;
        }
    }

    return 0;
}
