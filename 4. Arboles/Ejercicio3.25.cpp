//36. Escriba una versión no recursiva del algoritmo que calcula la altura de un árbol binario.

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

int tree_height(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int height = 0;

    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            Node* current = q.front();
            q.pop();
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        height++; 
    }

    return height;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Altura del arbol: " << tree_height(root) << endl;

    return 0;
}
