// 92. Suponga que cada nodo posee un campo adicional next. Escriba un algoritmo que
// enlace todos nodos del árbol según el recorrido infijo.

#include <iostream>
using namespace std;

// Estructura del nodo con campo "next"
struct Node {
    char value;
    Node* left;
    Node* right;
    Node* next;  // Enlace al siguiente nodo en orden infijo

    Node(char v) : value(v), left(nullptr), right(nullptr), next(nullptr) {}
};

// Función auxiliar recursiva
void link_inorder(Node* root, Node*& prev) {
    if (!root) return;


    link_inorder(root->left, prev);

    if (prev) {
        prev->next = root;
    }
    prev = root;

    link_inorder(root->right, prev);
}


void create_inorder_links(Node* root) {
    Node* prev = nullptr;
    link_inorder(root, prev);
}


void print_inorder_links(Node* root) {
    Node* current = root;
    while (current && current->left) {
        current = current->left;
    }

    cout << "Enlaces infijos: ";
    while (current) {
        cout << current->value;
        if (current->next) cout << " → ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;


    create_inorder_links(A);


    print_inorder_links(A);

    return 0;
}
