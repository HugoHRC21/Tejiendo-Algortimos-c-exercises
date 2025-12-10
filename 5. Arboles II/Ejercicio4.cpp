// 14. Diseñe un algoritmo de unión de dos árboles aleatorios T1 y T2 tal que claves
// pertenecientes a T1 pueden ser mayores que algunas claves pertenecientes a T2. El
// algoritmo debe ser O(n lg(n)).

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


Node* rotateRight(Node* t) {
    Node* L = t->left;
    t->left = L->right;
    L->right = t;
    update(t);
    update(L);
    return L;
}

Node* rotateLeft(Node* t) {
    Node* R = t->right;
    t->right = R->left;
    R->left = t;
    update(t);
    update(R);
    return R;
}


Node* insertRoot(Node* t, int key) {
    if (!t) return new Node(key);

    if (key < t->key) {
        t->left = insertRoot(t->left, key);
        return rotateRight(t);
    } else {
        t->right = insertRoot(t->right, key);
        return rotateLeft(t);
    }
}

Node* insertRandom(Node* t, int key, mt19937& rng) {
    if (!t) return new Node(key);

    uniform_int_distribution<int> dist(0, t->size);

    if (dist(rng) == 0)
        return insertRoot(t, key);

    if (key < t->key)
        t->left = insertRandom(t->left, key, rng);
    else
        t->right = insertRandom(t->right, key, rng);

    update(t);
    return t;
}


void toVector(Node* t, vector<int>& v) {
    if (!t) return;
    toVector(t->left, v);
    v.push_back(t->key);
    toVector(t->right, v);
}


Node* unionABBA(Node* T1, Node* T2, mt19937& rng) {
    vector<int> elements;
    toVector(T2, elements); // O(n)

    for (int x : elements)
        T1 = insertRandom(T1, x, rng); // O(log n) promedio

    return T1;
}


void printTree(Node* root, int space = 0, int indent = 6) {
    if (!root) return;

    space += indent;
    printTree(root->right, space);

    cout << "\n";
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->key << "\n";

    printTree(root->left, space);
}


int main() {
    random_device rd;
    mt19937 rng(rd());

    Node* T1 = nullptr;
    Node* T2 = nullptr;

    vector<int> A = {1, 5, 9, 12, 20};
    for (int x : A)
        T1 = insertRandom(T1, x, rng);

    vector<int> B = {7, 3, 25, 2, 11};
    for (int x : B)
        T2 = insertRandom(T2, x, rng);

    cout << "T1:\n";
    printTree(T1);

    cout << "\nT2:\n";
    printTree(T2);

    Node* T = unionABBA(T1, T2, rng);
    cout << "\nÁRBOL UNIDO T = T1 ∪ T2:\n";
    printTree(T);

    return 0;
}
