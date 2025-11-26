//43. Escriba un programa que recorra un árbol binario por niveles de derecha a izquierda.

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void level_order_right_to_left(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->value << " ";

        if (current->right) q.push(current->right);
        if (current->left) q.push(current->left);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Recorrido por niveles (derecha a izquierda): ";
    level_order_right_to_left(root);
    cout << endl;

    return 0;
}
