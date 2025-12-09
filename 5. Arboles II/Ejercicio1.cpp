// 3. Ejecute las siguientes secuencias de inserción en un árbol aleatorio.
// (a) 127 193 30 71 158 185 40 12 35 94 116 110 139 57 81 95 181 114 112 171
// (b) 143 118 34 111 125 61 101 45 126 38 12 41 199 54 21 166 136 154 188 174
// (c) 148 176 182 108 141 44 173 128 102 65 139 192 37 188 116 88 165 162 9 91
// (d) 108 67 109 76 83 175 140 136 35 168 62 181 100 112 197 92 1 173 180 33
// (e) 123 193 13 15 50 115 160 25 45 136 79 3 1 14 178 108 62 57 101 75
// Para todas las secuencias, asuma la siguiente secuencia de números aleatorios entre 1
// y 100:
// 43 19 46 43 6 28 11 5 10 35 4 38 23 48 3 17 30 31 41 12 35 32 44 47 40 46 3 44 32 19 9 39 38
// 19 28 12 13 18 36 11 50 9 33 44 6 8 29 6 48 13 30 21 16 48 3 14 39 9 1 31 23 48 40 46 34 30 43
// 3 40 4 15 36 40 41 30 26 44 23 34 50 33 10 49 22 9 37 32 47 26 19 40 39 12 10 5 10 26 36 49 24
// 21 28 1 48 24 7 14 39 38 42 45 20 5 40 5 31 20 9 50 7 35 13 7 13 19 50 35 45 9 39 3 34 32 17 45
// 19 41 40 32 8 24 9 17 48 12 44 24 7 33 25


#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key, priority;
    Node *left, *right;
    Node(int k, int p): key(k), priority(p), left(nullptr), right(nullptr) {}
};

// Rotaciones
void rotateRight(Node* &root) {
    Node* L = root->left;
    root->left = L->right;
    L->right = root;
    root = L;
}

void rotateLeft(Node* &root) {
    Node* R = root->right;
    root->right = R->left;
    R->left = root;
    root = R;
}

// Inserción en árbol aleatorio (Treap)
void insert(Node* &root, int key, int priority) {
    if (!root) {
        root = new Node(key, priority);
        return;
    }
    if (key < root->key) {
        insert(root->left, key, priority);
        if (root->left && root->left->priority < root->priority)
            rotateRight(root);
    } else {
        insert(root->right, key, priority);
        if (root->right && root->right->priority < root->priority)
            rotateLeft(root);
    }
}

// Recorrido inorder (ordenado por clave)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << "(" << root->priority << ") ";
    inorder(root->right);
}

// Liberar memoria
void destroy(Node* &root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
    root = nullptr;
}

int main() {
    vector<int> randoms = {
        43,19,46,43,6,28,11,5,10,35,4,38,23,48,3,17,30,31,41,12,
        35,32,44,47,40,46,3,44,32,19,9,39,38,19,28,12,13,18,36,11,
        50,9,33,44,6,8,29,6,48,13,30,21,16,48,3,14,39,9,1,31,23,48,
        40,46,34,30,43,3,40,4,15,36,40,41,30,26,44,23,34,50,33,10,
        49,22,9,37,32,47,26,19,40,39,12,10,5,10,26,36,49,24,21,28
    };

    vector<vector<int>> sequences = {
        {127,193,30,71,158,185,40,12,35,94,116,110,139,57,81,95,181,114,112,171},
        {143,118,34,111,125,61,101,45,126,38,12,41,199,54,21,166,136,154,188,174},
        {148,176,182,108,141,44,173,128,102,65,139,192,37,188,116,88,165,162,9,91},
        {108,67,109,76,83,175,140,136,35,168,62,181,100,112,197,92,1,173,180,33},
        {123,193,13,15,50,115,160,25,45,136,79,3,1,14,178,108,62,57,101,75}
    };

    int rand_index = 0;

    for (int i = 0; i < sequences.size(); ++i) {
        cout << "\nSecuencia (" << char('a' + i) << "):\n";
        Node* root = nullptr;
        for (int key : sequences[i]) {
            if (rand_index >= randoms.size()) {
                cout << "Error: no hay suficientes números aleatorios\n";
                return 1;
            }
            insert(root, key, randoms[rand_index++]);
        }

        cout << "Recorrido inorder (clave(prioridad)):\n";
        inorder(root);
        cout << "\n";
        destroy(root);
    }

    return 0;
}
