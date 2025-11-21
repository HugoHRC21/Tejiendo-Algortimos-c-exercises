//26. Defina e implante la SIMILARIDAD entre dos árboles especificados mediante el TAD Tree_Node

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
bool are_similar(Tree_Node<T>* a, Tree_Node<T>* b) {
    if (!a && !b) return true;

    if (!a || !b) return false;

    if (a->children.size() != b->children.size()) return false;

    for (size_t i = 0; i < a->children.size(); i++) {
        if (!are_similar(a->children[i], b->children[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Tree_Node<string>* A = new Tree_Node<string>("A");
    Tree_Node<string>* B = new Tree_Node<string>("B");
    Tree_Node<string>* C = new Tree_Node<string>("C");
    Tree_Node<string>* D = new Tree_Node<string>("D");
    A->children = {B, C};
    B->children = {D};

    Tree_Node<string>* X = new Tree_Node<string>("X");
    Tree_Node<string>* Y = new Tree_Node<string>("Y");
    Tree_Node<string>* Z = new Tree_Node<string>("Z");
    Tree_Node<string>* W = new Tree_Node<string>("W");
    X->children = {Y, Z};
    Y->children = {W};

    cout << (are_similar(A, X) ? "Similares" : "No similares") << endl;

    Tree_Node<string>* P = new Tree_Node<string>("P");
    Tree_Node<string>* Q = new Tree_Node<string>("Q");
    P->children = {Q};

    cout << (are_similar(A, P) ? "Similares" : "No similares") << endl;

    return 0;
}
