// 63. Diseñe e implante un algoritmo que liste los rangos de claves que no se encuentran en
// el árbol.

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

void inorder(Node* root, vector<int>& keys) {
    if (!root) return;
    inorder(root->left, keys);
    keys.push_back(root->key);
    inorder(root->right, keys);
}

void list_missing_ranges(Node* root) {
    vector<int> keys;
    inorder(root, keys);

    cout << "Rangos faltantes: ";
    bool found = false;
    for (size_t i = 0; i + 1 < keys.size(); i++) {
        if (keys[i+1] > keys[i] + 1) {
            int start = keys[i] + 1;
            int end = keys[i+1] - 1;
            cout << "[" << start << "–" << end << "] ";
            found = true;
        }
    }
    if (!found) cout << "Ninguno";
    cout << endl;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 8);

    list_missing_ranges(root);

    return 0;
}
