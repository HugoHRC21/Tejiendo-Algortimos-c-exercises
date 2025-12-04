// 90. Diseñe un algoritmo que cuente la cantidad de nodos incompletos no hojas de un árbol
// binario.
#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

int count_incomplete_non_leaf_nodes(Node* root) {
    if (!root) return 0; 

    if (!root->left && !root->right) return 0;

    int count = 0;

    if ((root->left && !root->right) || (!root->left && root->right)) {
        count = 1;
    }

    return count 
           + count_incomplete_non_leaf_nodes(root->left)
           + count_incomplete_non_leaf_nodes(root->right);
}

int main() {

    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');

    A->left = B;  A->right = C;
    B->left = D;
    C->right = E;
    E->left = F;

    cout << "Cantidad de nodos incompletos no hojas: "
         << count_incomplete_non_leaf_nodes(A) << endl;

    return 0;
}
