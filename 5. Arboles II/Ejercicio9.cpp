// 24. Diseñe un algoritmo O(n lg(n)) que efectúe la intersección de dos treaps

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int priority;
    Node* left;
    Node* right;

    Node(int k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
};

Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* insertTreap(Node* root, int key, mt19937& rng) {
    if (!root)
        return new Node(key, uniform_int_distribution<int>(1, 1e9)(rng));

    if (key < root->key) {
        root->left = insertTreap(root->left, key, rng);
        if (root->left->priority > root->priority)
            root = rotateRight(root);
    } else {
        root->right = insertTreap(root->right, key, rng);
        if (root->right->priority > root->priority)
            root = rotateLeft(root);
    }
    return root;
}

void inorder(Node* t, vector<int>& out) {
    if (!t) return;
    inorder(t->left, out);
    out.push_back(t->key);
    inorder(t->right, out);
}

vector<int> intersectArrays(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            C.push_back(A[i]);
            i++; j++;
        }
        else if (A[i] < B[j]) i++;
        else j++;
    }
    return C;
}

Node* treapIntersection(Node* T1, Node* T2) {
    // 1. obtener claves ordenadas
    vector<int> A1, A2;
    inorder(T1, A1);
    inorder(T2, A2);

    // 2. intersección
    vector<int> C = intersectArrays(A1, A2);

    // 3. reconstruir treap aleatorio
    mt19937 rng(12345);
    Node* R = nullptr;
    for (int x : C)
        R = insertTreap(R, x, rng);

    return R;
}

void printTreap(Node* root, int space = 0, int indent = 6) {
    if (!root) return;
    space += indent;

    printTreap(root->right, space);
    cout << "\n";
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->key << "(" << root->priority << ")";

    printTreap(root->left, space);
}

int main() {
    mt19937 rng(123);

    Node* T1 = nullptr;
    Node* T2 = nullptr;

    // Treap 1
    T1 = insertTreap(T1, 5, rng);
    T1 = insertTreap(T1, 10, rng);
    T1 = insertTreap(T1, 20, rng);
    T1 = insertTreap(T1, 25, rng);

    // Treap 2
    T2 = insertTreap(T2, 10, rng);


    T2 = insertTreap(T2, 15, rng);
    T2 = insertTreap(T2, 20, rng);

    cout << "T1:\n";
    printTreap(T1);

    cout << "\n\nT2:\n";
    printTreap(T2);

    Node* I = treapIntersection(T1, T2);

    cout << "\n\nINTERSECCIÓN T1 ∩ T2:\n";
    printTreap(I);
    cout << "\n";

    return 0;
}
