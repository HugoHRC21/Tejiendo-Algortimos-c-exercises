// 30.Diseñe un algoritmo no recursivo que ejecute la búsqueda por número de Deway.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Nodo del árbol n-ario
template <typename T>
struct Tree_Node {
    T value;
    vector<Tree_Node*> children;
    Tree_Node(T v) : value(v) {}
};


vector<int> parse_dewey(const string& dewey) {
    vector<int> steps;
    stringstream ss(dewey);
    string part;
    while (getline(ss, part, '.')) {
        steps.push_back(stoi(part));
    }
    return steps;
}

template <typename T>
Tree_Node<T>* search_dewey(Tree_Node<T>* root, const string& dewey) {
    if (!root) return nullptr;

    vector<int> steps = parse_dewey(dewey);

    if (steps.empty() || steps[0] != 1) {
        cout << "Número de Dewey inválido" << endl;
        return nullptr;
    }

    Tree_Node<T>* current = root;

    for (size_t i = 1; i < steps.size(); i++) {
        int child_index = steps[i] - 1; 
        if (child_index < 0 || child_index >= (int)current->children.size()) {
            return nullptr;
        }
        current = current->children[child_index];
    }

    return current;
}

int main() {
    // Construcción del árbol de ejemplo
    Tree_Node<string>* A = new Tree_Node<string>("A");
    Tree_Node<string>* B = new Tree_Node<string>("B");
    Tree_Node<string>* C = new Tree_Node<string>("C");
    Tree_Node<string>* D = new Tree_Node<string>("D");
    Tree_Node<string>* E = new Tree_Node<string>("E");
    Tree_Node<string>* F = new Tree_Node<string>("F");

    A->children = {B, C, D};
    C->children = {E, F};

    // Prueba de búsqueda
    string dewey = "1.2.1"; // Debería encontrar F
    Tree_Node<string>* result = search_dewey(A, dewey);

    if (result) {
        cout << "Nodo encontrado: " << result->value << endl;
    } else {
        cout << "Nodo no encontrado." << endl;
    }

    return 0;
}
