// 62. Dado un árbol binario de búsqueda, diseñe un algoritmo que construya una secuencia
// de inserción que reproduzca un árbol binario equivalente.

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* insert_bst(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->value)
        root->left = insert_bst(root->left, value);
    else
        root->right = insert_bst(root->right, value);
    return root;
}

void get_insertion_sequence(Node* root, vector<int>& sequence) {
    if (!root) return;
    sequence.push_back(root->value);        
    get_insertion_sequence(root->left, sequence);  
    get_insertion_sequence(root->right, sequence);
}

int main() {
    Node* root = nullptr;
    vector<int> values = {10, 5, 1, 7, 40, 50};
    for (int v : values) {
        root = insert_bst(root, v);
    }

    vector<int> insertion_sequence;
    get_insertion_sequence(root, insertion_sequence);

    cout << "Secuencia de inserción que reproduce el ABB: ";
    for (int v : insertion_sequence) cout << v << " ";
    cout << endl;

    return 0;
}
