//Diseñe un algoritmo no recursivo que copie de árboles binarios (+)

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T v) : value(v), left(nullptr), right(nullptr) {}
};

template <typename T>
Node<T>* copy_tree(Node<T>* root) {

    if (!root) return nullptr;

    Node<T>* new_root = new Node<T>(root->value);

    queue<pair<Node<T>*, Node<T>*>> q;
    q.push({root, new_root});

    while (!q.empty()) {
        auto [orig, copy] = q.front();
        q.pop();


        if (orig->left) {
            copy->left = new Node<T>(orig->left->value);
            q.push({orig->left, copy->left});
        }

        if (orig->right) {
            copy->right = new Node<T>(orig->right->value);
            q.push({orig->right, copy->right});
        }
    }

    return new_root;
}


template <typename T>
void print_inorder(Node<T>* root) {
    if (!root) return;
    print_inorder(root->left);
    cout << root->value << " ";
    print_inorder(root->right);
}

int main() {

    Node<char>* root = new Node<char>('A');
    root->left = new Node<char>('B');
    root->right = new Node<char>('C');
    root->left->left = new Node<char>('D');
    root->left->right = new Node<char>('E');
    root->right->right = new Node<char>('F');

    cout << "Inorden del original: ";
    print_inorder(root);
    cout << endl;


    Node<char>* copy_root = copy_tree(root);

    cout << "Inorden de la copia: ";
    print_inorder(copy_root);
    cout << endl;

    return 0;
}
