//46. Diseñe un algoritmo que reciba como entrada el número de Deway de un nodo cualquiera
//y el árbol binario donde reside el nodo y retorne el nodo en cuestión

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
    Node(string v) : value(v), left(nullptr), right(nullptr) {}
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

Node* find_by_dewey(Node* root, const string& dewey) {
    if (!root) return nullptr;

    vector<int> steps = parse_dewey(dewey);

    if (steps.empty() || steps[0] != 1) {
        return nullptr;
    }

    Node* current = root;
    for (size_t i = 1; i < steps.size(); i++) {
        if (!current) return nullptr;
        if (steps[i] == 1) {
            current = current->left; 
        } else if (steps[i] == 2) {
            current = current->right; 
        } else {
            return nullptr; 
        }
    }
    return current;
}

int main() {
    Node* root = new Node("A");
    root->left = new Node("B");
    root->right = new Node("C");
    root->left->left = new Node("D");
    root->left->right = new Node("E");
    root->right->left = new Node("F");
    root->right->right = new Node("G");

    string query = "1.1.2";
    Node* result = find_by_dewey(root, query);

    if (result) {
        cout << "El nodo en " << query << " es: " << result->value << endl;
    } else {
        cout << "Nodo no encontrado para " << query << endl;
    }

    return 0;
}
