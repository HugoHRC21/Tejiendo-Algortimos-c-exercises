//34. Escriba un algoritmo que transforme un árbol m-rio completo, representado con listas, en un arreglo secuencial.

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;
    Node(string v) : value(v) {}
};

vector<string> tree_to_array(Node* root, int m) {
    if (!root) return {};

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    vector<string> arr(100, "?");
    arr[0] = root->value;

    while (!q.empty()) {
        auto [node, index] = q.front();
        q.pop();

        for (int j = 0; j < node->children.size(); j++) {
            int child_index = m * index + (j + 1); 
            arr[child_index] = node->children[j]->value;
            q.push({node->children[j], child_index});
        }
    }

    return arr;
}

int main() {
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");

    A->children = {B, C, D};
    B->children = {E, F};

    int m = 3;

    vector<string> arr = tree_to_array(A, m);

    cout << "Árbol en arreglo secuencial: ";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != "?") cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
