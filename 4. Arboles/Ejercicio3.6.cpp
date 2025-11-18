#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;
    Node(string v) : value(v) {}
};


void postorder_traversal(Node* root) {
    if (!root) return;

    for (Node* child : root->children) {
        postorder_traversal(child);
    }
    cout << root->value << " ";
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

    cout << "Recorrido en sufijo (postorden): ";
    postorder_traversal(A);
    cout << endl;
}
