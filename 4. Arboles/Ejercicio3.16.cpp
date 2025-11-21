// 20. Suponga un árbol binario cuyos nodos tienen un campo adicional llamado PLINK y que
// denota el nodo padre. Dado un nodo cualquiera p, diseñe algoritmos no recursivos y
// sin pila para:
// (a) Determinar el nodo predecesor y,
// (b) Determinar el nodo sucesor.

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent; 
    Node(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node* min_node(Node* p) {
    while (p && p->left) p = p->left;
    return p;
}

Node* max_node(Node* p) {
    while (p && p->right) p = p->right;
    return p;
}


Node* predecessor(Node* p) {
    if (!p) return nullptr;

    if (p->left) return max_node(p->left);

    Node* parent = p->parent;
    while (parent && p == parent->left) {
        p = parent;
        parent = parent->parent;
    }
    return parent;
}

Node* successor(Node* p) {
    if (!p) return nullptr;

    if (p->right) return min_node(p->right);

    Node* parent = p->parent;
    while (parent && p == parent->right) {
        p = parent;
        parent = parent->parent;
    }
    return parent;
}

int main() {
 
    Node* root = new Node(20);
    Node* n10 = new Node(10);
    Node* n30 = new Node(30);
    Node* n5  = new Node(5);
    Node* n15 = new Node(15);

    root->left = n10; n10->parent = root;
    root->right = n30; n30->parent = root;
    n10->left = n5; n5->parent = n10;
    n10->right = n15; n15->parent = n10;

    Node* p = n10; 
    Node* pred = predecessor(p);
    Node* succ = successor(p);

    cout << "Nodo actual: " << p->value << endl;
    cout << "Predecesor: " << (pred ? to_string(pred->value) : "Ninguno") << endl;
    cout << "Sucesor: "   << (succ ? to_string(succ->value) : "Ninguno") << endl;

    return 0;
}
