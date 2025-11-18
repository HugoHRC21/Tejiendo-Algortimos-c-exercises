#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;  
    Node(string v) : value(v) {}
};

struct DeweyEntry {
    string value;
    string code;
};

vector<int> parseDewey(const string& dewey) {
    vector<int> steps;
    stringstream ss(dewey);
    string part;
    while (getline(ss, part, '.')) {
        steps.push_back(stoi(part));
    }
    return steps;
}

void insert(Node*& root, const DeweyEntry& entry) {
    vector<int> steps = parseDewey(entry.code);

    if (!root) root = new Node("ROOT"); 

    Node* current = root;
    for (size_t i = 1; i < steps.size(); i++) {
        int pos = steps[i] - 1; 
        if (pos >= current->children.size()) {
            current->children.resize(pos + 1, nullptr);
        }
        if (!current->children[pos]) {
            current->children[pos] = new Node("?");
        }
        current = current->children[pos];
    }
    current->value = entry.value; // asignar valor al nodo destino
}

// 🔸 Mostrar el árbol en preorden
void printTree(Node* root, string code = "1") {
    if (!root) return;
    if (root->value != "ROOT") // no mostrar la raíz virtual
        cout << root->value << " → " << code << endl;

    for (size_t i = 0; i < root->children.size(); i++) {
        if (root->children[i])
            printTree(root->children[i], code + "." + to_string(i + 1));
    }
}

int main() {
    // 🔹 Entrada: secuencia desordenada
    vector<DeweyEntry> input = {
        {"C", "1.2"},
        {"A", "1"},
        {"B", "1.1"},
        {"D", "1.3"},
        {"E", "1.2.1"},
        {"F", "1.2.2"}
    };

    Node* root = nullptr;

    // 🔹 Insertar cada par Dewey en el árbol
    for (auto& entry : input) {
        insert(root, entry);
    }

    // 🔹 Mostrar árbol resultante
    cout << "Árbol en listas enlazadas (recorrido preorden con Dewey):" << endl;
    printTree(root);

    return 0;
}
