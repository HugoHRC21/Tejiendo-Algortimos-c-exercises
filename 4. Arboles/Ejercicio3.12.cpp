// Diseñe un algoritmo no recursivo que destruya de árboles binarios (+)
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T v) : value(v), left(nullptr), right(nullptr) {}
};

template <typename T>
void destroy_tree(Node<T>* root) {
    if (!root) return;

    stack<Node<T>*> st;
    st.push(root);

    while (!st.empty()) {
        Node<T>* current = st.top();
        st.pop();

        if (current->left) st.push(current->left);
        if (current->right) st.push(current->right);

        delete current;
    }
}
template <typename T>
void print_inorder(Node<T>* root) {
    if (!root) return;
    print_inorder(root->left);
    cout << root->value << " ";
    print_inorder(root->right);
}

int main() {
    // Construimos un árbol de ejemplo
    Node<char>* root = new Node<char>('A');
    root->left = new Node<char>('B');
    root->right = new Node<char>('C');
    root->left->left = new Node<char>('D');
    root->left->right = new Node<char>('E');
    root->right->right = new Node<char>('F');

    cout << "Inorden antes de destruir: ";
    print_inorder(root);
    cout << endl;

    // Destruimos el árbol (no recursivo)
    destroy_tree(root);

    cout << "Árbol destruido (punteros ya liberados)." << endl;

    return 0;
}
