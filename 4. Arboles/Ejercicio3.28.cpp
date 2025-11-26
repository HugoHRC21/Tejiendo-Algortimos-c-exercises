// 47. Diseñe un algoritmo que tome de entrada un árbol binario y construya un conjunto
// compuesto por todos los nodos representados en números de Deway.

#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
    Node(string v) : value(v), left(nullptr), right(nullptr) {}
};

void generate_dewey(Node* root, string code, set<string>& dewey_set) {
    if (!root) return;

    dewey_set.insert(code);

    if (root->left) {
        generate_dewey(root->left, code + ".1", dewey_set);
    }
    if (root->right) {
        generate_dewey(root->right, code + ".2", dewey_set);
    }
}

int main() {
    Node* root = new Node("A");
    root->left = new Node("B");
    root->right = new Node("C");
    root->left->left = new Node("D");
    root->left->right = new Node("E");
    root->right->left = new Node("F");
    root->right->right = new Node("G");

    set<string> dewey_numbers;
    generate_dewey(root, "1", dewey_numbers);

    cout << "Conjunto de números de Dewey:" << endl;
    for (const auto& num : dewey_numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
