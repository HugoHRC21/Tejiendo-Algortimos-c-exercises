//22.Diseñe una rutina recursiva que recorra por niveles un árbol binario y use espacio O(1)

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void print_level(Node* root, int level) {
    if (!root) return;
    if (level == 1) {
        cout << root->value << " ";
    } else {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

void level_order(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        print_level(root, i);
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

    cout << "Recorrido por niveles: ";
    level_order(root);
    cout << endl;

    return 0;
}

