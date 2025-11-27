// 56. Diseñe un algoritmo que pode un árbol binario, es decir, que elimine la mínima
// cantidad de nodos para volverlo un árbol completo.
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};


void prune_to_complete(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    bool found_null = false;  

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left) {
            if (found_null) {
                current->left = nullptr;
            } else {
                q.push(current->left);
            }
        } else {
            found_null = true;
        }
        
        if (current->right) {
            if (found_null) {
                current->right = nullptr;
            } else {
                q.push(current->right);
            }
        } else {
            found_null = true;
        }
    }
}


void level_order(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->value << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);  // ← rompe el "completo"
    root->right->right = new Node(7);

    cout << "Antes de podar (por niveles): ";
    level_order(root);
    cout << endl;

    prune_to_complete(root);

    cout << "Despues de podar (por niveles): ";
    level_order(root);
    cout << endl;

    return 0;
}
