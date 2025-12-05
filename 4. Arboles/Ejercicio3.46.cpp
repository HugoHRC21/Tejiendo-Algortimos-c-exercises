// 99. Implante un algoritmo recursivo que efectúe la unión general de dos ABBE.

#include <iostream>
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
Node<T>* union_abbe(Node<T>* A, Node<T>* B) {
    if (A->is_external && B->is_external)
        return create_external<T>();

    if (A->is_external) return copy_tree(B);
    if (B->is_external) return copy_tree(A);

    Node<T>* new_root = new Node<T>(A->value, false);
    new_root->left = union_abbe(A->left, B->left);
    new_root->right = union_abbe(A->right, B->right);

    if (B->value != A->value)
        new_root = insert(new_root, B->value);

    return new_root;
}

template <typename T>
Node<T>* copy_tree(Node<T>* root) {
    if (!root) return nullptr;
    Node<T>* new_node = new Node<T>(root->value, root->is_external);
    if (!root->is_external) {
        new_node->left = copy_tree(root->left);
        new_node->right = copy_tree(root->right);
    }
    return new_node;
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

    Node<int>* U = union_abbe(A, B);

    cout << "Unión (Inorden): ";
    print_inorder(U);
    cout << endl;

    return 0;
}
