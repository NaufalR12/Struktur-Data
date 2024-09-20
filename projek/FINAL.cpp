#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_PRODUCTS = 100;

struct TreeNode {
    string productName;
    double price;
    string productCode;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string name, double pr, string code) : productName(name), price(pr), productCode(code), left(nullptr), right(nullptr) {}
};

TreeNode* root = nullptr;

struct Product {
    string productName;
    double price;
    string productCode;
};

unordered_map<string, Product> productHash;

struct DeletedProduct {
    string productCode;
    string productName;
    double price;
};

Product products[MAX_PRODUCTS];
DeletedProduct deletedProducts[MAX_PRODUCTS];
int productCount = 0;
int deletedProductCount = 0;

void addToTree(TreeNode*& node, string productName, double price, string productCode) {
    if (node == nullptr) {
        node = new TreeNode(productName, price, productCode);
        Product newProduct;
        newProduct.productName = productName;
        newProduct.price = price;
        newProduct.productCode = productCode;
        productHash[productCode] = newProduct;
    } else {
        if (productName < node->productName) {
            addToTree(node->left, productName, price, productCode);
        } else if (productName > node->productName) {
            addToTree(node->right, productName, price, productCode);
        }
    }
}

void buildTree() {
    for (const auto& entry : productHash) {
        const Product& product = entry.second;
        addToTree(root, product.productName, product.price, product.productCode);
    }
}

void collectProductsPostOrderDesc(TreeNode* node, vector<Product>& sortedProducts) {
    if (node == nullptr) {
        return;
    }
    collectProductsPostOrderDesc(node->right, sortedProducts);
    auto it = productHash.find(node->productCode);
    if (it != productHash.end()) {
        sortedProducts.push_back(it->second);
    }
    collectProductsPostOrderDesc(node->left, sortedProducts);
}

void sortAndDisplayProductsByNameDescending() {
    vector<Product> sortedProducts;
    collectProductsPostOrderDesc(root, sortedProducts);

    sort(sortedProducts.begin(), sortedProducts.end(), [](const Product& a, const Product& b) {
        return a.productName > b.productName;
    });

    cout << "+------------------------------------------------+\n";
    cout << "|         URUTAN PRODUK (Descending Nama)        |\n";
    cout << "+------------------------------------------------+\n\n";
    for (const auto& product : sortedProducts) {
        cout << "\nNama Produk\t: " << product.productName;
        cout << "\nHarga\t\t: " << product.price;
        cout << "\nKode Produk\t: " << product.productCode << endl << endl;
    }
    system("pause");
    system("cls");
}

void displayMenu() {
    cout << "          +----------------------------+           \n";
    cout << "          |  TOKO KELONTONG SERBA ADA  |           \n";
    cout << "          +----------------------------+           \n";
    cout << endl;
    cout << "+------------------------------------------------+\n";
    cout << "|                     MENU                       |\n";
    cout << "+------------------------------------------------+\n";
    cout << "| 1. INPUT DATA                                  |\n";
    cout << "| 2. TAMPILKAN DATA                              |\n";
    cout << "| 3. CARI DATA (berdasarkan kode produk)         |\n";
    cout << "| 4. CARI DATA (berdasarkan rentang nama produk) |\n";
    cout << "| 5. URUTKAN PRODUK (berdasarkan nama)           |\n";
    cout << "| 6. HAPUS DATA                                  |\n";
    cout << "| 7. HISTORY DATA                                |\n";
    cout << "| 8. KELUAR                                      |\n";
    cout << "+------------------------------------------------+\n";
}

void addProduct() {
    cout << "+------------------------------------------------+\n";
    cout << "|                  INPUT DATA                    |\n";
    cout << "+------------------------------------------------+\n\n";
    int numInputs;
    cout << "Masukkan jumlah produk yang ingin diinput : ";
    cin >> numInputs;

    for (int i = 0; i < numInputs; ++i) {
        if (productCount < MAX_PRODUCTS) {
            Product newProduct;
            cout << "\nNama Produk\t: ";
            cin.ignore(); // Clear buffer
            getline(cin, newProduct.productName);
            cout << "Harga\t\t: ";
            cin >> newProduct.price;
            cout << "Kode Produk\t: ";
            cin >> newProduct.productCode;

            productHash[newProduct.productCode] = newProduct;

            addToTree(root, newProduct.productName, newProduct.price, newProduct.productCode);

            productCount++;
        } else {
            cout << "Sistem sudah mencapai batas maksimum produk.\n";
            break;
        }
    }
    cout << "\nProduk berhasil ditambahkan.\n\n";
    system("pause");
    system("cls");
}

void displayProducts() {
    cout << "+------------------------------------------------+\n";
    cout << "|                 TAMPILAN DATA                  |\n";
    cout << "+------------------------------------------------+\n\n";
    cout << "Daftar Produk :\n";
    cout << "---------------\n";
    for (const auto& entry : productHash) {
        const Product& product = entry.second;
        cout << "\nNama Produk\t: " << product.productName;
        cout << "\nHarga\t\t: " << product.price;
        cout << "\nKode Produk\t: " << product.productCode << endl << endl;
    }
    system("pause");
    system("cls");
}

void searchByProductCode() {
    cout << "+------------------------------------------------+\n";
    cout << "|      CARI DATA (berdasarkan kode produk)       |\n";
    cout << "+------------------------------------------------+\n\n";
    string productCode;
    cout << "Masukkan Kode Produk yang Dicari : ";
    cin >> productCode;

    auto it = productHash.find(productCode);
    if (it != productHash.end()) {
        const Product& product = it->second;
        cout << "\nNama Produk\t: " << product.productName;
        cout << "\nHarga\t\t: " << product.price;
        cout << "\nKode Produk\t: " << product.productCode << endl << endl;
    } else {
        cout << "\nProduk tidak ditemukan.\n\n";
    }
    system("pause");
    system("cls");
}

void searchByName(TreeNode* node, const string& targetName) {
    if (node != nullptr) {
        searchByName(node->left, targetName);
        if (node->productName == targetName) {
            auto it = productHash.find(node->productCode);
            if (it != productHash.end()) {
                const Product& product = it->second;
                cout << "\nNama Produk\t: " << product.productName;
                cout << "\nHarga\t\t: " << product.price;
                cout << "\nKode Produk\t: " << product.productCode << endl;
                return;
            }
        }
        searchByName(node->right, targetName);
    } else {
        cout << "\nProduk tidak ditemukan.\n\n";
    }
}

void searchByProductName() {
    cout << "+------------------------------------------------+\n";
    cout << "|      CARI DATA (berdasarkan rentang huruf)     |\n";
    cout << "+------------------------------------------------+\n\n";
    
    char startChar, endChar;
    cout << "Masukkan rentang huruf awal\t: ";
    cin >> startChar;
    cout << "Masukkan rentang huruf akhir\t: ";
    cin >> endChar;

    cout << "\nProduk dengan nama yang dimulai dari huruf " << startChar << " - " << endChar << " :\n";
    for (const auto& entry : productHash) {
        const Product& product = entry.second;
        char firstChar = product.productName[0];
        if (firstChar >= startChar && firstChar <= endChar) {
            cout << "\nNama Produk\t: " << product.productName;
            cout << "\nHarga\t\t: " << product.price;
            cout << "\nKode Produk\t: " << product.productCode << endl << endl;
        }
    }
    
    cout << endl;
    system("pause");
    system("cls");
}


void collectProductsPostOrder(TreeNode* node, vector<Product>& sortedProducts) {
    if (node == nullptr) {
        return;
    }
    collectProductsPostOrder(node->left, sortedProducts);
    auto it = productHash.find(node->productCode);
    if (it != productHash.end()) {
        sortedProducts.push_back(it->second);
    }
    collectProductsPostOrder(node->right, sortedProducts);
}

void displaySortedProducts(const vector<Product>& sortedProducts);

void sortAndDisplayProductsByName() {
    vector<Product> sortedProducts;
    collectProductsPostOrder(root, sortedProducts);

    sort(sortedProducts.begin(), sortedProducts.end(), [](const Product& a, const Product& b) {
        return a.productName < b.productName;
    });

    displaySortedProducts(sortedProducts);
}

void displaySortedProducts(const vector<Product>& sortedProducts) {
    cout << "+------------------------------------------------+\n";
    cout << "|                   URUTAN DATA                  |\n";
    cout << "+------------------------------------------------+\n\n";
    for (const auto& product : sortedProducts) {
        cout << "\nNama Produk\t: " << product.productName;
        cout << "\nHarga\t\t: " << product.price;
        cout << "\nKode Produk\t: " << product.productCode << endl << endl;
    }
    system("pause");
    system("cls");
}

void removeProduct() {
    cout << "+------------------------------------------------+\n";
    cout << "|                   HAPUS DATA                   |\n";
    cout << "+------------------------------------------------+\n\n";
    string productCode;
    cout << "Masukkan Kode Produk yang Akan Dihapus : ";
    cin >> productCode;

    auto it = productHash.find(productCode);
    if (it != productHash.end()) {
        DeletedProduct deletedProduct;
        deletedProduct.productCode = it->second.productCode;
        deletedProduct.productName = it->second.productName;
        deletedProduct.price = it->second.price;

        deletedProducts[deletedProductCount++] = deletedProduct;

        productHash.erase(it);
        cout << "\nProduk berhasil dihapus.\n\n";
    } else {
        cout << "\nProduk tidak ditemukan.\n\n";
    }
    system("pause");
    system("cls");
}

void displayDeletedProductsInOrder(int index) {
    if (index < deletedProductCount) {
        displayDeletedProductsInOrder(2 * index + 1);
        const DeletedProduct& deletedProduct = deletedProducts[index];
        cout << "\nNama Produk\t: " << deletedProduct.productName;
        cout << "\nHarga\t\t: " << deletedProduct.price;
        cout << "\nKode Produk\t: " << deletedProduct.productCode << endl << endl;
        displayDeletedProductsInOrder(2 * index + 2);
    }
}

void displayDeletedProductsPostOrder(int index) {
    if (index < deletedProductCount) {
        displayDeletedProductsPostOrder(2 * index + 1);
        displayDeletedProductsPostOrder(2 * index + 2);
        const DeletedProduct& deletedProduct = deletedProducts[index];
        cout << "\nNama Produk\t: " << deletedProduct.productName;
        cout << "\nHarga\t\t: " << deletedProduct.price;
        cout << "\nKode Produk\t: " << deletedProduct.productCode << endl << endl;
    }
}

void displayDeletedProductsPreOrder(int index) {
    if (index < deletedProductCount) {
        const DeletedProduct& deletedProduct = deletedProducts[index];
        cout << "\nNama Produk\t: " << deletedProduct.productName;
        cout << "\nHarga\t\t: " << deletedProduct.price;
        cout << "\nKode Produk\t: " << deletedProduct.productCode << endl << endl;
        displayDeletedProductsPreOrder(2 * index + 1);
        displayDeletedProductsPreOrder(2 * index + 2);
    }
}

void displayDeletedProducts() {
    cout << "+------------------------------------------------+\n";
    cout << "|                  HISTORY DATA                  |\n";
    cout << "+------------------------------------------------+\n\n";

    cout << "+------------+\n";
    cout << "|  Preorder  |\n";
    cout << "+------------+\n";
    
    displayDeletedProductsPreOrder(0);
    cout << endl;

    cout << "+------------+\n";
    cout << "|  Inorder   |\n";
    cout << "+------------+\n";
  
    displayDeletedProductsInOrder(0);
    cout << endl;

    cout << "+------------+\n";
    cout << "|  Postorder |\n";
    cout << "+------------+\n";
  
    displayDeletedProductsPostOrder(0);
    cout << endl;

    system("pause");
    system("cls");
}

int main() {
    int choice;
    buildTree();
    do {
        displayMenu();
        cout << "Pilih : ";
        cin >> choice;

        switch (choice) {
            case 1:
				system("cls");
                addProduct();
                break;
            case 2:
				system("cls");
                displayProducts();
                break;
            case 3:
				system("cls");
                searchByProductCode();
                break;
            case 4:
				system("cls");
                searchByProductName();
                break;
            case 5:
				system("cls");
                sortAndDisplayProductsByNameDescending();
                break;
            case 6:
				system("cls");
                removeProduct();
                break;
            case 7:
				system("cls");
                displayDeletedProducts();
                break;
            case 8:
				system("cls");
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
				system("cls");
                break;      
        }
    } while (choice != 8);

    return 0;
}
