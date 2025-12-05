// 100. Implante un algoritmo iterativo, que no use pila, que haga la unión general de dos
// ABBE
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    bool is_external;

    Node(T v, bool ext = false) : value(v), left(nullptr), right(nullptr), is_external(ext) {}
};

template <typename T>
Node<T>* create_external() {
    return new Node<T>(T(), true);
}

template <typename T>
Node<T>* insert(Node<T>* root, T value) {
    if (!root) {
        root = new Node<T>(value, false);
        root->left = create_external<T>();
        root->right = create_external<T>();
        return root;
    }

    if (root->is_external) {
        root->value = value;
        root->is_external = false;
        root->left = create_external<T>();
        root->right = create_external<T>();
        return root;
    }

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root;
}

template <typename T>
Node<T>* union_abbe_iterative(Node<T>* A, Node<T>* B) {
    if (!A && !B) return nullptr;

    Node<T>* result = nullptr;
    queue<Node<T>*> q;

    if (A && !A->is_external) q.push(A);
    if (B && !B->is_external) q.push(B);

    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();

        if (current->is_external) continue;

        result = insert(result, current->value);

        if (current->left && !current->left->is_external)
            q.push(current->left);
        if (current->right && !current->right->is_external)
            q.push(current->right);
    }

    return result;
}

template <typename T>
void print_inorder(Node<T>* root) {
    if (!root || root->is_external) return;
    print_inorder(root->left);
    cout << root->value << " ";
    print_inorder(root->right);
}

int main() {

    Node<int>* A = nullptr;
    A = insert(A, 10);
    A = insert(A, 5);
    A = insert(A, 15);


    Node<int>* B = nullptr;
    B = insert(B, 7);
    B = insert(B, 10);
    B = insert(B, 20);

    cout << "Árbol A (Inorden): ";
    print_inorder(A);
    cout << endl;

    cout << "Árbol B (Inorden): ";
    print_inorder(B);
    cout << endl;

    Node<int>* U = union_abbe_iterative(A, B);

    cout << "Unión iterativa (Inorden): ";
    print_inorder(U);
    cout << endl;

    return 0;
}
