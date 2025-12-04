// 91. Diseñe un algoritmo que cuente la cantidad de nodos llenos de un árbol binario

#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

int count_full_nodes(Node* root) {
    if (!root) return 0;  

    int count = 0;
    if (root->left && root->right) {
        count = 1;
    }

    return count + count_full_nodes(root->left) + count_full_nodes(root->right);
}

int main() {

    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    cout << "Cantidad de nodos llenos: " << count_full_nodes(A) << endl;

    return 0;
}
