//119. Diseñe un algoritmo iterativo eciente que efectúe la intersección de dos árboles binarios. (+)

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int value) {
    Node** curr = &root;
    while (*curr) {
        if (value < (*curr)->value)
            curr = &((*curr)->left);
        else if (value > (*curr)->value)
            curr = &((*curr)->right);
        else
            return;
    }
    *curr = new Node(value);
}

Node* intersection_trees(Node* rootA, Node* rootB) {
    if (!rootA || !rootB) return nullptr;

    stack<Node*> s1, s2;
    Node* a = rootA;
    Node* b = rootB;

    Node* result = nullptr; 
    Node** tail = &result;

    while ((a || !s1.empty()) && (b || !s2.empty())) {
        while (a) {
            s1.push(a);
            a = a->left;
        }
        while (b) {
            s2.push(b);
            b = b->left;
        }

        a = s1.top();
        b = s2.top();

        if (a->value == b->value) {
            *tail = new Node(a->value);
            tail = &((*tail)->right);

            s1.pop(); a = a->right;
            s2.pop(); b = b->right;
        }
        else if (a->value < b->value) {
            s1.pop();
            a = a->right;
            b = nullptr; 
        }
        else {
            s2.pop();
            b = b->right;
            a = nullptr;
        }
    }

    return result;
}
void print_inorder(Node* root) {
    if (!root) return;
    print_inorder(root->left);
    cout << root->value << " ";
    print_inorder(root->right);
}

int main() {
    Node* A = nullptr;
    Node* B = nullptr;

    // Árbol A
    insert(A, 5);
    insert(A, 3);
    insert(A, 8);
    insert(A, 2);
    insert(A, 4);

    // Árbol B
    insert(B, 7);
    insert(B, 5);
    insert(B, 9);
    insert(B, 3);

    cout << "Árbol A (inorden): ";
    print_inorder(A);
    cout << endl;

    cout << "Árbol B (inorden): ";
    print_inorder(B);
    cout << endl;

    Node* I = intersection_trees(A, B);
    cout << "Intersección (inorden): ";
    print_inorder(I);
    cout << endl;

    return 0;
}
