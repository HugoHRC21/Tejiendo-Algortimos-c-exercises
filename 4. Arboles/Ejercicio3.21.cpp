// 29. Diseñe un algoritmo no recursivo que implante la copia de un árbol especificado mediante el TAD Tree_Node .

#include <iostream>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

template <typename T>
struct Tree_Node {
    T value;
    vector<Tree_Node*> children;

    Tree_Node(T v) : value(v) {}
};

template <typename T>
Tree_Node<T>* copy_tree_iterative(Tree_Node<T>* root) {
    if (!root) return nullptr;

    Tree_Node<T>* new_root = new Tree_Node<T>(root->value);

    queue<pair<Tree_Node<T>*, Tree_Node<T>*>> q;
    q.push({root, new_root});

    while (!q.empty()) {
        auto [orig, copy] = q.front();
        q.pop();

        for (auto child : orig->children) {
            Tree_Node<T>* new_child = new Tree_Node<T>(child->value);
            copy->children.push_back(new_child);

            q.push({child, new_child});
        }
    }

    return new_root;
}

template <typename T>
void print_preorder(Tree_Node<T>* root) {
    if (!root) return;
    cout << root->value << " ";
    for (auto child : root->children) {
        print_preorder(child);
    }
}

int main() {
    // Construimos un árbol de ejemplo
    Tree_Node<string>* A = new Tree_Node<string>("A");
    Tree_Node<string>* B = new Tree_Node<string>("B");
    Tree_Node<string>* C = new Tree_Node<string>("C");
    Tree_Node<string>* D = new Tree_Node<string>("D");
    A->children = {B, C};
    C->children = {D};

    cout << "Árbol original (preorden): ";
    print_preorder(A);
    cout << endl;

    Tree_Node<string>* copy = copy_tree_iterative(A);

    cout << "Árbol copiado (preorden): ";
    print_preorder(copy);
    cout << endl;

    return 0;
}
