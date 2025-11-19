#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;
    Node(string v) : value(v) {}
};

void print_parenthesized(Node* root) {
    if (!root) return;

    cout << root->value;

    if (!root->children.empty()) {
        cout << "(";

        for (size_t i = 0; i < root->children.size(); ++i) {
            print_parenthesized(root->children[i]);
            if (i < root->children.size() - 1) {
                cout << " ";
            }
        }
        cout << ")";
    }
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

    cout << "Representacion parentizada del arbol: ";
    print_parenthesized(A);
    cout << endl;

    return 0;
}