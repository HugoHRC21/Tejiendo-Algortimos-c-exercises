// 4. Para los siguientes árboles aleatorios, denidos por sus recorridos prejos, ejecute las
// secuencias de eliminación dadas:
// (a) Prejo: 46 11 18 151 102 83 55 70 61 63 79 103 125 124 140 148 173 162 160 181
// Secuencia de eliminación: 125 148 18 11 79 124 140 181 102 173
// (b) Prejo: 195 193 105 40 33 5 31 22 50 61 68 62 76 159 151 146 112 137 165 199
// Secuencia de eliminación: 31 68 165 22 159 105 112 61 199 151
// (c) Prejo: 132 48 37 28 12 9 95 76 55 70 82 106 102 97 153 135 195 171 165 177
// Secuencia de eliminación: 165 177 171 9 76 28 195 48 55 37
// (d) Prejo: 96 89 59 28 21 13 46 30 83 87 174 147 132 109 101 99 162 150 157 19
// Secuencia de eliminación: 28 132 13 99 101 150 87 174 157 96
// (e) Prejo: 190 63 43 37 13 3 28 38 55 51 184 177 90 124 122 168 138 162 187 196
// Secuencia de eliminación: 90 37 124 190 51 28 122 168 3 13
// Para todos los ejercicios asuma la siguiente secuencia de números aleatorios entre 1 y
// 100:
// 1 83 9 84 64 46 100 65 7 43 20 63 26 61 100 95 95 60 75 50 19 51 21 29 90 69 80 93 71 52 34 40
// 34 29 67 63 39 57 93 70 31 82 67 93 47 12 99 67 4 59 75 41 93 93 21 93 52 49 50 93 100 39 58 6
// 95 68 45 63 10 13 4 100 85 1 3 70 77 43 94 35 8 56 71 69 96 80 30 30 85 59 68 35 29 34 97 15
// 29 44 79 71 26 47 12 67 94 27 30 80 39 79 32 3 49 65 66 89 45 66 93 68 69 81 85 99 86 44 18 80
// 50 19 69 90 96 35 12 1 72 21 26 27 29 55 52 62 50 19 50 46 68 71

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

struct Node {
    int key;        // valor del nodo (de la secuencia prefijo)
    int priority;   // prioridad (de la secuencia aleatoria)
    Node *left, *right;
    Node(int k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
};

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

// --- Inserción en el treap ---
Node* insert(Node* root, int key, int priority) {
    if (!root) return new Node(key, priority);

    if (key < root->key)
        root->left = insert(root->left, key, priority);
    else
        root->right = insert(root->right, key, priority);

    // Rebalanceo según prioridades (heap)
    if (root->left && root->left->priority > root->priority)
        root = rotateRight(root);
    else if (root->right && root->right->priority > root->priority)
        root = rotateLeft(root);

    return root;
}

// --- Eliminación en el treap ---
Node* erase(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = erase(root->left, key);
    else if (key > root->key)
        root->right = erase(root->right, key);
    else {
        // Caso encontrado
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else {
            // Rotamos con el hijo de mayor prioridad
            if (root->left->priority > root->right->priority) {
                root = rotateRight(root);
                root->right = erase(root->right, key);
            } else {
                root = rotateLeft(root);
                root->left = erase(root->left, key);
            }
        }
    }
    return root;
}

// --- Mostrar árbol (inorden, para ver BST ordenado) ---
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "(" << root->key << "," << root->priority << ") ";
    inorder(root->right);
}

// --- MAIN ---
int main() {
    // EJEMPLO: inciso (a)
    vector<int> pre = {46, 11, 18, 151, 102, 83, 55, 70, 61, 63, 79, 103, 125, 124, 140, 148, 173, 162, 160, 181};
    vector<int> eliminaciones = {125, 148, 18, 11, 79, 124, 140, 181, 102, 173};

    // Secuencia de números aleatorios dada (completa en el enunciado)
    vector<int> aleatorios = {
        1,83,9,84,64,46,100,65,7,43,20,63,26,61,100,95,95,60,75,50,
        19,51,21,29,90,69,80,93,71,52,34,40,34,29,67,63,39,57,93,70,
        31,82,67,93,47,12,99,67,4,59,75,41,93,93,21,93,52,49,50,93,
        100,39,58,6,95,68,45,63,10,13,4,100,85,1,3,70,77,43,94,35,
        8,56,71,69,96,80,30,30,85,59,68,35,29,34,97,15,29,44,79,71,
        26,47,12,67,94,27,30,80,39,79,32,3,49,65,66,89,45,66,93,68,
        69,81,85,99,86,44,18,80,50,19,69,90,96,35,12,1,72,21,26,27,
        29,55,52,62,50,19,50,46,68,71
    };

    Node* root = nullptr;
    int idx = 0;

    // Insertamos en orden del prefijo
    for (int k : pre)
        root = insert(root, k, aleatorios[idx++]);

    cout << "Árbol inicial (inorden):\n";
    inorder(root);
    cout << "\n\n";

    // Ejecutamos las eliminaciones
    for (int x : eliminaciones) {
        cout << "Eliminando " << x << "...\n";
        root = erase(root, x);
        inorder(root);
        cout << "\n\n";
    }

    return 0;
}
