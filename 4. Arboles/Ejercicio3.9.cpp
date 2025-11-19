#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct ListNode {
    T value;
    vector<ListNode<T>*> children;
    ListNode(T v) : value(v) {}
};


// Árbol con arreglos fijos (orden conocido)
template <typename T>
struct ArrayNode {
    T value;
    vector<ArrayNode<T>*> children; 
    ArrayNode(T v, int m) : value(v), children(m, nullptr) {}
};

template <typename T>
ArrayNode<T>* convert_with_known_order(ListNode<T>* root, int m) {
    if (!root) return nullptr;

    ArrayNode<T>* new_node = new ArrayNode<T>(root->value, m);

    for (size_t i = 0; i < root->children.size() && i < (size_t)m; ++i) {
        new_node->children[i] = convert_with_known_order(root->children[i], m);
    }

    return new_node;
}

template <typename T>
void print_known_order(ArrayNode<T>* root) {
    if (!root) return;
    cout << root->value << " ";
    for (auto child : root->children) {
        if (child) print_known_order(child);
    }
}

// Árbol con arreglos dinámicos (orden desconocido)
template <typename T>
struct DynamicArrayNode {
    T value;
    vector<DynamicArrayNode<T>*> children;
    DynamicArrayNode(T v) : value(v) {}
};

template <typename T>
DynamicArrayNode<T>* convert_with_unknown_order(ListNode<T>* root) {
    if (!root) return nullptr;

    DynamicArrayNode<T>* new_node = new DynamicArrayNode<T>(root->value);

    for (auto child : root->children) {
        new_node->children.push_back(convert_with_unknown_order(child));
    }
    return new_node;
}

template <typename T>
void print_unknown_order(DynamicArrayNode<T>* root) {
    if (!root) return;
    cout << root->value << " ";
    for (auto child : root->children) {
        print_unknown_order(child);
    }
}

int main() {
    ListNode<string>* A = new ListNode<string>("A");
    ListNode<string>* B = new ListNode<string>("B");
    ListNode<string>* C = new ListNode<string>("C");
    ListNode<string>* D = new ListNode<string>("D");
    ListNode<string>* E = new ListNode<string>("E");
    ListNode<string>* F = new ListNode<string>("F");

    A->children = {B, C, F};
    C->children = {D, E};

    cout << "Árbol original (listas enlazadas): A(B, C(D,E), F)" << endl;

    ArrayNode<string>* root_known = convert_with_known_order(A, 3);
    cout << "\nRecorrido del árbol con orden conocido (m=3): ";
    print_known_order(root_known);
    cout << endl;

    DynamicArrayNode<string>* root_unknown = convert_with_unknown_order(A);
    cout << "\nRecorrido del árbol con orden desconocido: ";
    print_unknown_order(root_unknown);
    cout << endl;

    ListNode<int>* n1 = new ListNode<int>(1);
    ListNode<int>* n2 = new ListNode<int>(2);
    ListNode<int>* n3 = new ListNode<int>(3);
    ListNode<int>* n4 = new ListNode<int>(4);

    n1->children = {n2, n3};
    n2->children = {n4};

    cout << "\nÁrbol de enteros (listas enlazadas): 1(2(4),3)" << endl;

    DynamicArrayNode<int>* root_int = convert_with_unknown_order(n1);
    cout << "Recorrido del árbol de enteros: ";
    print_unknown_order(root_int);
    cout << endl;

    return 0;
}
