// 106. Diseñe un algoritmo recursivo, basado en rotaciones, que efectúe la inserción por la raíz
// en un ABB. El algoritmo debe buscar el nodo externo que albergaría al nuevo nodo y
// después rotar recursivamente a su padre hasta que éste devenga en raíz.

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* rotate_right(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    return x; 
}

Node* rotate_left(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y; 
}


Node* insert_root(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }

    if (key == root->key) {
        return root;
    }

    if (key < root->key) {
        root->left = insert_root(root->left, key);
        root = rotate_right(root);
    } else {
        root->right = insert_root(root->right, key);
        root = rotate_left(root);
    }

    return root;
}

Node* insert_normal(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert_normal(root->left, key);
    else if (key > root->key) root->right = insert_normal(root->right, key);
    return root;
}

void inorder_print(Node* root) {
    if (!root) return;
    inorder_print(root->left);
    cout << root->key << " ";
    inorder_print(root->right);
}

void preorder_print(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert_normal(root, 50);
    root = insert_normal(root, 30);
    root = insert_normal(root, 70);
    root = insert_normal(root, 20);
    root = insert_normal(root, 40);
    root = insert_normal(root, 60);
    root = insert_normal(root, 80);

    cout << "Árbol inicial (inorden): ";
    inorder_print(root);
    cout << endl;

    cout << "Árbol inicial (preorden): ";
    preorder_print(root);
    cout << endl << endl;

    int key_to_insert = 35;
    cout << "Insertando por la raiz la clave " << key_to_insert << " ..." << endl;
    root = insert_root(root, key_to_insert);

    cout << "Árbol tras insert_root (inorden): ";
    inorder_print(root);
    cout << endl;

    cout << "Árbol tras insert_root (preorden): ";
    preorder_print(root);
    cout << endl << endl;

    root = insert_root(root, 25);
    cout << "Tras insertar 25 (preorden): ";
    preorder_print(root);
    cout << endl;

    return 0;
}
