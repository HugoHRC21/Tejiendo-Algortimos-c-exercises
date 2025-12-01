// 60. Diseñe un algoritmo que genere un árbol binario aleatorio de n nodos. La cantidad n
// es un parámetro del algoritmo y todos los árboles deben tener la misma probabilidad
// (++).

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* generate_random_tree(int n, int& counter) {
    if (n == 0) return nullptr;

    Node* root = new Node(counter++);

    int left_nodes = rand() % n;
    int right_nodes = n - 1 - left_nodes;
    root->left = generate_random_tree(left_nodes, counter);
    root->right = generate_random_tree(right_nodes, counter);

    return root;
}

void print_preorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main() {
    srand(time(0));

    int n = 7; 
    int counter = 1; 

    Node* root = generate_random_tree(n, counter);

    cout << "Árbol binario aleatorio en preorden: ";
    print_preorder(root);
    cout << endl;

    return 0;
}
