//35. Escriba un algoritmo que transforme un árbol binario completo en un arreglo secuencial.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
    Node(string v) : value(v), left(nullptr), right(nullptr) {}
};

void tree_to_array(Node* root, vector<string>& arr, int index) {
    if (!root) return;


    if (index >= arr.size()) {
        arr.resize(index + 1, "");
    }

    arr[index] = root->value;


    tree_to_array(root->left, arr, 2 * index + 1);
    tree_to_array(root->right, arr, 2 * index + 2);
}

int main() {

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* G = new Node("G");

    A->left = B; A->right = C;
    B->left = D; B->right = E;
    C->left = F; C->right = G;

    vector<string> arr;
    tree_to_array(A, arr, 0);

    cout << "Árbol binario completo en arreglo secuencial:" << endl;
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "Índice " << i << " → " << arr[i] << endl;
    }

    return 0;
}
