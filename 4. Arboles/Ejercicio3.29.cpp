// 54. Diseñe un algoritmo que imprima el recorrido por niveles inverso de un árbol binario.
// Es decir, primero se listan de izquierda a derecha los nodos del último nivel; luego, los
// del penúltimo y así sucesivamente hasta llegar a la raíz

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void reverse_level_order(Node* root) {
    if (!root) return;

    queue<Node*> q; 
    stack<Node*> s; 

    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        s.push(current);

        if (current->right) q.push(current->right);
        if (current->left) q.push(current->left);
    }

    while (!s.empty()) {
        cout << s.top()->value << " ";
        s.pop();
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

    cout << "Recorrido por niveles inverso: ";
    reverse_level_order(root);
    cout << endl;

    return 0;
}
