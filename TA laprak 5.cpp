#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* left;
    Node* right;
    
    Node(int x) : nilai(x), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->nilai)
        root->left = insertNode(root->left, x);
    else
        root->right = insertNode(root->right, x);
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->nilai << " ";
        inorder(root->right);
    }
}

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left)
        root = root->left;
    return root->nilai;
}

int findMax(Node* root) {
    if (!root) return -1;
    while (root->right)
        root = root->right;
    return root->nilai;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih, x;

    do {
        cout << "\n=== Sistem Nilai Siswa (BST) ===\n";
        cout << "1. Tambah Nilai Siswa\n";
        cout << "2. Tampilkan Nilai (Inorder)\n";
        cout << "3. Nilai Minimum (Terendah)\n";
        cout << "4. Nilai Maksimum (Tertinggi)\n";
        cout << "5. Hitung Total Nilai (Count Nodes)\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nilai siswa: "; cin >> x;
            root = insertNode(root, x);
        } 
        else if (pilih == 2) {
            cout << "Nilai siswa (kecil ke besar): ";
            inorder(root);
            cout << "\n";
        } 
        else if (pilih == 3) {
            cout << "Nilai Terendah: " << findMin(root) << "\n";
        } 
        else if (pilih == 4) {
            cout << "Nilai Tertinggi: " << findMax(root) << "\n";
        } 
        else if (pilih == 5) {
            cout << "Total Data Nilai: " << countNodes(root) << "\n";
        }

    } while (pilih != 6);
    return 0;
}