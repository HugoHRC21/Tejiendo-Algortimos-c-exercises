// 27.Defina e implante la EQUIVALENCIA  entre dos árboles especificados mediante
// el TAD Tree_Node .

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
bool are_equivalent(Tree_Node<T>* a, Tree_Node<T>* b) {
    if (!a && !b) return true;

    if (!a || !b) return false;

    if (a->value != b->value) return false;

    if (a->children.size() != b->children.size()) return false;

    for (size_t i = 0; i < a->children.size(); i++) {
        if (!are_equivalent(a->children[i], b->children[i])) {
            return false;
        }
    }

    return true;
}

int main() {

    Tree_Node<string>* A = new Tree_Node<string>("A");
    Tree_Node<string>* B = new Tree_Node<string>("B");
    Tree_Node<string>* C = new Tree_Node<string>("C");
    A->children = {B, C};

    Tree_Node<string>* X = new Tree_Node<string>("A");
    Tree_Node<string>* Y = new Tree_Node<string>("B");
    Tree_Node<string>* Z = new Tree_Node<string>("C");
    X->children = {Y, Z};

    Tree_Node<string>* P = new Tree_Node<string>("A");
    Tree_Node<string>* Q = new Tree_Node<string>("X");
    Tree_Node<string>* R = new Tree_Node<string>("C");
    P->children = {Q, R};

    cout << (are_equivalent(A, X) ? "Equivalentes" : "No equivalentes") << endl;
    cout << (are_equivalent(A, P) ? "Equivalentes" : "No equivalentes") << endl;

    return 0;
}
