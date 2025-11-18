#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;
    Node(string v) : value(v) {}
};

// este fue mas encillo, es incrementar un contador e medida que ibamos
// recorreindo cada hijo pero lo hacemos de manera recursiva hasta que ya no haya mas que contar

int count_nodes(Node* root) {
    if (!root) return 0;

    int total = 1; 
    for (Node* child : root->children) {
        total += count_nodes(child); 
    }
    return total;
}

int main() {

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");

    A->children = {B, C, D};
    C->children = {E, F};

    cout << "Número de nodos en el árbol: " << count_nodes(A) << endl;
}
