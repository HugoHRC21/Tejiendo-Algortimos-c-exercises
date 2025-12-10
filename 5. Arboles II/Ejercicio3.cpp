// 10. Diseñe un algoritmo que genere un árbol de búsqueda aleatorio, 
// es decir, que corresponda a la definición de árbol aleatorio dada en § 6.2.

#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct Node {
    int key;
    int size;
    Node* left;
    Node* right;
    Node(int k) : key(k), size(1), left(nullptr), right(nullptr) {}
};

int subtreeSize(Node* t) {
    return t ? t->size : 0;
}

void update(Node* t) {
    if (t)
        t->size = 1 + subtreeSize(t->left) + subtreeSize(t->right);
}

void printTree(Node* root, int space = 0, int indent = 6) {
    if (root == nullptr) return;

    space += indent;
    printTree(root->right, space);
    cout << "\n";
    for (int i = indent; i < space; i++)
        cout << " ";
    cout << root->key << "\n";
    printTree(root->left, space);
}


Node* generarABBA(const vector<int>& S, int l, int r, mt19937& rng) {
    if (l > r) return nullptr;

    uniform_int_distribution<int> dist(l, r);
    int idx = dist(rng);    

    Node* root = new Node(S[idx]);

    root->left  = generarABBA(S, l, idx - 1, rng);
    root->right = generarABBA(S, idx + 1, r, rng);

    update(root);
    return root;
}

int main() {
    vector<int> S = {1, 2, 3, 4, 5, 6, 7}; 

    random_device rd;
    mt19937 rng(rd());

    Node* T = generarABBA(S, 0, S.size() - 1, rng);

    cout << "ABBA generado exitosamente:\n\n";

    printTree(T);     

    return 0;
}
