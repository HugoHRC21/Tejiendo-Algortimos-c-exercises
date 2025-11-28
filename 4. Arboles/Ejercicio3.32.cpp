// 58. Diseñe un algoritmo que genere un árbol binario de n nodos donde n es un valor
// constante (+).

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* generate_binary_tree(int n) {
    if (n <= 0) return nullptr;

    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(new Node(i + 1));
    }

    for (int i = 0; i < n; i++) {
        int left_index = 2 * i + 1;
        int right_index = 2 * i + 2;

        if (left_index < n) nodes[i]->left = nodes[left_index];
        if (right_index < n) nodes[i]->right = nodes[right_index];
    }

    return nodes[0]; 
}

void print_level_order(Node* root) {
    if (!root) return;
    vector<Node*> q = {root};
    while (!q.empty()) {
        vector<Node*> next;
        for (Node* node : q) {
            cout << node->value << " ";
            if (node->left) next.push_back(node->left);
            if (node->right) next.push_back(node->right);
        }
        q = next;
    }
}

int main() {
    int n = 10; 
    Node* root = generate_binary_tree(n);

    cout << "Árbol binario con " << n << " nodos (recorrido por niveles): ";
    print_level_order(root);
    cout << endl;

    return 0;
}
