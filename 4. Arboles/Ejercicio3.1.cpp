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

vector<int> parseDewey(const string& dewey) {
    vector<int> steps;
    stringstream ss(dewey);
    string part;
    while (getline(ss, part, '.')) {    
        steps.push_back(stoi(part));
    }
    return steps;
}

void insert(Node*& root, const string& value, const string& dewey) {
    vector<int> steps = parseDewey(dewey);
    if (steps[0] != 1) throw invalid_argument("Dewey debe comenzar en 1");

    if (!root) root = new Node("?");

        if (steps.size() == 1) {
        root->value = value;
        return;
    }

    Node* current = root;
    for (size_t i = 1; i < steps.size(); i++) {
        if (steps[i] == 1) {
            if (!current->left) current->left = new Node("?");
            if (i == steps.size()-1) current->left->value = value;
            current = current->left;
        } else if (steps[i] == 2) {
            if (!current->right) current->right = new Node("?");
            if (i == steps.size()-1) current->right->value = value;
            current = current->right;
        }
    }
}

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Node* root = nullptr;
    insert(root, "E", "1.1.2");
    insert(root, "A", "1");
    insert(root, "D", "1.1.1");
    insert(root, "B", "1.1");
    insert(root, "C", "1.2");

    cout << "Preorden del árbol: ";
    printPreorder(root);
}

