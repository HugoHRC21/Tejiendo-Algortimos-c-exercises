// 25. Diseñe un algoritmo O(n lg(n)) que efectúe la partición (split) de un treap

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


void split(Node* T, int x, Node*& TL, Node*& TR) {
    if (T == nullptr) {
        TL = TR = nullptr;
        return;
    }

    if (T->key < x) {
        // T va al lado izquierdo
        split(T->right, x, T->right, TR);
        TL = T;
    } else {
        // T va al lado derecho
        split(T->left, x, TL, T->left);
        TR = T;
    }
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

    Node* T = nullptr;

    // Insertamos claves en el treap
    vector<int> keys = {50, 30, 20, 40, 80, 70, 90};

    for (int x : keys)
        T = insertTreap(T, x, rng);

    cout << "Treap original:\n";
    printTreap(T);
    cout << "\n\n";

    // Realizar split
    Node *TL, *TR;
    int x = 60;

    split(T, x, TL, TR);

    cout << "TL (claves < " << x << "):\n";
    printTreap(TL);
    cout << "\n\n";

    cout << "TR (claves >= " << x << "):\n";
    printTreap(TR);
    cout << "\n";

    return 0;
}
