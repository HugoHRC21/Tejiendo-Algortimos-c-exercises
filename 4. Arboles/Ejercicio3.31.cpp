// 57. Diseñe un algoritmo que encuentre el más largo camino por la derecha contenido en un
// árbol binario.

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
    Node(string v) : value(v), left(nullptr), right(nullptr) {}
};

vector<string> longest_right_path(Node* root) {
    vector<string> path;
    Node* current = root;

    while (current) {
        path.push_back(current->value);
        current = current->right;
    }
    return path;
}

int main() {
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");

    A->left = B;
    A->right = C;
    C->left = D;
    C->right = E;
    E->right = F;

    vector<string> path = longest_right_path(A);

    cout << "Camino más largo por la derecha: ";
    for (auto& node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
