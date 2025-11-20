#include <iostream>
#include <stack> 

using namespace std;
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

void preorder_non_recursive(Node* root) {

    if (root == nullptr) {
        return;
    }
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {

        Node* current = s.top();
        s.pop();

        cout << current->value << " ";

        if (current->right != nullptr) {
            s.push(current->right);
        }
        if (current->left != nullptr) {
            s.push(current->left);
        }
    }
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

    cout << "Recorrido en preorden (no recursivo): ";
    preorder_non_recursive(A);
    cout << endl;

    stack<Node*> destroy_stack;
    destroy_stack.push(A);
    while (!destroy_stack.empty()) {
        Node* current = destroy_stack.top();
        destroy_stack.pop();
        if (current->left != nullptr) destroy_stack.push(current->left);
        if (current->right != nullptr) destroy_stack.push(current->right);
        delete current;
    }

    return 0;
}