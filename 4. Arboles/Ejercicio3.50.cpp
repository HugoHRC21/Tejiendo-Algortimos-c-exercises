// 117. Diseñe un algoritmo iterativo eciente que efectúe la concatenación de dos árboles
// binarios (+).
 #include <iostream>
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

Node* concatenate_trees(Node* rootA, Node* rootB) {
    if (!rootA) return rootB;
    if (!rootB) return rootA;

    Node* maxA = rootA;
    while (maxA->right)
        maxA = maxA->right;

    maxA->right = rootB;

    return rootA;
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

    insert(A, 2);
    insert(A, 1);
    insert(A, 3);

    insert(B, 7);
    insert(B, 6);
    insert(B, 8);

    cout << "Árbol A (inorden): ";
    print_inorder(A);
    cout << endl;

    cout << "Árbol B (inorden): ";
    print_inorder(B);
    cout << endl;

    Node* C = concatenate_trees(A, B);
    cout << "Concatenación (inorden): ";
    print_inorder(C);
    cout << endl;

    return 0;
}
