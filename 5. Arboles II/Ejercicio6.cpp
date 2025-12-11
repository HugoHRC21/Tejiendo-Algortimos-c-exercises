// 17. Diseñe un algoritmo que efectúe la eliminación por posición en un árbol aleatorizado.
// El árbol resultante debe ser aleatorio. Demuestre su respuesta. (+)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int priority;
    int size;
    Node* left;
    Node* right;

    Node(int k, int p) : key(k), priority(p), size(1), left(nullptr), right(nullptr) {}
};

int getSize(Node* t) { return t ? t->size : 0; }

void update(Node* t) {
    if (t) t->size = 1 + getSize(t->left) + getSize(t->right);
}


void splitByPosition(Node* t, int k, Node*& L, Node*& R) {
    if (!t) { L = R = nullptr; return; }

    int leftSize = getSize(t->left);

    if (k <= leftSize) {
        splitByPosition(t->left, k, L, t->left);
        R = t;
    } else {
        splitByPosition(t->right, k - leftSize - 1, t->right, R);
        L = t;
    }
    update(t);
}


Node* merge(Node* A, Node* B) {
    if (!A) return B;
    if (!B) return A;

    if (A->priority > B->priority) {
        A->right = merge(A->right, B);
        update(A);
        return A;
    }
    else {
        B->left = merge(A, B->left);
        update(B);
        return B;
    }
}


Node* eraseAt(Node* t, int pos) {
    Node *A, *BC, *B, *C;

    splitByPosition(t, pos, A, BC);

    splitByPosition(BC, 1, B, C);

    delete B; 

    return merge(A, C);
}

void printTree(Node* root, int space = 0, int indent = 6) {
    if (!root) return;

    space += indent;
    printTree(root->right, space);

    cout << "\n";
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->key << " (p=" << root->priority << ")";

    printTree(root->left, space);
}

int main() {
    mt19937 rng(987);

    Node* T = nullptr;

    uniform_int_distribution<int> pr(1, 1000000);

    auto insertEnd = [&](int key) {
        Node* newNode = new Node(key, pr(rng));
        T = merge(T, newNode);
    };

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    cout << "\nÁrbol original:\n";
    printTree(T);

    T = eraseAt(T, 2);

    cout << "\n\nÁrbol tras eliminar posición 2:\n";
    printTree(T);
    cout << endl;

    return 0;
}
