// 28. Diseñe un algoritmo recursivo que implante la copia de un árbol especicado mediante
//el TAD Tree_Node

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct Tree_Node {
    T value;
    vector<Tree_Node*> children;

    Tree_Node(T v) : value(v) {}
};

template <typename T>
Tree_Node<T>* copy_tree(Tree_Node<T>* root) {
    if (!root) return nullptr;


    Tree_Node<T>* new_root = new Tree_Node<T>(root->value);

    for (auto child : root->children) {
        new_root->children.push_back(copy_tree(child));
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

    Tree_Node<string>* A = new Tree_Node<string>("A");
    Tree_Node<string>* B = new Tree_Node<string>("B");
    Tree_Node<string>* C = new Tree_Node<string>("C");
    Tree_Node<string>* D = new Tree_Node<string>("D");
    A->children = {B, C};
    C->children = {D};

    cout << "Árbol original (preorden): ";
    print_preorder(A);
    cout << endl;


    Tree_Node<string>* copy = copy_tree(A);

    cout << "Árbol copiado (preorden): ";
    print_preorder(copy);
    cout << endl;

    return 0;
}
