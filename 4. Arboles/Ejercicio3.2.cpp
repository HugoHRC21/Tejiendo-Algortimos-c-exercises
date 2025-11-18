#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

struct Node {
    string value;
    vector<Node*> children; 
    Node(const string& v = "?") : value(v) {}
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
    if (steps.empty() || steps[0] != 1) throw invalid_argument("Dewey debe comenzar en 1");
    if (!root) root = new Node("?");

    Node* current = root;
    if (steps.size() == 1) { current->value = value; return; }

    for (size_t i = 1; i < steps.size(); i++) {
        int childIndex = steps[i] - 1; 
        bool is_last = (i == steps.size() - 1);

        if ((int)current->children.size() <= childIndex) { current->children.resize(childIndex + 1, nullptr); }
        
        if (!current->children[childIndex]) { current->children[childIndex] = new Node("?");}
        if (is_last) { current->children[childIndex]->value = value; }

        current = current->children[childIndex];
    }
}

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    for (Node* child : root->children) {
        printPreorder(child);
    }
}

void freeTree(Node* root) {
    if (!root) return;
    for (Node* child : root->children) {
        freeTree(child);
    }
    delete root;
}

int main() {
    Node* root = nullptr;


    insert(root, "A", "1");       
    insert(root, "E", "1.3.2");
    insert(root, "B", "1.1");     
    insert(root, "C", "1.2");     
    insert(root, "D", "1.3");    
    insert(root, "F", "1.3.1");   
    insert(root, "G", "1.2.1");  

    cout << "Preorden (árbol general): ";
    printPreorder(root);
    cout << endl;

    freeTree(root);
    return 0;
}
