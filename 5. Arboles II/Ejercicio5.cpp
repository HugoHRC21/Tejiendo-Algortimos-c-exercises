// 16. Diseñe un algoritmo que efectúe la inserción por posición en un árbol aleatorizado. El
// árbol resultante debe ser aleatorio. Demuestre su respuesta. (+)

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

int getSize(Node* t) {
    return t ? t->size : 0;
}

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

Node* merge(Node* L, Node* R) {
    if (!L) return R;
    if (!R) return L;

    if (L->priority > R->priority) {
        L->right = merge(L->right, R);
        update(L);


        return L;
    } else {
        R->left = merge(L, R->left);
        update(R);
        return R;
    }
}

Node* insertAt(Node* t, int pos, int key, mt19937& rng) {
    uniform_int_distribution<int> dist(1, 1000000000);
    Node* newNode = new Node(key, dist(rng));

    Node *L, *R;
    splitByPosition(t, pos, L, R);
    return merge(merge(L, newNode), R);
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
    mt19937 rng(123);  
    Node* T = nullptr;

    T = insertAt(T, 0, 10, rng);  
    T = insertAt(T, 1, 20, rng);  
    T = insertAt(T, 1, 15, rng);  
    T = insertAt(T, 0, 5, rng);   
    T = insertAt(T, 4, 30, rng); 
    T = insertAt(T, 2, 99, rng); 

    cout << "\nÁrbol aleatorizado resultante:\n";
    printTree(T);
    cout << endl;

    return 0;
}
