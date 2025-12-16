// 23. Diseñe un algoritmo O(n lg(n)) que efectúe la unión de dos treaps.

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
    }
    else {
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

vector<int> mergeArrays(const vector<int>& A, const vector<int>& B) {
    vector<int> M;
    M.reserve(A.size() + B.size());

    size_t i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) M.push_back(A[i++]);
        else M.push_back(B[j++]);
    }
    while (i < A.size()) M.push_back(A[i++]);
    while (j < B.size()) M.push_back(B[j++]);

    return M;
}

Node* treapUnion(Node* T1, Node* T2) {
    vector<int> A1, A2;
    inorder(T1, A1);
    inorder(T2, A2);

    vector<int> M = mergeArrays(A1, A2);

    mt19937 rng(123456);
    Node* T = nullptr;
    for (int x : M)
        T = insertTreap(T, x, rng);

    return T;
}

void printTree(Node* root, int space = 0, int indent = 6) {
    if (!root) return;
    space += indent;

    printTree(root->right, space);
    cout << "\n";
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->key << "(" << root->priority << ")";

    printTree(root->left, space);
}

int main() {
    mt19937 rng(123);

    Node* T1 = nullptr;
    T1 = insertTreap(T1, 10, rng);
    T1 = insertTreap(T1, 5, rng);
    T1 = insertTreap(T1, 20, rng);

    Node* T2 = nullptr;
    T2 = insertTreap(T2, 7, rng);
    T2 = insertTreap(T2, 30, rng);
    T2 = insertTreap(T2, 1, rng);

    cout << "T1:\n";
    printTree(T1);

    cout << "\n\nT2:\n";
    printTree(T2);

    Node* U = treapUnion(T1, T2);

    cout << "\n\nUNIÓN T1 ∪ T2:\n";
    printTree(U);
    cout << "\n";

    return 0;
}
